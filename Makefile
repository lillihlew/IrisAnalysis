# File:          Makefile
# Author:        Lilli Lewis
# Created:       20 April 2008
# Simplified:    11 May 2023
# Acknowledgement:  adapted from an example by Marge Coahran then from Henry Walker
#----------------------------------------------------------------------------
# Use the clang compiler
CC = clang

# Set compilation flags
#   -ansi       check syntax against the American National Standard for C
#   -g          include debugging information
#   -Wall       report all warnings
#   -std=gnu99  use the GNU extensions of the C99 standard
CFLAGS = -ansi -g -Wall -std=gnu99

#----------------------------------------------------------------------------
# build rules:
#
# Each rule takes the following form  (Note there MUST be a tab,
# as opposed to several spaces, preceeding each command.
#
# target_name:  dependency_list
#	command(s)

all: iris

# List program components, what they depend on, and how to compile or link each

iris:  iris.o iris-header.o
	clang -lm -o iris iris.o iris-header.o 

iris.o:  iris.c iris-header.h
	clang -c iris.c

iris-header.o:  iris-header.c iris-header.h
	clang -c iris-header.c 

#----------------------------------------------------------------------------
# cleanup rules: To invoke this command, type "make clean".
# Use this target to clean up your directory, deleting (without warning) 
#   the built program, object files, old emacs source versions, and core dumps.

clean:
	rm -f list *.o *~ core*
