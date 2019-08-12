inherit "/cmds/spells/s/_shapechange";

string *valid_forms()
{
    return ({"spider","pixie","troll"});
}

void create()
{
    ::create();
    set_spell_name("polymorph self");
    set_spell_level(([ "mage" : 4, "ranger" : 4 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS polymorph self on spider|pixie|troll");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}
