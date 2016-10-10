all:
	gcc list.c -o list

run: list
	./list

clean:
	rm *~
