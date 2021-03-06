//coded by Tristan, capture and jail added by Styx
// removed save to simplify pardons since wanted list is shared *Styx*  2/10/03
// changed do_laws and do_races to void type and casting in the function also to try again to eradicate the spammy bug we've been chasing for months.  *Styx*  7/14/05

#include <std.h>
#include <daemons.h>
#include "/d/shadow/mon/guards/dir_map.h"

#define GUARD_D "/d/shadow/mon/guards/guard_d"
#define BAD_RACES ({"drow","half-drow","goblin","hobgoblin","kobold","ogre","half-ogre","orc","half-orc","gnoll","bugbear","ogre-mage"})

inherit NPC;

void do_laws(object live);

void interactions(object live);

string randomRaceMessage(object x);

void do_races(object live);

void go_jail();
int jail_it(object who);
void do_capture(object who);

int isWatch() {
    return 1;
}

void create(){
    ::create();
// turned off since attackers save in global list now *Styx*  2/10/03
//    set_save_monster(1); 
    enable_commands();
    set_detecting_invis(random(2));
    set_property("knock unconscious",1);
}

int interaction;

int isMagic(){
    return ::isMagic() + detecting_invis();
}

void heart_beat() {
    object *watch, *other_attackers;
    int i, j;
    object *lives;
    object who;

    ::heart_beat();

//    if(!interaction) {
//        interaction = 1;
//        interaction = 0;
//    }

// don't need to do this every hb, trying to zap the recursion bug *Styx* 7/5/05
    if(random(2))  return;  

    if (!objectp(TO))  { return; }
    if (!objectp(ETO)) { return; }

    lives = all_living(ETO);
    for (i =0;i<sizeof(lives);i++) {
        if (!objectp(lives[i])) 
            continue;
	if(lives[i]->isWatch())  // don't ck interactions on other watch *Styx* 6/19/05
 	    continue;
        interactions(lives[i]);
    }
    if (objectp(TO) && objectp(ETO)) {
        watch = all_present("shadow law",ETO);
        for (i = 0;i<sizeof(watch);i++) {
            other_attackers = watch[i]->query_attackers();
            for ( j = 0;j<sizeof(other_attackers);j++) {
                if (!objectp(other_attackers[j])) 
                    continue;
                if (!other_attackers[j]->query_bound() && !other_attackers[j]->query_unconscious()) {
                    add_attacker(other_attackers[j]);
                }
            }
        }
//added by Styx to take prisoners and drag to jail when not in combat 
        if(!sizeof(other_attackers)) {
           // if they are dragging someone, move toward jail
           if( present("draggee",TO) ) {  
              go_jail();
              return;
           }
	   // ignore watch members - bind/drag troublemakers
           for(i=0; i<sizeof(lives); i++) {
              who = lives[i];
	      if ( !objectp(who) ) 	continue;  // added by *Styx* 6/15/03
              if( who->isWatch() )      continue;
              if(who->query_unconscious() || who->query_bound() ) {
                 do_capture(who);
                 return;
              }
           }
        }
    }
}

void do_capture(object who) {
   int need;
   if(!objectp(who))
	return;
   if(member_array((string)who->query_race(),BAD_RACES) != -1)
      return;     // do_races will handle killing them so we want to skip this
   if(GUARD_D->isWanted(who)) {
    // first priority is bind before they wake up
      if(!who->query_bound()) {
         command("say %^BOLD%^You are under arrest you criminal!");
         tell_room(ETO,"%^BOLD%^"+TPQCN+" takes some rope and binds "
            +who->query_cap_name()+"'s hands and feet.",({TP,who}));
         command("gag "+who->query_name());
         who->set_bound(500);
      }
    // heal them so bats & rats won't kill in one hit?
      if(who->query_unconscious()) {
         tell_room(ETO,"\nThe watch binds "+who->query_cap_name()+"'s "
            "wounds.");
         need = who->query_hp();
         who->add_hp(-need + random(20)+10);
	 tell_object(who,"You wake up and find the guard quickly binding your wounds.");
         return;
      }
      if(who->query_bound() && !who->query_property("draggee")) {
         command("say %^BOLD%^Off to jail you go for your crimes!");
         command("drag "+who->query_name());
         return;
      }
   }
   return;
}


