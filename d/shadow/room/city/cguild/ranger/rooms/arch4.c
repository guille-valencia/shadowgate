#include <std.h>

inherit ROOM;

void create() {
   object ob;
   ::create();
   set_short("Archery range");
   set_property("no teleport", 1);
   set_long("You are here.");
   set_exits( ([
               "south":"/d/shadow/room/city/cguild/ranger/rooms/arch3",
               "north" : "/d/shadow/room/city/cguild/ranger/rooms/arch5",
               ]) );
   ob = new("/std/obj/target");
   ob->set_difficulty(40);
   ob->move(TO);
   
   ob = new("/std/obj/target");
   ob->set_id(({"moving","moving target"}));
   ob->set_name("Moving archery target");
   ob->set_short("Moving archery Target");
   ob->set_ac(-5);
   ob->set_difficulty(80);
   ob->move(TO);
}
