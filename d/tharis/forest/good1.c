//good1.c

#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_name("Forest Path");
    set_short("A small path through the forest");
    set_property("indoors",0);
    set_property("light",1);
    set_terrain(HEAVY_FOREST);
    set_travel(FOOT_PATH);
    set_long(
@OLI
    %^BOLD%^%^GREEN%^A small twisting path through the forest%^RESET%^
Tall trees loom over you almost basking in their grandure. Around
you, you sense a horrible feeling of pain. Nature's work is here but
that work is being hurt. Small plants grow around the floor of the
forest, fighting for sunshine as it creeps sparcely through the thick
canopy. You can feel a suspiscious benevolence around you.
OLI
    );
    set_items((["floor":"The ground is cluttered  with twigs and leaves.",
                "trees":"These grand creatures range from oak and hickory to Pine and spruce."
                ]));
    set_exits(([
                "out":"/d/tharis/forest/forest97",
                "east":"/d/tharis/forest/good2"
                ]));
    set_smell("default","The lush fragrances of the forest quell your worries.");
    set_listen("default","The silence of the forest is unnatural, as if all the insects and birds are hiding.");
    set_pre_exit_functions(({"east"}),({"stop_em"}));
    set_property("no teleport",1);
}

int stop_em(){
     if(present("e_archer") && !TP->query_invis()){
        if(ALIGN->is_good(TP))
            return 1;
        write("%^BOLD%^The elf stops you from going any farther!");
        tell_room(TO,"%^BOLD%^You see an elf stop "+TPQCN+"from going any further east.",TP);
        return 0;
     }
     return 1;
}

void reset(){
    ::reset();
    if(!present("elf"))
        new("/d/tharis/monsters/e_archer")->move(TO);
    if(!present("tree"))
        new("/d/tharis/monsters/treant")->move(TO);
}

