#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>
#include "socket.h"

static char ifname[IFNAMSIZ];

const char* socket_getifname(uint32 interface) {
  char *tmp=if_indextoname(interface,ifname);
  if (tmp)
    return tmp;
  else
    return "[unknown]";
}
