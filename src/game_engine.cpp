#include "../include/game_engine.hpp"

const std::string GameEngine::gameModeMenu = "Choose a game mode:\n1.Player vs Player\n2.Player vs Robot\n->";
const std::string GameEngine::chooseSignMenu = "Chose the sign for Player 1: X or O\n->";
const std::string GameEngine::robotDiffMenu = "Chose a difficutly for the robot:\n1. Noob\n2. Experienced\n3. Expert\n->";
const std::string GameEngine::instructionsMsg = " has to chose a move:\nWrite the coordonates of the grid, where you want your sign to be placed\nTop left cell is (1 1), bottom right one is (3 3):\n->";

GameEngine::GameEngine(): player1(Sign::Empty), player2(Sign::Empty){
    currentPlayerNumber = 1;
    status = GameStatus::Running;
};

GameEngine::GameEngine(Board board, Player player1, Player player2, GameStatus status, Painter painter, short int currPlayerNumber){
    this->board = board;
    this->player1 = player1;
    this->player2 = player2;
    this->status = status;
    this->painter = painter;
    currentPlayerNumber = currPlayerNumber;
};

GameEngine::GameEngine(const GameEngine& gameEngine){
    board = gameEngine.board;
    player1 = gameEngine.player1;
    player2 = gameEngine.player2;
    status = gameEngine.status;
    painter = gameEngine.painter;
    currentPlayerNumber = gameEngine.currentPlayerNumber;
};

GameEngine& GameEngine::operator=(const GameEngine& gameEngine){
    board = gameEngine.board;
    player1 = gameEngine.player1;
    player2 = gameEngine.player2;
    status = gameEngine.status;
    painter = gameEngine.painter;
    currentPlayerNumber = gameEngine.currentPlayerNumber;

    return *this;
};

bool GameEngine::operator==(const GameEngine& other)const{
    return other.status == status;
};


std::istream& operator >> (std::istream& in, GameEngine& gameEngine){
    Board board;
    Player player1, player2;
    Painter painter;
    short int currPlayerNumber;

    in >> board >> player1 >> player2 >> painter >> currPlayerNumber;

    gameEngine = GameEngine(board, player1, player2, GameStatus::Running, painter, currPlayerNumber);

    return in;
};

std::ostream& operator << (std::ostream& out, const GameEngine& gameEngine){
    out << gameEngine.board << "\n" << gameEngine.currentPlayerNumber;

    return out;
};


void GameEngine::StartGame()
{ 
    while(true){
        painter.ClearFrame();

        char game_mode_var;
        bool is_imput_valid = false;
        std::cout << gameModeMenu;
        std::cin >> game_mode_var;
        if(game_mode_var == '1'){
            isMultiplayer = true;
            painter.ClearFrame();
            std::cout << chooseSignMenu;
            std::cin >> game_mode_var;
            if(game_mode_var == 'x'){
                player1 = Player(Sign::X);
                player2 = Player(Sign::O);
                is_imput_valid = true;
            } else if(game_mode_var == 'o'){
                player2 = Player(Sign::X);
                player1 = Player(Sign::O);    
                is_imput_valid = true;       
            };
        } else if (game_mode_var == '2')
        {   
            isMultiplayer = false;
            painter.ClearFrame();
            std::cout << chooseSignMenu;
            std::cin >> game_mode_var;
            if(game_mode_var == 'x') player1 = Player(Sign::X);
            else if(game_mode_var == 'o') player1 = Player(Sign::O);
            else continue;
            painter.ClearFrame();
            std::cout << robotDiffMenu;
            std::cin >> game_mode_var;
            if(game_mode_var == '1'){
                robot = Robot(Difficulty::Noob, player1.GetSign() == Sign::O ? Sign::X : Sign::O);
                is_imput_valid = true;
            } else if(game_mode_var == '2'){
                robot = Robot(Difficulty::Experienced, player1.GetSign() == Sign::O ? Sign::X : Sign::O);
                is_imput_valid = true;
            }else if(game_mode_var == '3'){
                robot = Robot(Difficulty::Expert, player1.GetSign() == Sign::O ? Sign::X : Sign::O);
                is_imput_valid = true;
            }
        }
        if(is_imput_valid) break;
    }
        painter.ClearFrame();
        painter.DrawBoard(board.board_);
};

