#ifndef OBJECT_PRINTER_H
#define OBJECT_PRINTER_H

#ifdef __cplusplus
extern "C" {
#endif

//handles the printing of objects/streams to stdout

#define ObjectPrinter_PRINT_INT(str) printf("%d", str)

#define ObjectPrinter_PRINT_LONG(str) printf("%ld", str)

#define ObjectPrinter_PRINT_UINT(str) printf("%u", str)

#define ObjectPrinter_PRINT_CAT(str1, str2) printf("%s%s", str1, str2)

#define ObjectPrinter_PRINT_BOOL(str) str ? printf("true") : printf("false")

void ObjectPrinter_print(XenObject* xo);

#ifdef __cplusplus
}
#endif

#endif