#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"34-14",
       "east" : F_ROOMS"32-14",
       "south" : F_ROOMS"33-13",
       "north" : F_ROOMS"33-15",
       "northwest" : F_ROOMS"34-15",
       "southwest" : F_ROOMS"34-13",
       "southeast" : F_ROOMS"32-13",
       "northeast" : F_ROOMS"32-15",       
    ] ));
}