void GameEngine::RunGame(){
    while(IsGameOver() == false){
        HandleMove();
        painter.ClearFrame();
        painter.DrawBoard(board.board_);
        status = CheckStatus();
        if(currentPlayerNumber == 1) painter.PrintGameStatus(player1, status);
        if(currentPlayerNumber == 2 && isMultiplayer) painter.PrintGameStatus(player2, status);
        else if(currentPlayerNumber == 2 && !isMultiplayer) painter.PrintGameStatus(robot, status);
        SwitchPlayer();
    }
    EndGame(status);
};

bool GameEngine::IsGameOver() const{
    if(status != GameStatus::Running) return true;
    else return false;
};

GameStatus GameEngine::CheckStatus() const{
    if(currentPlayerNumber == 1){
        if(board.CheckWinSituation(player1.GetSign())){
            return player1.GetSign() == Sign::O ? GameStatus::WinnerO : GameStatus::WinnerX;
        };
    }
    if(currentPlayerNumber == 2 && isMultiplayer){
        if(board.CheckWinSituation(player2.GetSign())){
            return player2.GetSign() == Sign::O ? GameStatus::WinnerO : GameStatus::WinnerX;
        };
    } else if (currentPlayerNumber == 2 && !isMultiplayer) {
        if(board.CheckWinSituation(robot.GetSign())){
            return robot.GetSign() == Sign::O ? GameStatus::WinnerO : GameStatus::WinnerX;
        };
    }
    if(board.CheckDrawSituation()) return GameStatus::Tie;

return GameStatus::Running;
};

Board& GameEngine::GetBoard(){
    return board;
};

void GameEngine::SwitchPlayer(){
    if (currentPlayerNumber == 1) currentPlayerNumber = 2;
    else currentPlayerNumber = 1;
    
};

void GameEngine::HandleMove(){

    int currentMoveX = 0;
    int currentMoveY = 0;
    if(currentPlayerNumber == 1){
        std::cout << "Player " << currentPlayerNumber << instructionsMsg;
        std::cin >> currentMoveX >> currentMoveY;
        board.MakeMove(Point(currentMoveX-1,currentMoveY-1), player1.GetSign());
    }
    if(currentPlayerNumber == 2 && isMultiplayer){
        std::cout << "Player " << currentPlayerNumber << instructionsMsg;
        std::cin >> currentMoveX >> currentMoveY;
        board.MakeMove(Point(currentMoveX-1,currentMoveY-1), player2.GetSign());
    } else if(currentPlayerNumber == 2 && !isMultiplayer) {
        board.MakeMove(robot.MakeMove(board), robot.GetSign());
    }
};

void GameEngine::InitializeDatabase(sqlite3** db) {
    int rc = sqlite3_open("game_stats.db", db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(*db) << std::endl;
        return;
    }

    const char* createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS GameStats (
            Player TEXT PRIMARY KEY,
            Wins INTEGER DEFAULT 0
        );
    )";

    char* errMsg = nullptr;
    rc = sqlite3_exec(*db, createTableSQL, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}


void GameEngine::UpdateWins(sqlite3* db, const std::string& player) {
    const char* updateSQL = R"(
        INSERT INTO GameStats (Player, Wins)
        VALUES (?, 1)
        ON CONFLICT(Player)
        DO UPDATE SET Wins = Wins + 1;
    )";

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, updateSQL, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, player.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Failed to update wins: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
}

void GameEngine::DisplayStats(sqlite3* db) {
    const char* querySQL = "SELECT Player, Wins FROM GameStats";

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, querySQL, -1, &stmt, nullptr);

    std::cout << "Game Stats:\n";
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const char* player = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        int wins = sqlite3_column_int(stmt, 1);

        std::cout << player << ": " << wins << " wins\n";
    }

    sqlite3_finalize(stmt);
}

void GameEngine::EndGame(GameStatus status) {
    sqlite3* db;
    InitializeDatabase(&db);

    if (status == GameStatus::WinnerX) {
        UpdateWins(db, "Player X");
    } else if (status == GameStatus::WinnerO) {
        UpdateWins(db, "Player O");
    }

    DisplayStats(db);

    sqlite3_close(db);
}
