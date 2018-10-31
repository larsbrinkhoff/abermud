4100 bprintf("Twit explodes in a mass of feathers, to fall to the ground as a*n");
4110 bprintf("charred ball.*n");
4120 destroy(171);
4130 destroy(24);
4140 if(state(24)==0)
4150    {
4160    ocreate(25);
4170    setoloc(25,curch,0);
4180    bprintf("A star bounces away from the charred mess*n");
4190    }
4220 }
4230 /*-- Processed by BTIDY V6.2 on 19/Jan/88. --*/

brkchest()
{
extrn mynum,curch;
if(!ishere(200))
{
bprintf("There isn't one here*n");
return;
}
destroy(200);
ocreate(205);
setoloc(205,curch,0);
bprintf("You smash the tea-chest , to reveal a bronze sculpture*n");
}

End of GF1/MUD1/BLOOD.B
