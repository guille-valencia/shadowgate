#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "south" : MAZEDIR+"1/b/I,III",
                "east"  : MAZEDIR+"1/b/II,II"
           ]) );
}
