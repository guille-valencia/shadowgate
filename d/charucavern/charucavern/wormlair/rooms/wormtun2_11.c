#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMTUN;

void create() 
{
    ::create();
    set_exits((["southwest" : WROOMS + "wormtun2_12", "northeast" : WROOMS + "wormtun2_7"]));	    
}
