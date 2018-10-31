#include <stdio.h>

 /*
 Zone based name generator
 */

struct zone
{
	char *z_name ;
	long z_loc ;
} ;

typedef struct zone ZONE ;

ZONE zoname[  ]={
    "LIMBO", 1, "WSTORE", 2, "HOME", 4, "START", 99, "BLIZZARD"
    } ;

 findzone( x, str )
 char *str ;
    {
    extern ZONE zoname[] ;
    long a, b ;
    long c ;
    a=0 ;
    b=0 ;
    x= -x ;
    if( x<=0 )
       {
       strcpy( str, "TCHAN" ) ;
       return( 0 ) ;
       }

    while( a<x )
       {
       strcpy( str, zoname[ b ].z_name ) ;
       c=a ;
       a=zoname[ b ].z_loc ;
       b++;
       }
    return( x-c ) ;
    }

long ex_dat[ 7 ] ;

 exits(  )
    {
    long a ;
    extern long my_lev ;
    long b ;
    char st[ 64 ];
    long v ;
    extern long ex_dat[] ;
    extern char *dirns[] ;
    a=0 ;
    b=0 ;
    bprintf( "Obvious exits are\n" ) ;
    while( a<6 )
       {
       if( ex_dat[ a ]>=0 )
          {
          a++ ;
          continue ;
          }
       if( my_lev<10 )bprintf( "%s\n", dirns[ a ] ) ;
       else
          {
          v=findzone( ex_dat[ a ], st ) ;
          bprintf( "%s : %s%d\n", dirns[ a ], st, v ) ;
          }
       b=1 ;
       a++ ;
       }
    if( b==0 )bprintf( "None....\n" ) ;
    }

char *dirns[  ]={"North", "East ", "South", "West ", "Up   ", "Down "} ;

 lodex( file )
 FILE *file;
    {
    long a ;
    extern long ex_dat[] ;
    a=0 ;
    while( a<6 )
       {
       fscanf(file," %ld ",&ex_dat[ a ]);
       a++ ;
       }
    }
 roomnum( str, offstr )
 char *str;
 char *offstr;
    {
    long a, b, c ;
    long d ;
    extern ZONE zoname[] ;
    extern char wd_there[];
    char w[64] ;
    b=0 ;c=0 ;
    a=0 ;
    while( b<99990 )
       {
       strcpy( w, zoname[ a ].z_name ) ;lowercase( w ) ;
       if( !strcmp( w, str ) ) goto fnd1 ;
       b=zoname[ a ].z_loc ;
       a++ ;
       }
    return( 0 ) ;
    fnd1: ;
    c=zoname[ a ].z_loc ;
    sscanf(offstr,"%ld",&d);
    if( !strlen( offstr ) ) d=1 ;
    sprintf(wd_there,"%s %s",str,offstr);
    if( d==0 ) return( 0 ) ;
    if( d+b>c ) return( 0 ) ;
    return( -( d+b ) ) ;
    }
 showname( loc )
    {
    extern long my_lev ;
    char a[64] ;
    extern char wd_there[];
    long b ;
    b=findzone( loc, a ) ;
    bprintf( "%s%d", a, b ) ;
    if( my_lev>9999 )bprintf( "[ %d ]", loc ) ;
    sprintf(wd_there,"%s %d",a,b);
    bprintf( "\n" ) ;
    }
 loccom(  )
    {
    extern long my_lev ;
    extern ZONE zoname[] ;
    long a ;
    a=0 ;
if( my_lev<10 )
{
bprintf( "Oh go away, thats for wizards\n" ) ;
return ;
}
    bprintf( "\nKnown Location Nodes Are\n\n" ) ;
    l1:bprintf( "%-20s", zoname[ a].z_name ) ;
    if( a%4==3 ) bprintf( "\n" ) ;
    if( zoname[ a++ ].z_loc!=99999 ) goto l1 ;
    bprintf( "\n" ) ;
    }

 

