#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_id(({
  "partisan","pole arm","polearm","spear",
      }));
    set_name(
  "partisan"
    );
    set_short(
  "Partisan"
    );
    set_long(
  "  This form of pole arm is consists of a long ox-tongue spear blade with two small axe blades added to the spearheads base."
    );
    set_size(3);
    set_weight(10);
    set_value(10);
    set_type(
  "slash"
    );
    set_prof_type(
      "polearm"
    );
    set_weapon_speed(8);
    set_wc(
  1,6
    );
    set_large_wc(
  1,6
    );
    set("read","Another fine newbie product from Amidon.\n");
}
