
/*
	153. Combination Sum II
	Given an array num and a number target. Find all unique combinations in num where the numbers sum to target.

	Example
	Example 1:

	Input: num = [7,1,2,5,1,6,10], target = 8
	Output: [[1,1,6],[1,2,5],[1,7],[2,6]]
	Example 2:

	Input: num = [1,1,1], target = 2
	Output: [[1,1]]
	Explanation: The solution set must not contain duplicate combinations.
	Notice
	Each number in num can only be used once in one combination.
	All numbers (including target) will be positive integers.
	Numbers in a combination a1, a2, … , ak must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak)
	Different combinations can be in any order.
	The solution set must not contain duplicate combinations.
 */

class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        // write your code here
        this->target = target; 
        this->numSize = num.size(); 
        // vector<bool> visited(num.size(), false); 
        set<vector<int>> setSolution;
        vector<int> candidate; 
        _combinationSum2(num, 0, 0, candidate, setSolution); 
        vector<vector<int>> solution(setSolution.begin(), setSolution.end()); 
        return solution; 
    }
private:
    int target; 
    int numSize; 
    void _combinationSum2(vector<int>& num, int start, int sum, vector<int> candidate, set<vector<int>>& setSolution) {

	/* 
		notice that it should 
			start > numSize 
		instead of 
			start >= numSize 
		since i + 1 is passed to the next level, so that when at the last element, start == numSize is actually allowed
	 */
        if (start > numSize || sum > target) {
            return; 
        }
        if (sum == target) {
            sort(candidate.begin(), candidate.end());
            setSolution.insert(candidate);
            return; 
        }
        for (int i = start; i < numSize; ++i) {
            candidate.push_back(num[i]); 
            sum += num[i]; 
            _combinationSum2(num, i+1, sum, candidate, setSolution); 
            candidate.pop_back(); 
            sum -= num[i]; 
        }
    } 
};
