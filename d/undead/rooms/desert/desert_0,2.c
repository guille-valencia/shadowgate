#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :DES+"desert_0,3",
        "south"     :DES+"desert_1,2",
        "west"      :DES+"desert_0,1"
             ]));
}