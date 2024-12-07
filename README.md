# Tic-Tac-Toe-In-Cpp

## Descrierea Proiectului

Această aplicație este faimosul joc TicTacToe, realizat în consolă, scris limbajul de programare C++. Oferă două posibilități de Gameplay:
- PVP (Player vs Player) - doi jucători introduc coordonatele de la tastatură pe rând până când jocul se termină cu un rezultat.
- PVR (Player vs Robot) - jucătorul se îmfruntă cu un inamic cu IA, ce își schimbă stilul și stradegia de joc în dependență de dificultatea aleasă de către jucător.

Numărul de câștiguri pentru fiecare semn sunt salvate într-o bază de date.

## Regulile jocului.

**Obiectiv**: Înfrângerea adversarului prin înșirarea a trei semne consecutive pe o linie verticală, orizontală sau oblică.

**Setări inițiale**: Jocul începe cu masa de joc formată din 9 celule formatate într-o matrice 3x3. Toate celulele sunt goale. Primul merge jucătorul numărul 1, cel care a ales primul semnul.

**Cum se joacă**:

- Jucătorul alege modul de joc: PVP sau PVR.

- Dacă alege PVP:

    - Primul jucător alege semnul cu care dorește să joace: X sau O. Al doilea jucător primește automat celălalt semn.
    - Primul jucător plasează semnul ales în oricare celulă de pe masă.
    - Al doilea jucător alege și își plasează semnul său în una dintre celulele goale de pe masă.
    - Rândul îi revine primului jucător și continuă progresiv până când unul dintre jucători nu ajunge la o situație de câștig descrisă ân *obiectiv*, sau dacă toate celule sunt marcate, dar situație de câștig nu există, jocul se conclude într-o egalitate.

- Dacă alege PVR:
    - Jucătorul alege dificulatea Robotului cu care dorește să se joace. Sunt disponibile 3 opțiuni:
        - Noob
        - Experienced
        - Expert
    - Jucătorul alege semnul cu care dorește să joace X sau O. Robotul primește automat celălalt semn.
    - Jucătorul plasează semnul ales în oricare celulă de pe masă.
    - Robotul va face următoarea mișcare în dependență de dificultatea alesă și de situația de pe masă.
    - Rândul îi revine jucătorului și continuă progresiv până când jucătorul sau robotul ajung la o situație de câștig descrisă ân *obiectiv*. Sau în cazul în care toate celule sunt marcate, dar situație de câștig nu există, jocul se conclude într-o egalitate.

## Dependențele proiectului

- **Mediul de dezvoltare**: Aplicația *Visual Studio Code v1.95.3*
- **Compilator**: GNU Compile Collection - g++
- **Biblioteci terțe utilizate**:
    - **sqlite3** - pentru păstrarea istoricului câștigurilor pentru fiecare semn într-o bază de date SQLite.
    - **googletest** - pentru testare

## Modul de construcție

Proiectul poate fi construit cu **make** folosind:

   - **make** pentru a compila jocul.
   - Apoi **.bin/TicTacToeGame.exe** pentru a juca

sau

   - **make tests** pentru a compila testele
   - Apoi **.test_bin/TicTacToeTests.exe** pentru a rula testele