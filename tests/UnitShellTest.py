#!/usr/bin/env python
# -*- coding: utf-8 -*-

import pexpect
import sys
import termios
import struct
import fcntl
from signal import signal
from random import choice

def generate_title(title):
    filler = choice(['-', '_', '*', '^', '#', '@', '!', '~', '>', '<']) * len(title)
    return "    ( %s )\n      %s\n    ( %s )" % (filler, title, filler)

class UnitShellTest(object):

    def __init__(self, title, command, args, output_expect):
        self.title = generate_title(title)
        self.expect_out = output_expect
        self.logname = "./%s.out" % title
        self.logfile = open(self.logname, "w+")
        self.child = pexpect.spawn(command, args, timeout=10)
        self.child.logfile_read = self.logfile


    def generate_tests(self, actions):
        """Take in argument a list of tuples to generate the action to perform
        The list must be formatted like this: [(action, [args])]"""
        for child_function, arguments in actions:
            try:
                method = getattr(self.child, child_function)
                try:
                    method(*arguments)
                except:
                    print "Error expect"
            except AttributeError:
                raise NotImplementedError("Class `{}` does not implement `{}`".format(self.child.__class__.__name__, child_function))
        self.logfile.close()

    def run_tests(self, actions):
        print self.title
        self.generate_tests(actions)
        if (self.child.isalive()):
            if not (self.child.terminate(force=True)):
                print "[Error]: Child cannot be terninated."
        out = open(self.logname, 'r').read()
        if (self.expect_out == out):
            return 0
        else:
            print "Expect: (\"%s\")\nRet: (\"%s\")\n" % (self.expect_out, out)
            return 1

