#ifndef TIMEOUTCONN_H
#define TIMEOUTCONN_H

#include "uint16.h"
#include "uint32.h"

extern int timeoutconn(int,char *,uint16,unsigned int);
extern int timeoutconn6(int,char *,uint16,unsigned int,uint32);

#endif
