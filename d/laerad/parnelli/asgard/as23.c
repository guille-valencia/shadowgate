//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
    set_name("Peasant home");
    set_short("Peasant home");
    set_long(
	"%^BOLD%^A cozy peasant home%^RESET%^
You have walked into a small cozy house.  Most of the furniture is worn and "+
	"beat up.  A small stove rests on the north wall.  An old wooden table "+
	"sits near the stove surrounded by chairs.  Some straw mats are laid "+
	"out around the room, probably make-shift beds."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","You smell some chicken soup brewing on the stove.");
    set_listen("default","The house is fairly quiet.");
*/
   set_long(::query_long()+"\nLittle is left of what was once a family's home.  "
      "All that remains here are their smashed belongings and the tattered "
      "remains of their lives.\n");
    set_exits( ([
	"west":"/d/laerad/parnelli/asgard/as17"
    ]) );
}
/*
void reset(){
    ::reset();
    if(!present("peasant")){
	new("/d/laerad/mon/peasant")->move(this_object());
    }
}
*/