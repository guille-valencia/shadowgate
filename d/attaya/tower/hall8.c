
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("A lavish hallway");
        set_long("
    You are walking down a long, lavishly decorated hallway.  The walls are covered with patterned tiles and black curtains.  Polished silver sculptures line the hallway on either side.  
    A great energy flows in the air...  You can feel it around you.  It drapes over you and makes your lungs strain slightly more than normal for each breath as if the very air seeks to suffocate you.
    The ceiling above you is carpeted like the floor.
    %^RED%^A bloodstain catches your eye.
");
       set_exits(([
       "west" : "/d/attaya/tower/hall9",
       "south" : "/d/attaya/tower/hall7",
]));
       set_items(([
    "ceiling" : "The ceiling is carpeted just as the floor is.  It is almost like looking into a mirror!",
    "floor" : "A blue and gold carpet covers the marble floor.",
    "carpet" : "The carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.  It is stained with blood.",
    "sculptures" : "The polished silver sculptures are very tall and loom out over the hallway making partial arches above you.  They look like representations of a woman lunging forward, but the image is stretched out and very thin.",
    "walls" : "The walls are comprised of decorated tiles.",
     "bloodstain" : "The carpet beneath one of the sculptures is bloodstained.",
    "tiles" : "The tiles display various patterns and only every so often is one like any other.",
    "shadow" : "%^BLUE%^A shadow rests only upon you as if a figure were between you and the light.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
void reset(){
        ::reset();
    if(!present("chair"))
     new("d/attaya/obj/chair")->move(this_object());
}
