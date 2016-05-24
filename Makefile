all: freeimageit
	sudo chown root freeimageit
	sudo chmod u+s freeimageit

freeimageit: freeimageit.o
	gcc freeimageit.o -o freeimageit

freeimageit.o: freeimageit.c
	gcc freeimageit.c -c

clean:
	rm *.o
	sudo rm freeimageit
