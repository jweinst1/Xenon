from ctypes import *
import os

# Defines functions to run unit tests

def xo_unit_tests():
    xounit = cdll.LoadLibrary(os.path.abspath("binso/libunitxo.so.1"))
    xounit.xo_test_1_settype()
    xounit.xo_test_2_sametype()
    
    
    
def run_all():
    xo_unit_tests()