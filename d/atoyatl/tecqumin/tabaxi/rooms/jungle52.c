#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                    "southeast" : TABAXROOM + "jungle38",
                    "northwest" : TABAXROOM + "jungle43"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
