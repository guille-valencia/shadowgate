#include "../../ud_ruins.h"
inherit STORAGE"_ruins_base";

void create() {
    ::create();
    set_exits(([
        "east" : ROOMS"ruins/ruins_12",
        "west" : ROOMS"ruins/ruins_14",
        ]));
}
