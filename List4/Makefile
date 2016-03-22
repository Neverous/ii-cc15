CXXFLAGS=-Wreturn-type -pedantic -pedantic-errors -Wundef -O3
CC=gcc
FLEX=flex

3.c: 3.lex
	$(FLEX) -o 3.c 3.lex

3: 3.c
	$(CC) $(CXXFLAGS) -o 3 -lfl 3.c
