import ctypes
import os

temp = os.path.abspath(__file__)
temp = os.path.realpath(temp)
temp = os.path.dirname(temp)
temp = os.path.join(temp, 'libxss.so')


xsstest = ctypes.CDLL('libxss.so')

print xsstest.xss_test_1()