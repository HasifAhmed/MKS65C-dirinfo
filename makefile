all: dirinfo.o
	gcc dirinfo.o

run:
	./a.out
	
clean:
	rm *.o

dirinfo.o: dirinfo.c
	gcc -c dirinfo.c
