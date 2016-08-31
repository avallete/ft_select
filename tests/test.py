#!/usr/bin/env python
# -*- coding: utf-8 -*-

from UnitShellTest import UnitShellTest

test1 = UnitShellTest("BasicTest1", "./ft_select", ["toto", "titi", "tata"], "   \ntoto titi tata")

ret = test1.run_tests([
    ("send", " "),
    ("send", "\n"),
    ("interact", []),
])

print "Result : [%s]" % ["OK", "KO"][ret]
