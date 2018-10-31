Listing of IY7/TIMELOCK.B written on 22 Mar 1988 at 16:04:43

timecheck()
{
auto tb[6];
datev(tb);
auto bf[12];
date(bf);
auto day;
day=datesi(bf)%7;
auto hour;
hour=tb[3];
if((day==5)||(day==6)) return(1);
if((hour<9)||(hour>16)) return(1);
printf("*n*n");
printf("AberMUD is currently closed....*n");
printf("*n*n*nOpening Times Are *n");
printf("*n*n");
printf("Weekdays    :  5 pm  -  9 am*n");
printf("Weekend     :  All day*n");
printf("*n*n*n");
printf("Hit Any Key To Continue*n");
while(getchar()!='*n');
exit(0);
}

End of IY7/TIMELOCK.B
