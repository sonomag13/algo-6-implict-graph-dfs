/*
     33. N-Queens
    The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other(Any two queens can't be in the same row, column, diagonal line).

    Given an integer n, return all distinct solutions to the n-queens puzzle.

    Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' each indicate a queen and an empty space respectively.

    Example
    Example 1:

    Input:1
    Output:
       [["Q"]]


    Example 2:

    Input:4
    Output:
    [
      // Solution 1
      [".Q..",
       "...Q",
       "Q...",
       "..Q."
      ],
      // Solution 2
      ["..Q.",
       "Q...",
       "...Q",
       ".Q.."
      ]
    ]
 */

#include "Solution.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {

    Solution nQueen;
    vector<vector<string>> nQueenSolution {nQueen.solveNQueens(4)};

    int k = 0;
    for (auto subSolution : nQueenSolution) {
        cout << "\nk = " << k++ << endl;
        for (auto ele : subSolution) {
            cout << "\t" << ele << endl;
        }
    }

    return 0;
}
