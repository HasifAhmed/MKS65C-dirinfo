run:dirinfo.o
	gcc dirinfo.o

clean:
	rm *.o

dirinfo.o: dirinfo.c
	gcc -c dirinfo.c 
