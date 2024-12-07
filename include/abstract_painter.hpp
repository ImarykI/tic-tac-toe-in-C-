#pragma once

#include "board.hpp"
#include "player.hpp"
#include "game_status.hpp"



/**
 * @brief Clasa abstracta care este moștenită de către Painter
 * 
 */
struct AbstractPainter {

    const static int BOARD_SIZE = 3;
    /**
     * @brief Metodă virtuală ce curăță consola
     * 
     */
    virtual void ClearFrame() = 0;

    /**
     * @brief Metodă virtuală ce desenează masa în starea ei curentă.
     * 
     * @param board Array bidimensional 3/3
     */
    virtual void DrawBoard(std::array<std::array<Sign, BOARD_SIZE>, BOARD_SIZE> board) = 0;

    /**
     * @brief Metodă virtuală ce afișează situația curentă a jocului.
     * 
     * @param player Jucătorul pentru care se printează statutul.
     * @param currentGameStatus Statutul curent al jocului.
     */
    virtual void PrintGameStatus(Player player, GameStatus currentGameStatus) = 0;
};