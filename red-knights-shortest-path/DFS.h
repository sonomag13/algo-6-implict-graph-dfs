#pragma once

#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

const vector<string> priority = {"UL", "UR", "R", "LR", "LL", "L"};
const vector<pair<int, int>> dxdy = {{-1, -2},
                                     {+1, -2},
                                     {+2,  0},
                                     {+1, +2},
                                     {-1, +2},
                                     {-2,  0}};
vector<vector<pair<int, int>>> allMoves;

vector<string> convertNumToStr(const vector<pair<int, int>> & movesNum) {

    vector<string> movesStr;

    for (auto & move : movesNum) {
        auto it = find(dxdy.begin(), dxdy.end(), move);
        movesStr.push_back(priority[it - dxdy.begin()]);
    }

    return movesStr;
}

void dfs(vector<vector<bool>> visited,
         vector<pair<int, int>> candidate,
         int i_start,
         int j_start,
         int i_end,
         int j_end,
         int n) {

    if (i_start == i_end && j_start == j_end) {
        allMoves.push_back(candidate);
        return;
    }

    visited[i_start][j_start] = true;

    for (auto & nextMove : dxdy) {

        int i_next = i_start + nextMove.second;
        int j_next = j_start + nextMove.first;

        if (!inBoundary(n, i_next, j_next) || visited[i_next][j_next]) {
            continue;  // the next position will be outside the boundary
        }
        candidate.push_back(nextMove);
        dfs(visited, candidate, i_next, j_next, i_end, j_end, n);
        candidate.pop_back();
    }

}

bool compareMoves(const vector<pair<int, int>> & refMove,
                  const vector<pair<int, int>> & otherMove) {

    for (int i = 0; i < refMove.size(); ++i) {
        int priRefMove = find(dxdy.begin(),
                              dxdy.end(),
                              refMove[i]) - dxdy.begin();

        int priOtherMove = find(dxdy.begin(),
                                dxdy.end(),
                                otherMove[i]) - dxdy.begin();

        if (priRefMove < priOtherMove) {
            return true;
        }

        if (priRefMove > priOtherMove) {
            return false;
        }
    }

    return true;
}

void printShortestPath_DFS(int n, int i_start, int j_start, int i_end, int j_end) {
    // Print the distance along with the sequence of moves.

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<pair<int, int>> candidateNum;

    dfs(visited, candidateNum, i_start, j_start, i_end, j_end, n);

    if (allMoves.empty()) {
        cout << "Impossible";
        return;
    }

    size_t minNumMoves = INT_MAX;

    for (auto & curMove : allMoves) {
        minNumMoves = min(minNumMoves, curMove.size());
    }

    vector<vector<pair<int, int>>> candidateMinMoves;

    for (auto & curMove : allMoves) {
        if (curMove.size() == minNumMoves) {
            candidateMinMoves.push_back(curMove);
        }
    }

    vector<pair<int, int>> solutionNum = candidateMinMoves[0];

    for (int i = 1; i < candidateMinMoves.size(); ++i) {
        if (!compareMoves(solutionNum, candidateMinMoves[i])) {
            solutionNum = candidateMinMoves[i];
        }
    }

    vector<string> solutionStr = convertNumToStr(solutionNum);

    cout << minNumMoves << '\n';
    for (auto & moveStr : solutionStr) {
        cout << moveStr << ' ';
    }

}