bin: derle calistir

derle:
	gcc -I ./inc/ -o ./lib/TC.o -c ./src/TC.c
	gcc -I ./inc/ -o ./lib/IMEI.o -c ./src/IMEI.c
	gcc -I ./inc/ -o ./lib/Telephone.o -c ./src/Telephone.c
	gcc -I ./inc/ -o ./lib/Random.o -c ./src/Random.c
	gcc -I ./inc/ -o ./lib/Person.o -c ./src/Person.c
	gcc -I ./inc/ -o ./bin/Test ./lib/Person.o ./lib/Random.o ./lib/Telephone.o ./lib/IMEI.o ./lib/TC.o ./src/Main.c

calistir:
	./bin/Test