#include <std.h>

inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set("short", "A home with a thatch roof");
    set("long",
	"This is the small thatch covered house of an old, dishonored "
	"knight of Praxis.  There is almost nothing in the way of "
	"decoration or furnishing, as she is quite poor.  "
	"There is a door leading into a room south.");
    set_items(
	(["thatch" : "It is beginning to suffer from the weather "
	    "and ill-keeping.",
	  "house" : "It is very unimpressive.",
	  "furnishing" : "Nothing.",
	  "decoration" : "Absolutely nothing.",
	  "door" : (: this_object(), "look_at_door" :) ]) );
    set_exits( 
	      (["south" : "/d/standard/locked",
		"north"	: "/d/standard/sun1"]) );
    set_door("door", "/d/standard/locked", "south", "honor key");
    present("knight")->force_me("close door");
    present("knight")->force_me("lock door with key");
}

void reset() {
    object mon, key;

    ::reset();
    if(!present("knight")) {
	mon = new("d/standard/obj/mon/knight");
 	mon->move(this_object());
	new("d/standard/obj/armour/helm")->move(mon);
	mon->force_me("wear helm");
        key = new(OBJECT);
	key->set_name("key");
  	key->set_id( ({ "key", "honor key" }) );
	key->set("short", "a wooden key");
	key->set("long", "It is really unimpressive.");
	key->set_value(15);
	key->set_weight(40);
	key->move(mon);
    }
    if(query_reset_number() != 1) {
        present("knight")->force_me("close door");
        present("knight")->force_me("lock door with key");
    }
}

void look_at_door() {
    if(query_open("door")) write("It is open.");
    else write("It is closed.");
}

