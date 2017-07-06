from ctypes import *
import os

# Defines functions to run unit tests

def xo_unit_tests():
    xounit = cdll.LoadLibrary(os.path.abspath("binso/libunitxo.so.1"))
    xounit.xo_test_settype()
    
    
    
xo_unit_tests()