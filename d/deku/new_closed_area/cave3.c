#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
   set_terrain(NAT_CAVE);
   set_travel(DIRT_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_short("Kobold Caverns");
    set_long(
@KAYLA
You are moving deeper into the mountain's side.  All around you
the stone is naturally carved.  The cavern splits here.  In both
directions, the caverns are completely dark.
KAYLA
    );
      set_listen("default","Peculiar, the cavern is deadly quiet.");
    set_exits(([
       "south" : "/d/deku/new/cave4",
       "north" : "/d/deku/new/cave10",
       "east" : "/d/deku/new/cave2"
    ] ));
    set_items(([
        "walls" : "The cavern walls are naturally formed."
    ] ));
}


void reset() {
  ::reset();
  if(!present("hobgoblin")) {
    new("/d/deku/monster/hobgob")->move(this_object());
  }
}
