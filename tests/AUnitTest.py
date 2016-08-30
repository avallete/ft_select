#!/usr/bin/env python
# -*- coding: utf-8 -*-

import pexpect
from random import choice

def AUnitTest(class):

    def __init__(self, ):


    def get_title(title):
        filler = choice(['-', '_', '*', '^', '#', '@', '!', '~', '>', '<']) * len(title)
        return "    ( %s )\n      %s\n    ( %s )" % (filler, title, filler)

    @abstractmethod
    def run_test(self):