// added by Styx using Tristan's mapping to get them to the jail
void go_jail() {
   object who;
   string here;
//   who = present("draggee",TO);  // that returns the temp object, not the player
   if(!objectp(TO))
	return;
   who = TO->query_draggee();
   if(!objectp(who) || !objectp(ETO))  
	return;
   here = base_name(ETO);
   if(here == "/d/shadow/room/city/gallows")    command("open door");
//   check for doors anywhere?  
//   check for sizeof(exits) valid & valid directions?
     if(here == "/d/shadow/room/city/jail_main") {
          if(present(who))
             jail_it(who);
          return;
     }
     if(member_array(here, keys(TOJAIL)) != -1) {
	  command(TOJAIL[here]);
	  return;
     }
     return;
}

int jail_it(object jailwho) {
// adapted from /d/shadow/mon/jail_guard
   tell_room(ETO,"The guard peers through the grating in the door and "
      "pulls a lever.  You hear something click inside the cell before "
      "he unlocks the door and quickly shoves "+jailwho->query_cap_name()+
      " inside.",jailwho);
   tell_object(jailwho,"The guard peers through the grating in the door "
       "and pulls a lever.  You hear something click inside the cell "
       "before he unlocks the door and quickly shoves you into the cell.");
 
   command("drop "+jailwho->query_name());
   tell_room(ETO,"The cell door creaks as it swings on the hinges but "
       "shuts with an ominous, solid thud.\n");
   jailwho->move("/d/shadow/room/city/jail");
   jailwho->set("jailed_age",(int)jailwho->query_age());
   force_me("close cell door");
   "/d/shadow/room/city/jail_main"->set_locked("cell door", 1, "lock");
   jailwho->force_me("look");
   "/cmds/avatar/_note.c"->cmd_note("ckpt "+jailwho->query_name()+
      " was put into %^RED%^Shadow jail %^BOLD%^by the watch.");
   SAVE_D->set_value("Shadow_prisoners", jailwho->query_name());
   return 1;
}
  

void interactions(object live) {
// moving these common checks from running separately in do_laws & do_races *Styx* 6/19/05
    if (!objectp(live))	
	return;
    if(live->query_true_invis() ) 
	return;
    if(live->query_invis() && !detecting_invis()) 
	return;
//  end of additions here, moved do_races before uncon. check so it can work
 
    do_races(live);
    if(!objectp(live))  // need a check here too *Styx*  7/31/05
	return;
    if (live->query_unconscious())
        return;
    do_laws(live);
}

string getSaveFileName() {
    string fn;
    fn = npc::getSaveFileName();
    fn = fn + "_"+query_name();
    return fn;
}

//both do_laws and do_races were missing the int at the beginning
//and occasionally bugging, so we added them and added a 1 to the 
//returns since it is defined as an int function at the top of the 
//file.  ~Circe~ 7/14/05
//also changing to void funcs after further discussion *Styx*

void do_laws(object live){
/*  moved to do_interactions *Styx* 6/15/05
    if(live->query_invis() && !detecting_invis()) return;  
    if (member_array(live,query_attackers()) != -1) {
        return;
    }
    if(live->query_unconscious()) {
        return 1;    // let do_unconscious handle it  (doesn't seem to be one... *Styx*)
    }
*/
    if(member_array((string)live->query_race(),BAD_RACES) != -1) {
        return;   // let do_races handle it or things get too confused
    }
    if (GUARD_D->isWanted(live) && !live->query_bound() ) {
        force_me("yell %^BOLD%^%^CYAN%^Stop in the name of the law!");
        kill_ob(live,0);
    }
}

