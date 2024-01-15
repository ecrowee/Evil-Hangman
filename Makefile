CC = gcc
CFLAGS = -Wall --std=c99 -g
OBJECTS = main.o my_string.o generic_vector.o avl_tree.o


all: string_driver unit_test


string_driver: $(OBJECTS)
        $(CC) $(CFLAGS) $(OBJECTS) -o string_driver

unit_test: my_string.o unit_test.o test_defs.o
        $(CC) $(CFLAGS) unit_test.o test_defs.o my_string.o -o unit_test

unit_test.o: unit_test.c my_string.h status.h unit_test.h
        $(CC) $(CFLAGS) -c unit_test.c -o unit_test.o

test_defs.o: test_defs.c my_string.h status.h unit_test.h
        $(CC) $(CFLAGS) -c test_defs.c -o test_defs.o

main.o: main.c status.h my_string.h
        $(CC) $(CFLAGS) -c gamemain.c -o main.o

my_string.o: my_string.c my_string.h status.h
        $(CC) $(CFLAGS) -c my_string.c -o my_string.o

generic_vector.o: generic_vector.c
        $(CC) $(CFLAGS) -c generic_vector.c -o generic_vector.o

avl_tree.o: avl_tree.c
        $(CC) $(CFLAGS) -c avl_tree.c -o avl_tree.o

clean:
        rm string_driver $(OBJECTS) unit_test.o test_defs.o unit_test
