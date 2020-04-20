#include "Solution.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> inputVec{7, 1, 2, 5, 1, 6, 10};
    int target{8};
    vector<vector<int>> outputVec;
    Solution solution;
    outputVec = solution.combinationSum2(inputVec, target);

    for (auto subvec : outputVec) {
        for (auto val : subvec) {
            cout << val << "\t";
        }
        cout << endl;
    }

    return EXIT_SUCCESS;

}
