
// Market Street, Verhedin 
// Thorn@ShadowGate
// 001027
// New City, Verhedin
// som4.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/verhedin/include/city.h"

inherit ROOM;

void create() {
  room::create();
  set_light(2);
  set_short("%^BOLD%^Market Street, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^Market Street, Verhedin%^RESET%^

You can go west,east, or southwest down the street from here.
VERHEDIN
    );
  set_exits(([
    "west" : VOLD+"ms5",
    "southwest" : VOLD+"ms11",
    "east" : VOLD+"ms7"
   ]));
  set_listen("default","Default listen.");
  set_smell("default","Default smell.");
 }

void reset(){
	::reset();
}
