#pragma once

#include "board.hpp"
#include "player.hpp"
#include "game_status.hpp"

struct AbstractPainter {
    virtual void ClearFrame() = 0;
    virtual void DrawBoard(Sign board[3][3]) = 0;
    virtual void PrintGameStatus(Player player, GameStatus currentGameStatus) = 0;
};