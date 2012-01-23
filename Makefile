dsquared: main.o board.o cPiece.o charset.h menu.h setColors.h dSquared.h cTimer.h
	gcc -o dsq main.o board.o cPiece.o -I. -lGL -lGLU -lglut -lX11

CFLAGS = -lGL -lglut
main.o: main.cpp dSquared.h
	gcc -c main.cpp -I. $(CFLAGS)

board.o: board.cpp dSquared.h
	gcc -c board.cpp -I. $(CFLAGS)
 
cPiece.o: cPiece.cpp dSquared.h
	gcc -c cPiece.cpp -I. $(CFLAGS)

clean: 
	rm *.o dsq