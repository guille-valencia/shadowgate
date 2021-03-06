#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit LAKETOP;

void create(){
    ::create();
    set_surface(1);
    set_short("In the lake");
    set_long(
      "You have moved into the deeper parts of the lake.  You can no longer see anything except trees, sky, and water as you treat water trying to stay afloat.  The ground has dropped out from below you, and you could probably swim down to the depths of the lake."
    );
    set_smell("default", "Don't sniff too deep, you don't want water in your nose!");
    set_listen("default", "You hear the water in your ears.");
    set_items( ([
      "trees" : "Yep those are trees.",
      "water" : "water water everywhere, and I wouldn't drink this if I were you.",
    ]) );
    set_exits( ([
      "west" : "/d/islands/dinosaur/lake/rooms/shallow16.c",
      "south" : "/d/islands/dinosaur/lake/rooms/shallow2.c",
      "north" : "/d/islands/dinosaur/lake/rooms/deep4u.c",
      "east" : "/d/islands/dinosaur/lake/rooms/deep2u.c",
      "down" : "/d/islands/dinosaur/lake/rooms/deep1d.c",
    ]) );
}
