#pragma once

#include <unordered_map>
#include <vector>

#include "board.h"

class Solution {
public:
    explicit Solution(const std::vector<Move> &moves);

    const std::vector<Move> &Moves() const {
        return m_Moves;
    }

    int NumMoves() const {
        return m_Moves.size();
    }

private:
    std::vector<Move> m_Moves;
};

class Solver {
public:
    Solution Solve(Board &board);
    int CountMoves(Board &board);
private:
    bool Search(Board &board, int depth, int maxDepth, int previousPiece);
    std::vector<Move> m_Moves;
    std::vector<std::vector<Move>> m_MoveBuffers;
    std::unordered_map<bb, int> m_Memo;
};
