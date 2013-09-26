#############################################################################
# makefile for running percolation_stats simulation. This file should not   #
# require any modification.                                                 #
#                                                                           #  
# Compilation: % make                                                       #
# Execution:   % ./perc                                                     #
#############################################################################

default_target: perc

#############################################################################
# Classes                                                                   #
#############################################################################

percolation.o: src/percolation.cpp; \
g++ -g -Wall src/percolation.cpp -c -o percolation.o

union_find.o: src/union_find.cpp; \
g++ -g -Wall src/union_find.cpp -c -o union_find.o

stats.o: src/stats.cpp; \
g++ -g -Wall src/stats.cpp -c -o stats.o

random.o: src/random.cpp; \
g++ -g -Wall src/random.cpp -c -o random.o

#############################################################################
# Program                                                                   #
#############################################################################

perc: src/percolation_stats.cpp percolation.o union_find.o stats.o random.o; \
g++ -g -Wall src/percolation_stats.cpp percolation.o union_find.o \
stats.o random.o -lm -o perc
