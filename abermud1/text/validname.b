{
printf("System Internal Error:  Dumping Image Please Wait\n");
system("copy abrt box/snoop/abrt_rec");
printf("Dumped\n");
exit(0);
}
1230    putpers(globme,bk);
1240    {
1250
1260 validname(name)
1270    {
if(resword(name)){bprintf("Sorry I cant call you that*n");return(0); }
1280    if(length(name)>10)
1290       {
1300      bprintf("This name is too long to be a game name... create a different game person*n"");
1310       return(0);
1320       }
1330    auto a;
1340    a=0;
1350    while(char(name,a))
1360       {
1370       if(char(name,a)==' ')
1380          {
1390         bprintf("Spaces are not allowed for a game name.. create a different game person*n");
1400          return(0);
1410          }
1420       a++;
1430       }
1440    if(fobn(name)!=-1)
1450       {
1460      bprintf("I can't call you that , It would be confused with an object*n");
1470       return(0);
1480       }
1490    return(1);
1500    }
1510 /*--  Processed by BTIDY V6.2 on 29/Nov/87. --*/

resword(name)
{
if(equal(name,"The")) return(1);
if(equal(name,"Me")) return(1);
if(equal(name,"Myself")) return(1);
if(equal(name,"It")) return(1);
if(equal(name,"Them")) return(1);
if(equal(name,"Him")) return(1);
if(equal(name,"Her")) return(1);
