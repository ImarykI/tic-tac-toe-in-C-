# tic-tac-toe-in-Cpp

### Scopul:
Recrearea faimosului joc Tic-Tac-Toe (aka: X și O) folosind limbajul C++.

### Regulile jocului:
- Jocul se începe pe o masă de 3 pe 3 celule/spații în care jucătorul care merge primul își alege un semn **X** sau **O** și îl plasează în una dintre celulele dorite. 
- Al doilea jucător folosește al doilea semn, care îl reprezintă pentru a marca o altă celulă liberă de pe masă.
- Jucătorii se rânduiesc în plasarea fiecare a câte un semn pe masă până când unul dintre ei câștigă sau jocul se conclude în egalitate (toate celulele sunt ocupate, dar nu există poziție câștigătoare pentru unul dintre jucători).
- Un jucător se consideră câștigător atunci când semnul pe care pe care la ales formează o linie din 3 puncte pe tabla de joc. Linia poate fi verticală, orizontală sau diagonală.

### Logica claselor și fișierele antet ale jocului.


Mai jos sunt toate fișierele antent ale proiectului.


- `point.hpp`:
Clasa care va exprima un punct din matricea jocului, prin coordonatele X și Y. Publice sunt constructorul și metodele Get.
```cpp
#pragma once

class Point{
    public:
        Point(int x, int y);
        int GetX() const;
        int GetY() const;
    private:
        int x;
        int y;
};
```

- `sign.hpp`: 
Este o clasă enumerație care conține cele trei semne/etape pe care fiecare celulă/punct poate să o conțină: 
    1. Goală (empty)
    2. X
    3. O

```cpp
#pragma once

enum class Sign{
	empty, X, O
};
```

- `board.hpp`:
Exprimă masa pe care jocul se va desfășura. 
- Metoda de inițializare a mesei **InitBoard()** va fi chemată de constructorul clasei la instanțierea obiectului.
- Masa în sine va fi un array de **Sign** bidimensional de 3 pe 3 celule/puncte în care vor fi plasate inițial valoarea *empty*, iar în decursul jocului, semnele *X* și *O* ale jucătorilor.
- **isMoveValid()** este metoda care va valida disponibilitatea amplasării semnului de către jucător în celula respectivă. Returnează *true* dacă celula este disponibilă sau *false* dacă celula deja este ocupată sau neexistentă.
- **MakeMove()** este metoda care va prelua ca parametru poziția în matrice și semnul care trebuie introdus și va schimba matriciea respectiv.
- **checkWinSituation()** este metoda care verifică dacă în starea curentă a mesei este vreo situație de câștig pentru jucătorul care a mers anterior.
- **checkDrawSituation()** este metoda care verifică dacă în starea curentă a mesei este o situație de egalitate între jucători, respectiv nu există câștigător.


```cpp
#pragma once

#include "point.hpp"
#include "sign.hpp"

class Board {
	
	public:
		Board();
		void MakeMove(Point p, Sign sign);
		bool isMoveValid(Point p) const;
		bool checkWinSituation(Sign sign) const;
		bool checkDrawSituation() const;

	private:
		Sign board[3][3];
		void InitBoard();
};
```



- `game_status.cpp`:
Este o altă clasă enumerație care exprimă statutul jocului la un anumit moment.
```cpp
#pragma once

enum class GameStatus{
    Running, WinnerX, WinnerO, Tie
};
```

- `painter.cpp`: Se va ocupa de reprezentarea vizuală a jocului în consolă
- **ClearFrame()** va curăți consola.
- **DrawBoard()** va desena masa de joc în ipostaza ei curentă.
- **PrintGameStatus()** va afișa statutul jocului după fiecare pas al jucătorilor, anunțând ipostaza actuală a jocului.

```cpp
#pragma once

#include "board.hpp"

class Painter {
	public:
		void ClearFrame();
		void DrawBoard(Board board);
		void PrintGameStatus();
};
```
- `player.hpp`: Clasa care va reprezenta un jucător în aplicație.
- Constructorul jucătorului îl va inițializa cu un Semn anumit.
- Metoda **GetSign()** returnează semnul pe care jucătorul îl deține (X sau O).

```cpp
#pragma once

#include "board.hpp"

class Player{
    public:
        Player(Sign sign);
        Sign GetSign() const;

    private:
        Sign sign;
};
```

- `difficulty.hpp`: O enumerație a dificultăților posibile pentru jucătorul robot/adversar al jucătorului

```cpp
#pragma once

enum class Difficulty{
    noob, experienced, expert, impossible
};
```


- `robot.hpp`: Conține clasa **Robot** care moștenește de la clasa **Player**
- Poate fi inițializat folosind constructorul și ca paramentru, dificultatea dorită pentru Robot.
- Metoda **getDifficulty()** returnează dificultatea la care robotul este setat.
- Metoda **makeMove()** va primi ca paramentru statutul curent al mesei de joc și va returna poziția pe care robotul va determina că va merge în dependență de dificultate.

```cpp
#pragma once

#include "player.hpp"
#include "difficulty.hpp"

class Robot : public Player{
    public:
        Robot(Difficulty diff);
        Difficulty getDifficulty() const;
    private:
        Difficulty difficulty;
        Point makeMove(Board board);

};

```

- `game_engine.hpp`: Conține **GameEngine** care este responsabilă de manevrarea programului.
- **StartGame()** va porni jocul.
- **isGameOver()** va verifica dacă jocul este terminat
- **checkStatus()** va returna statul la care se află jocul momentan
- **getBoard()** va returna o referiță la masa de joc
- **SwitchPlayer()** va răspunde de alternarea jucătorilor
- **handleMove()** va răspunde de imputul jucătorului.
```cpp
#pragma once

#include "painter.hpp"
#include "robot.hpp"
#include "game_status.hpp"

class GameEngine{
    public:
        void StartGame();
        bool isGameOver() const;
        
        GameStatus checkStatus() const;
        Board& getBoard();

    private:
        Board board;
        Player player1;
        Player player2;
        Robot robot;
        GameStatus status;

        short int currentPlayerNumber;

        void SwitchPlayer();
        void handleMove();

};
```


