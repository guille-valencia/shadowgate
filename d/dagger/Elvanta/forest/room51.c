#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the trees in the Deep Shadow Forest");
set ("day long", "%^ORANGE%^The <walkway> goes ever onward through the great <redwoods>.  The sounds and smells of the forge are diminishing as you travel.  What awaits you on this strange and compelling journey?%^RESET%^");
set ("night long", "%^CYAN%^The <walkway> goes ever onward through the  great <redwoods>  What awaits you on this strange and compelling journey, as you continue to follow the path laid before you, under the lights of glowing <globes>?%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe smell of smoke and metal is diminishing and the fresh scent of forest returning.");
set_listen ("default", "The noise of banging, tinking, and sizzling is beginning to fade, and the sounds of animals returning.");
set_exits (([
"west" : "/d/dagger/Elvanta/forest/room52",
"east" : "/d/dagger/Elvanta/forest/room50"
]));
set_items
(([
"globes" : "These globes are welcome in this forest and light your way.  They are approximately two feet in diameter and give off a warm blue light.  They are hung from intricately braided silver chains.",
"owls" : "Very large owls live here in this forest.  They stand about four feet tall, and have large talons and a wicked beak.  They hoot from thier perches, and it would be wise to give them a wide berth.",
"forest" : "This forest feels comfortable, you are not afraid as you walk through the circle of trees.  However, it might not be a bad idea to still be on your guard.",
"squirrels" : "These little creatures are of all colours, brown, black and grey.  Their chittering reminds you of small children laughing.",
"birds" : "Birds of many different hues live in this forest, protected it seems, by the keepers.",
"animals" : "As you walk through this city you notice how many small animals make their homes here as well, mice, crickets, rabbits, and other four legged and six legged creatures.  They seem not to be alarmed by your passing.",
"light" : "You see small round beams of light throughout the trees, it gives a warm and gentle feeling to the forest.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so.",
"trees" : "The trees in this forest appear to be larger than you first thought.  You could build a home within any one of them and have room left over.  Now you understand why you couldn't find the city of Elvanta.",
"walkway" : "Once again you marvel at the complexity of the walkway.  Someone or something has coaxed the trees themselves to create an interlocking walkway through the upper levels of the trees.",
"redwoods" : "These redwoods are becoming larger if that is possible, where you started at 300 feet, these are at least 400 feet now."
]));
}
