OBJDIR = obj
SRCDIR = src
BINDIR = bin

all: TicTacToeGame

TicTacToeGame: board.o game_engine.o main.o painter.o player.o point.o robot.o
	g++ $(OBJDIR)/board.o $(OBJDIR)/game_engine.o $(OBJDIR)/main.o $(OBJDIR)/painter.o \
	$(OBJDIR)/player.o $(OBJDIR)/point.o $(OBJDIR)/robot.o -o $(BINDIR)/TicTacToeGame.exe

board.o:
	g++ $(SRCDIR)/board.cpp -o $(OBJDIR)/board.o -c

game_engine.o:
	g++ $(SRCDIR)/game_engine.cpp -o $(OBJDIR)/game_engine.o -c

main.o:
	g++ $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o -c

painter.o:
	g++ $(SRCDIR)/painter.cpp -o $(OBJDIR)/painter.o -c

player.o:
	g++ $(SRCDIR)/player.cpp -o $(OBJDIR)/player.o -c

point.o:
	g++ $(SRCDIR)/point.cpp -o $(OBJDIR)/point.o -c

robot.o:
	g++ $(SRCDIR)/robot.cpp -o $(OBJDIR)/robot.o -c

clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/*.exe