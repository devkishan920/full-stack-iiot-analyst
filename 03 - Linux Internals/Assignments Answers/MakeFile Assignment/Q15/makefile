cc=gcc

main.out: main.o print.o 
	${cc} main.o print.o -o main.out

main.o: main.c 
	${cc} -c main.c -o main.o

print.o: print.c          
	${cc} -c print.c -o print.o
 
rm:
	rm *.o

