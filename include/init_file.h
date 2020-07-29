#ifndef __NN_INIT_FILE_H
#define __NN_INIT_FILE_H

#include "config.h"

#define READ(_1, _2) fread((char*)&_1, sizeof(_1), 1, _2)

int rev_int(int);
void read_mnist(char *);

#endif	/*__NN_INIT_FILE_H*/
