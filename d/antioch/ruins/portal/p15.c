#include <std.h>
#include "../ruins.h"
inherit PLANE;

void create()
{
   ::create();
   set_short("%^BOLD%^%^RED%^Plane of Fire%^RESET%^");
   set_long(
   "%^RED%^The sky is a dull red color and smoke hangs in the air,"+
   " preventing you from seeing too far in any direction. The air is hot"+
   " and humid, the ground beneath your feet is scorched and baked."+
   " You're standing on a ridge that stretches out to the northwest."+
   " The ridge is only perhaps six feet wide and on either side is a"+
   " long fall into molten lava. To the east and southeast is a small"+
   " plateau."
   );
   add_item("plateau","There is a plateau to the east and southeast.");
   set_exits(([
   "northwest" : PORTAL+"p16",
   "southeast" : PORTAL+"entrance",
   "east" : PORTAL+"p1",
   ]));
}
