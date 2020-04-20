//
// Created by strobe on 4/19/20.
//

#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum2(vector<int>& num, int target) {
        vector<vector<int>> result{};
        if (num.size() == 0)
            return result;
        sort(num.begin(), num.end());
        vector<int> current;
        DFS(num, 0, target, current, result);
        return result;
    }

private:
    void DFS(const vector<int>& num, int index, int target, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0)
            return;
        for (int i = index; i < num.size(); i++) {
            if (i > index && num[i] == num[i - 1])
                continue;
            current.push_back(num[i]);
            DFS(num, i + 1, target - num[i], current, result);
            current.pop_back();
        }
    }
};