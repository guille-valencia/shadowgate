#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"150",
        //"east" : ELROOMSD+"179",
        //"south" : ELROOMSD+"162",
        "west" : ELROOMSD+"178",
        
    ]));
}
