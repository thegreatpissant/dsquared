CFLAGS = -lGL -lglut -lGLU

dsquared: main.o board.o cPiece.o charset.h menu.h setColors.h dSquared.h cTimer.h
	$(CXX) -o dsq main.o board.o cPiece.o -I. $(CFLAGS)

main.o: main.cpp dSquared.h
	$(CXX) -c main.cpp -I. $(CFLAGS)

board.o: board.cpp dSquared.h
	$(CXX) -c board.cpp -I. $(CFLAGS)
 
cPiece.o: cPiece.cpp dSquared.h
	$(CXX) -c cPiece.cpp -I. $(CFLAGS)

clean: 
	rm *.o dsq
