#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^The trail stretches out unevenly, winding through huge boulders which stud the rugged terrain.  Long grasses sway with the breeze, hiding the path on occasion.");
set_smell("default", "%^BOLD%^BLUE%^\nRain soaked grasses sends clouds of pollen into the air making you sneeze.");
set_listen("default", "%^CYAN%^Crickets, mice and small birds make their presence heard.");
set_exits (([
"east" : PROOM+"room8.c",
"west" : PROOM+"room6.c"
]));
set_items(([
"path" : "It is a long and winding roadway to something, to somewhere.",
"boulders" : "Orange/grey rocks, the size of man, litter the grasslands, from a rockfall ages past."
]));
if(!present("rattlesnake"))
new("/d/dagger/Elvanta/forest/mon/rattlesnake")->move(TO);
if(!present("highelffemale"))
new("/d/ptalkin/mon/highelf_female")->move(TO);
}
