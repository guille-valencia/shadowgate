//      Thorn@Shadowgate
//      10/2/94
//      Darkwood forest
//     road8
/*Updated by Circe 10/4/03 to include room name, smell, listen and to use inherits to save on memory. Also, a few rooms were added to fix the way the area looks when mapped.*/

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(HEAVY_FOREST);
    set_travel(DIRT_ROAD);
    set_light(1);
    set_indoors(0);
    set_name("The Royal Southern Road");
    set_short("The Royal Southern Road");
set_long(
@THORN
The Royal Southern Road takes its path through the center of this dark 
forest.  The light of the sun is almost blotted out by the near-perfect 
shade of the trees all round you.  The thick growth of bushes beneath 
the trees looks as thought it might be hiding any number of 
unsavory creatures.
THORN
);
    set_exits(
              (["north" : "/d/darkwood/room/road7",
               "south" : "/d/darkwood/room/road21",]) );

    set_smell("default","The scent of pine is heavy in the air.");
    set_listen("default","The silence of the forest is complete except for the sound of travelers.");

    set_items(([
      ({"forest","tree","trees"}) : "The pine trees grow tall here, and are packed "+
         "so closely together that they seem to be bearing down on you.",
      ({"bush","bushes","undergrowth","growth"}) : "Sporadic crashes through the undergrowth "+
         "combine with the glint of peering eyes to verify that the forest is indeed inhabited.  "+
         "None pauses long enough for you to get a good look, however.",
      ({"creatures","unsavory creatures"}) : "A quick blur and the crash of leaves is all you can "+
         "perceive of the denizens of the forest." ]));
    /*
    if(base_name(TO) == "/d/darkwood/room/road8")
    {
        if(!present("shopkeeper"))  new("/d/token_hunt/low_vendor")->move(TO);
        if(!present("dino"))        new("/d/token_hunt/low_dino")->move(TO);
        if(!present("wagon"))       new("/d/token_hunt/wagon")->move(TO);
    }*/
}

void reset()
{
    ::reset();
    /*
    if(base_name(TO) == "/d/darkwood/room/road8")
    {
        if(!present("shopkeeper"))  new("/d/token_hunt/low_vendor")->move(TO);
        if(!present("dino"))        new("/d/token_hunt/low_dino")->move(TO);
        if(!present("wagon"))       new("/d/token_hunt/wagon")->move(TO);
    }*/
}
