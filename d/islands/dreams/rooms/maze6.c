#include "../defs.h"
inherit MAZE;

void create()
{
  ::create();
  set_exits(
    ([
    "north" : ROOMS+"maze1",
    "south" : ROOMS+"maze1",
    "east" : ROOMS+"maze1",
    "west" : ROOMS+"maze1",
    "up" : ROOMS+"maze1",
    "down" : ROOMS+"maze1"
    ]) );
  switch(random(6))
  {
  case 0:
    add_exit(ROOMS+"maze7","north");
    break;
  case 1:
    add_exit(ROOMS+"maze7","south");
    break;
  case 2:
    add_exit(ROOMS+"maze7","east");
    break;
  case 3:
    add_exit(ROOMS+"maze7","west");
    break;
  case 4:
    add_exit(ROOMS+"maze7","up");
    break;
  case 5:
    add_exit(ROOMS+"maze7","down");
    break;
  }
}