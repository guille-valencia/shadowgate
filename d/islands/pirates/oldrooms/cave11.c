#include <std.h>
#include "../piratedefs.h"

inherit "/std/room";

void create(){
::create();

set_property("indoors",1);
set_property("light",0);
  set_terrain(NAT_CAVE);
  set_travel(RUBBLE);

set_short("Caverns");

set_long("%^BOLD%^A Cavern%^RESET%^ \n"+
"You have descended further into the huge underground cavern. "
"It is completely dark here. "
"The stalagmites jutting up from the floor are more massive than in the upper caves. "+
"The stalactites are also larger and more menacing. "
"This place has gotten confusing and now you see no way out. "
"The cavern continues on in all directions, "
"but there is no obvious path, the stalagmites would make traveling harsh."
"\n"
);

set_smell("default","It smells dank and wet.");
set_listen("default","You can hear water dripping.");

set_items(([
"stalagmites":"These are old and large although "+
    "the smaller ones on the path have been bashed down.",
"stalactites":"These hang menacingly from the ceiling.",
]));

set_exits(([
"northwest":CAVES+"cave12",
"northeast":CAVES+"cave7",
"southwest":CAVES+"cave15"
]));
set_invis_exits(({"northwest","northeast","southwest"}));
}

void init(){
::init();
do_random_encounters(({MON+"piercer.c"}),30,5);
}
