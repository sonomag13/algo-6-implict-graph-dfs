#pragma once

#include <iostream>
#include <queue>
#include <vector>

#include "utils.h"

using namespace std;


/*
 * Complete the 'printShortestPath' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER i_start
 *  3. INTEGER j_start
 *  4. INTEGER i_end
 *  5. INTEGER j_end
 */


struct Motion {
public:
    Motion(int dx, int dy, const string & str): dx(dx), dy(dy), str(str) {}
    ~Motion() = default;

    int dx;
    int dy;
    string str;
};

vector<Motion> allMotions = {{-1, -2, "UL"},
                             {+1, -2, "UR"},
                             {+2,  0, "R"},
                             {+1, +2, "LR"},
                             {-1, +2, "LL"},
                             {-2,  0, "L"}};

struct Position {
public:
    Position(int i, int j): i(i), j(j), numSteps(0) {}
    Position(int i, int j, int numSteps, const vector<string> & moves):
            i(i),
            j(j),
            numSteps(numSteps),
            moves(moves) {}

    ~Position() = default;
    int i;
    int j;
    int numSteps;
    vector<string> moves;
};

void printSolution(int numSteps, const vector<string> & moves) {

    cout << numSteps << '\n';
    for (auto & mov : moves) {
        cout << mov << ' ';
    }
}

void bfs(int i_start, int j_start, int i_end, int j_end, int n) {

    queue<Position> quePos;
    quePos.push(Position(i_start, j_start));

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    while (!quePos.empty()) {
        auto curPos = quePos.front();
        quePos.pop();

        for (auto & motion : allMotions) {

            int i_next = curPos.i + motion.dy;
            int j_next = curPos.j + motion.dx;

            if (!inBoundary(i_next, j_next, n) || visited[i_next][j_next]) {
                continue;
            }

            visited[i_next][j_next] = true;
            auto nextMoves = curPos.moves;
            nextMoves.push_back(motion.str);

            int nextNumSteps = curPos.numSteps + 1;

            if (i_next == i_end && j_next == j_end) {
                printSolution(nextNumSteps, nextMoves);
                return;
            }

            quePos.push(Position(i_next, j_next, nextNumSteps, nextMoves));
        }
    }

    cout << "Impossible";
}

void printShortestPath_BFS(int n, int i_start, int j_start, int i_end, int j_end) {
    // Print the distance along with the sequence of moves.

    bfs(i_start, j_start, i_end, j_end, n);

}