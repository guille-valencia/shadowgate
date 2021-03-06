// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("carn_main_e");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("village");
    set_travel("rutted track");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Path to a %^YELLOW%^C%^RED%^a%^YELLOW%^r%^BLUE%^n%^CYAN%^i%^RED%^v%^YELLOW%^al%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^You stand at the eastern edge of the great %^YELLOW%^C%^RED%^a%^YELLOW%^r%^BLUE%^n%^CYAN%^i%^RED%^v%^YELLOW%^al%^WHITE%^. Crowds of visitor stampede through the grounds, hooting and h"
	"ollaring. For the most part the visitors are human, with the occasional %^GREEN%^elf%^WHITE%^, %^RESET%^%^ORANGE%^dwarf%^BOLD%^%^WHITE%^, or %^RESET%^%^RED%^beast%^BOLD%^%^WHITE%^. Heavily armed %^BLA"
	"CK%^mercenaries%^WHITE%^ keep the %^GREEN%^peace%^WHITE%^.  %^MAGENTA%^Brightly colored tents%^WHITE%^ rise up all around the grounds. To the north, a tavern has been set up and a tobacconist is to th"
	"e south.%^RESET%^"
	);

    set_smell("default","
It smells like fried food, stale beer, and garbage.");
    set_listen("default","Crowds are roaring in the distance at the Carnival.");


    set_exits(([ 
		"north" : "/d/av_rooms/myrkul/carn_gluttony",
		"south" : "/d/av_rooms/myrkul/carn_sloth",
		"west" : "/d/av_rooms/myrkul/carn_main",
		"east" : "/d/av_rooms/myrkul/carn_entry",
	]));

}