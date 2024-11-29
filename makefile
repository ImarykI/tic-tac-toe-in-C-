OBJDIR = obj
SRCDIR = src
BINDIR = bin
LIBDIR = lib


OBJECTS = $(OBJDIR)/board.o $(OBJDIR)/game_engine.o $(OBJDIR)/main.o $(OBJDIR)/painter.o \
          $(OBJDIR)/player.o $(OBJDIR)/point.o $(OBJDIR)/robot.o

LIBS = board game_engine main painter player point robot

all: libs TicTacToeGame

TicTacToeGame: $(OBJECTS)
	g++ $(OBJECTS) -L$(LIBDIR) $(addprefix -l,$(LIBS)) -lsqlite3 -o $(BINDIR)/TicTacToeGame.exe


libs: $(LIBDIR)/board.lib $(LIBDIR)/game_engine.lib $(LIBDIR)/main.lib \
      $(LIBDIR)/painter.lib $(LIBDIR)/player.lib $(LIBDIR)/point.lib $(LIBDIR)/robot.lib


$(LIBDIR)/board.lib: $(OBJDIR)/board.o
	ar rcs $(LIBDIR)/board.lib $(OBJDIR)/board.o

$(LIBDIR)/game_engine.lib: $(OBJDIR)/game_engine.o
	ar rcs $(LIBDIR)/game_engine.lib $(OBJDIR)/game_engine.o

$(LIBDIR)/main.lib: $(OBJDIR)/main.o
	ar rcs $(LIBDIR)/main.lib $(OBJDIR)/main.o

$(LIBDIR)/painter.lib: $(OBJDIR)/painter.o
	ar rcs $(LIBDIR)/painter.lib $(OBJDIR)/painter.o

$(LIBDIR)/player.lib: $(OBJDIR)/player.o
	ar rcs $(LIBDIR)/player.lib $(OBJDIR)/player.o

$(LIBDIR)/point.lib: $(OBJDIR)/point.o
	ar rcs $(LIBDIR)/point.lib $(OBJDIR)/point.o

$(LIBDIR)/robot.lib: $(OBJDIR)/robot.o
	ar rcs $(LIBDIR)/robot.lib $(OBJDIR)/robot.o

$(OBJDIR)/board.o: $(SRCDIR)/board.cpp
	g++ -c $(SRCDIR)/board.cpp -o $(OBJDIR)/board.o



$(OBJDIR)/game_engine.o: $(SRCDIR)/game_engine.cpp
	g++ -c $(SRCDIR)/game_engine.cpp -o $(OBJDIR)/game_engine.o

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	g++ -c $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/painter.o: $(SRCDIR)/painter.cpp
	g++ -c $(SRCDIR)/painter.cpp -o $(OBJDIR)/painter.o

$(OBJDIR)/player.o: $(SRCDIR)/player.cpp
	g++ -c $(SRCDIR)/player.cpp -o $(OBJDIR)/player.o

$(OBJDIR)/point.o: $(SRCDIR)/point.cpp
	g++ -c $(SRCDIR)/point.cpp -o $(OBJDIR)/point.o

$(OBJDIR)/robot.o: $(SRCDIR)/robot.cpp
	g++ -c $(SRCDIR)/robot.cpp -o $(OBJDIR)/robot.o




clean:
	rm -f $(OBJDIR)/*.o $(LIBDIR)/*.lib $(BINDIR)/*.exe
