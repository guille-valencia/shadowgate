#include "../kildare.h"

inherit TUN;

void create(){
   ::create();
   set_long(::query_long()+"\nThe tunnel is lower for a "+
      "stretch here, and the faint stench of mold suggests "+
      "that it sometimes floods.\n");
   set_exits(([
      "west" : ROOMS"tunnel9",
      "northeast" : ROOMS"tunnel11"
   ]));
}
