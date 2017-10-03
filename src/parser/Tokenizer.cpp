#include "Xenon.h"

CharSet TokenSets::whiteSpace = " \n\t\r\v\f";

CharSet TokenSets::digits = "0123456789";

CharSet TokenSets::alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

CharSet TokenSets::alphaNumeric = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

CharSet TokenSets::symbols = "_+-*/%~!@$^&<>=?";

CharSet TokenSets::eventName = "_+-*/%~!@$^&<>=?abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

CharSet TokenSets::numbers = "-0123456789.";
