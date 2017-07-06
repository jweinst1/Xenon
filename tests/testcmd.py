# File for parsing test commands

import sys
from suitenames import SUITES

def process_cmd():
    for cmd in sys.argv[1:]:
        if cmd in SUITES:
            # calls the suite if valid
            SUITES[cmd]()
        else:
            raise KeyError("Invalid test suite name {0}".format(cmd))
            
            
if __name__ == "__main__":
    process_cmd()