#ifndef IP4_H
#define IP4_H

extern unsigned int ip4_scan(const char *,char *);
extern unsigned int ip4_fmt(char *,const char *);

#define IP4_FMT 20

extern const char ip4loopback[4]; /* = {127,0,0,1}; */

#endif
