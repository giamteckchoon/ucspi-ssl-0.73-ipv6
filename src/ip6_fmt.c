#include "fmt.h"
#include "byte.h"
#include "ip4.h"
#include "ip6.h"

unsigned int ip6_fmt(char *s,char ip[16])
{
  unsigned long len,temp, k, pos0=0,len0=0, pos1=0, compr=0;

  for (k=0; k<16; k+=2) {
    if (ip[k]==0 && ip[k+1]==0) {
      if (!compr) {
        compr=1;
        pos1=k;
      }
      if (k==14) { k=16; goto last; }
    } else if (compr) {
    last:
      if ((temp=k-pos1) > len0) {
        len0=temp;
        pos0=pos1;
      }
      compr=0;
    }
  }

  for (len=0,k=0; k<16; k+=2) {
    if (k==12 && ip6_isv4mapped(ip)) {
      len += ip4_fmt(s,ip+12);
      break;
    }
    if (pos0==k && len0) {
      if (k==0) { ++len; if (s) *s++ = ':'; }
      ++len; if (s) *s++ = ':';
      k += len0-2;
      continue;
    }
    temp = ((unsigned long) (unsigned char) ip[k] << 8) +
            (unsigned long) (unsigned char) ip[k+1];
    temp = fmt_xlong(s,temp); len += temp; if (s) s += temp;
    if (k<14) { ++len; if (s) *s++ = ':'; }
  }

  return len;
}

static char tohex(char num) {
  if (num<10)
    return num+'0';
  else if (num<16)
    return num-10+'a';
  else
    return -1;
}

unsigned int ip6_fmt_flat(char *s,char ip[16])
{
  int i;
  for (i=0; i<16; i++) {
    *s++=tohex((unsigned char)ip[i] >> 4);
    *s++=tohex((unsigned char)ip[i] & 15);
  }
  return 32;
}
