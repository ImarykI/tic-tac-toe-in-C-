#pragma once

#include "board.hpp"
#include "player.hpp"
#include "game_status.hpp"

struct AbstractPainter {
    virtual void ClearFrame() = 0;
    virtual void DrawBoard(std::array<std::array<Sign, 3>, 3> board) = 0;
    virtual void PrintGameStatus(Player player, GameStatus currentGameStatus) = 0;
};