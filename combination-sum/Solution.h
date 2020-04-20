/*
    135. Combination Sum
    Given a set of candidtate numbers candidates and a target number target. Find all unique combinations in candidates where the numbers sums to target.

    The same repeated number may be chosen from candidates unlimited number of times.

    Example
    Example 1:

    Input: candidates = [2, 3, 6, 7], target = 7
    Output: [[7], [2, 2, 3]]
    Example 2:

    Input: candidates = [1], target = 3
    Output: [[1, 1, 1]]
    Notice
    All numbers (including target) will be positive integers.
    Numbers in a combination a1, a2, … , ak must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak)
    Different combinations can be in any order.
    The solution set must not contain duplicate combinations.
 */

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int>> solution; 
        if (candidates.empty())
            return solution; 
        this->target = target; 
        vector<int> combination; 
        _combinationSum(candidates, combination, solution); 
        return solution; 
    }
    
private: 
    int target;
    set<string> setSolution; 
    void _combinationSum(vector<int>& candidates, vector<int> combination, vector<vector<int>>& solution) {
        int sumVec = accumulate(combination.begin(), combination.end(), 0);
        if (sumVec == target) {
            sort(combination.begin(), combination.end());
            string key = getKey(combination); 
            if (setSolution.find(key) == setSolution.end()) {
                solution.push_back(combination); 
                setSolution.insert(key);
                return;     
            }
        }
        if (sumVec > target)
            return; 
        for (int i = 0; i < candidates.size(); ++i) {
            combination.push_back(candidates[i]); 
            _combinationSum(candidates, combination, solution);
            combination.pop_back();
        }
    } 
    
    string getKey(vector<int>& combination) {
        string key{""}; 
        for (auto ele : combination) {
            key += to_string(ele); 
        }
        return key; 
    }
};