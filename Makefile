# Makefile starter for pa01.

# See Cmake/Makefile for a complete commented sample Makefile,
# illustrating separate compilation and dependencies.

# Running "make" can generate many error messages.  Do
#	make intList.o >& make.log
# to compile intList.c and cause the errors to go into the file make.log.
# When "make" finishes you can read the file with "view", "more", or "less".
#
# Many later error messages can be meaningless because they were caused
# by an earlier error.  Always try to correct errors in order.
#
# Do 
#       make graph01 >& make.log
# or 
#       make >& make.log
# to create the executable file graph01.
#
# ===================================================================

CC     = gcc
CFLAGS = -g -Wall -O0 -std=c99 -D_SVID_SOURCE

scc03:		scc03.o  intList.o dfsTrace1.o loadGraph.o edgeList.o stack.o dfsPhase2.o
	${CC}  -o  scc03  scc03.o intList.o dfsTrace1.o loadGraph.o edgeList.o stack.o dfsPhase2.o

dfsTrace1.o:	dfsTrace1.c dfsTrace1.h intList.h stack.h edgeList.h
	${CC}  -c  ${CFLAGS}  dfsTrace1.c

dfsPhase2.o:	dfsPhase2.c dfsPhase2.h intList.h stack.h 
	${CC}  -c  ${CFLAGS}  dfsPhase2.c

stack.o:	stack.c stack.h
	${CC}  -c  ${CFLAGS}  stack.c

loadGraph.o:	loadGraph.c loadGraph.h intList.h edgeList.h
	${CC}  -c  ${CFLAGS}  loadGraph.c

edgeList.o:	edgeList.c edgeList.h
	${CC}  -c  ${CFLAGS}  edgeList.c

intList.o:	intList.c  intList.h
	${CC}  -c  ${CFLAGS}  intList.c

scc03.o:	scc03.c  intList.h dfsTrace1.h loadGraph.h edgeList.h stack.h dfsPhase2.h
	${CC}  -c  ${CFLAGS}  scc03.c
submit03:	
	submit cmps101-avg.f15 pa03 scc03.c  intList.c intList.h dfsTrace1.c dfsTrace1.h loadGraph.c loadGraph.h edgeList.c edgeList.h stack.c stack.h dfsPhase2.c dfsPhase2.h

