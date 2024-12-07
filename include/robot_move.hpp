#pragma once

    /**
     * @brief Clasa ce reprezintă o mișcare de robot. 
     * Conține valori X Y pentru coordonate și score pentru scorul mișcării.
     */
class RobotMove{

    friend class Robot;
    int x;
    int y;
    int score;

public:

    /**
     * @brief Construiește un nou obiect de tip RobotMove
     * 
     */
    RobotMove(){};

    /**
     * @brief Contruiește un nou obiect de tip RobotMove cu parametrul score.
     * 
     * @param Score Scorul cu care se inițializează mișcarea.
     */
    RobotMove(int Score):score(Score){};
};