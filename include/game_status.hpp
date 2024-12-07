#pragma once

/**
 * @brief Stări posibile pentru statutul jocului.
 * Running = 0,
 * WinnerX = 1,
 * WinnerO = 2,
 * Tie = 3.
 * 
 */
enum class GameStatus{
    Running, WinnerX, WinnerO, Tie
};