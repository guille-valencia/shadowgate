
// River Road, Verhedin 
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
  set_short("%^BOLD%^River Road, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^River Road, Verhedin%^RESET%^

You can go northwest or south down the street from here.
VERHEDIN
    );
  set_exits(([
    "northwest" : VOLD+"rir2",
    "south" : VOLD+"rir4"
  ]));
  set_listen("default","Default listen.");
  set_smell("default","Default smell.");
 }

void reset(){
	::reset();
}
