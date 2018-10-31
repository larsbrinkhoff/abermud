#!/bin/sh
echo 'Compiling world maker'
cc makeworld.c blib.c -o makeworld.util
makeworld.util
echo 'Game universe intialised'
echo 'Compiling reset data compiler'
cc ogen.c blib.o -o ogenerate
ogenerate
cp ob.out reset_data
echo 'Reset data generated'
echo 'Compiling uaf generator'
cc makeuaf.c -o makeuaf
makeuaf >uaf.rand
echo 'Ok'
echo 'Now set up a password for arthur the archwizard'
