# File for parsing test commands

import sys
from suitenames import SUITES

def val_flag(f):
    flags = {
        "-f":True,
        "-a":True
    }
    return f in flags
