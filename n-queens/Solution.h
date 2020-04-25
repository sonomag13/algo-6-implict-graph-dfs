
#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string>> solveNQueens(int n) {
        // write your code here
        vector<vector<string>> solution;
        vector<string> candidate;
        this->n = n;
        setStrTemplate();
        _solveNQuenes(candidate, solution);
        return solution;
    }
private:
    int n;
    string strTemplate;
    void _solveNQuenes(vector<string> candidate, vector<vector<string>>& solution) {
        if (candidate.size() == n) {
            solution.push_back(candidate);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (isValid(col, candidate)) {
                candidate.push_back(getQString(col));
                _solveNQuenes(candidate, solution);
                candidate.pop_back();
            }
        }
    }

    bool isValid(int col, vector<string>& candidate) {
        int row = candidate.size();
        // check the column
        for (int i = row - 1; i >= 0; --i)
            if (candidate[i][col] == 'Q')
                return false;
        // diagonal
        int i = row - 1, j = col - 1;
        while (i >= 0 && j >= 0) {
            if (candidate[i--][j--] == 'Q')
                return false;
        }
        // anti-diagonal
        i = row - 1;
        j = col + 1;
        while (i >= 0 && j < n) {
            if (candidate[i--][j++] == 'Q')
                return false;
        }
        return true;
    }

    void setStrTemplate() {
        for (int i = 0; i < n; ++i)
            strTemplate += '.';
    }

    string getQString(int idx) {
        string qString{strTemplate};
        qString[idx] = 'Q';
        return qString;
        /*
        for (int i = 0; i < n; ++i) {
            if (i == idx)
                qString += "Q";
            else
                qString += ".";
        }
        return qString;
         */
    }

};