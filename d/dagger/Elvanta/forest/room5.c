#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the Deep Shadow Forest");
set("day long", "%^ORANGE%^You follow a trail leading you into the forest disappearing into the trees.  The pathway at present is free of gnomes, dwarves, and other assorted individuals, you appear to be alone.%^RESET%^");
set("night long", "%^CYAN%^The <pathway> you travel upon is surrounded by 400 foot <redwoods>.  No light comes this far, except for the odd <moonbeam>.  You see no human life.  However, you do have the feeling eyes are following your every move.  You also seem to see flickering <lights> high in the trees, but that could be an illusion.");
set_smell ("default", "%^MAGENTA%^The fragrance of pine needles and freshly dampened earth fills your senses.");
set_listen ("default", "You hear birds, squirrels and the wind whispering through the trees.  Was that laughter you heard, as well?");
set_exits (([
"northeast" : "/d/dagger/Elvanta/forest/room6",
"southwest" : "/d/dagger/Elvanta/forest/room4"
]));
set_items
(([
"pathway" : "The pathway is smooth with a lifetime of redwood needles, making it soft and fragrant.","redwoods" : "These redwoods have been here for a thousand years.  Their immense age gives you a feeling of continuity.",
"shadows" : "Shadows fill the forest as you travel.  The shadows are the least of your worries.",
"moonbeam" : "Thank whatever Gods there may be that you have some light at least.",
"lights" : "Is it your imagination or just wishful thinking perhaps, but you see high in the trees to the northwest flickering points of light."
]));
}