void do_races(object live){
/*  moved to do_interactions
    if(live->query_invis() && !detecting_invis()) return;
    if (!objectp(live) || wizardp(live) || live->query_true_invis() ) return;
*/
    if(member_array((string)live->query_race(),BAD_RACES) != -1) {
           // added by Styx to make them kill bad races once ko'd
        if(live->query_unconscious()) {
            command("say %^BOLD%^For the crime of invading the city, you die now!");
            command("hit "+live->query_name());
            return;
        }
        if (member_array(live, query_attackers()) == -1 && !live->query_bound()) {
            command("yell "+randomRaceMessage(live));
            command("rush "+live->query_name());
            kill_ob(live,0);
        }
    }
}

void check_caught(object tp, object targ, int roll){
    force_me("say I see you "+TPQCN);
     force_me("yell STOP THIEF!");
     force_me("point "+TPQN);
     force_me("rush "+TPQN);
     kill_ob(TP,1);
}

void hairColor(){
  switch (random(6)) {
    case 0:        set("hair","blonde");        break;
    case 1:        set("hair","red");           break;
    case 2:        set("hair","auburn");        break;
    case 3:        set("hair","black");         break;
    case 4:        set("hair","gray");          break;
    case 5:        set("hair","brown");         break;
  }
}

void eyeColor(){
  switch (random(5)) {
    case 0:        set("eye","blue");         break;
    case 1:        set("eye","gray");         break;
    case 2:        set("eye","green");        break;
    case 3:        set("eye","brown");        break;
    case 4:        set("eye","azure");        break;
  }
}

void doHeight(){
    int feet, halves;
    int height = 63+random(20);
    feet = height/12;
    halves = "";
    if (height%12) {
        halves = (height%12<4)?"":((height%12<9)?" and a half":"");
        if (height%12>8) {
            height++;
        }
    }
    set("height",""+feet+halves);
}

void doWeight(){
    set("weight",((140+random(140))/10)*10);
}

void doGender(){
    set_gender(random(2)?"male":"female");
}

void setupName(string type){
    string name;
    name = GUARD_D->do_name(type);
    set_name(name);
    set_short(capitalize(name)+", "+article(query("hair"))+" "+query("hair")+" haired, "+query("eye")+" eyed "+query_gender()+" human");
    add_id(name);
    add_id(capitalize(name));
    add_id(lower_case(name));
}

void die(object ob){
    remove_save();
    ::die(ob);
}

int kill_ob(object ob, int i){
    int hold;
    hold = ::kill_ob(ob,i);
    if (hold) {
        if (!GUARD_D->isWanted(ob)) {
            GUARD_D->add_wanted(ob);
        }
// added check for isWanted so it doesn't spam so much for GH's, etc.  *Styx* 10/5/02
        if(GUARD_D->isWanted(ob)) {
	   GUARD_D->blow_horn(TO);
           GUARD_D->call_watch(TO, ob);
        }
    }
    return hold;
}

string randomRaceMessage(object x){
    string msg;    
    string race = (string)x->query_race();
    switch (race) {
    case "drow":
        msg = "Arg, its a drow, sound the horn, stop it before it starts killing children.";
        break;
    case "half-drow":
        msg = "Stop the bastard half-drow, any drow blood is bad.";
        break;
    case "goblin":
        msg = "Stop that miserable little goblin, and look around for more.";
        break;
    case "hobgoblin":
        msg = "Careful folks, it's a hobgoblin, I'll take care of it.";
        break;
    case "kobold":
        msg = "Dog faced rat, stop you kobold.";
        break;
    case "ogre":
        msg = "Gods help us, its an ogre, how did it get past the gate?";
        break;
    case "gnoll":
        msg = "It's a gnoll fellas, take 'em";
        break;
    case "half-ogre":
        msg = "Half-ogres are just smaller ogres, can't allow them in here.";
        break;
    case "half-orc":
        msg = "It's not human fellas, get that half-orc.";
        break;
    case "bugbear":
        msg = "Take em low, boys. It's gonna be mean, don't let that bugbear take you alive.";
        break;
    case "orc":
        msg = "Don't let the orcs escape!  You know it's spying for an invasion.";
        break;
    default:
        msg = "Stop you heinous "+race+".";
    }
    return msg;
}

