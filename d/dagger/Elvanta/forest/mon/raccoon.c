inherit "/std/monster";

create() {
    ::create();
set_name("raccoon");
set_id(({"raccoon"}));
set_short("raccoon");
   set_level(1);
set_long("Raccoons scamper across the green searching for leftovers");
   set_gender("male");
   set("race", "quadruped");
   set_body_type("quadruped");
   set_alignment(2);
set("aggressive",10);

   set_size(1);
   set_stats("intelligence",6);
   set_stats("wisdom",4);
   set_stats("strength",3);
   set_stats("charisma",3);
   set_stats("dexterity",8);
   set_stats("constitution",7);
   set_max_mp(0);
   set_hd(1,1);
set_max_hp(query_hp());
set_max_sp(query_hp());
set_sp(query_max_sp());
   set_max_hp(query_hp());
   set_mp(query_max_mp());
set_exp(100);
   add_money("copper",random(2));
   

}

