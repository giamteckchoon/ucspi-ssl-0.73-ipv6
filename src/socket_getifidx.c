#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>
#include "socket.h"

uint32 socket_getifidx(const char* ifname) {
  return if_nametoindex(ifname);
}
