
all: dateien dateien_child1 dateien_child2

dateien: dateien.c
	gcc -o dateien dateien.c

dateien_child1: dateien_child1.c
	gcc -lm -o dateien_child1 dateien_child1.c

dateien_chil2: dateien_child2.c
	gcc -lm -o dateien_child2 dateien_child2.c

