#include <std.h>

inherit "/d/koenig/fields/fields_inherit.c";

void create() {
    ::create();
    set_exits(([
       "south" : "/d/koenig/fields/room/field12",
       "west" : "/d/koenig/fields/room/field6",
       "east" : "/d/koenig/fields/room/field16"
    ] ));
}

void init() {
  ::init();
}

void reset() {
  ::reset();
}