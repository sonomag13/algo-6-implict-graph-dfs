/*
    15. Permutations
    Given a list of numbers, return all possible permutations.

    Example
    Example 1:

    Input: [1]
    Output:
    [
      [1]
    ]
    Example 2:

    Input: [1,2,3]
    Output:
    [
      [1,2,3],
      [1,3,2],
      [2,1,3],
      [2,3,1],
      [3,1,2],
      [3,2,1]
    ]
    Challenge
    Do it without recursion.

    Notice
    You can assume that there is no duplicate numbers in the list.
 */

class Solution {
public:
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int>> permute(vector<int> &nums) {
        // write your code here
        vector<vector<int>> solution;
        vector<int> candidate; 
        this->n = nums.size(); 
        vector<bool> visited(n, false);
        _permute(nums, visited, candidate, solution); 
        return solution; 
    }

private:
    int n; 
    void _permute(vector<int>& nums, vector<bool> visited, vector<int> candidate, vector<vector<int>>& solution) {
        if (candidate.size() == n) {
            solution.push_back(candidate);
            return; 
        }
        for (int i  = 0; i < n; ++i) {
            if (visited[i])
                continue; 
            else {
                visited[i] = true; 
                candidate.push_back(nums[i]);
                _permute(nums, visited, candidate, solution); 
                visited[i] = false; 
                candidate.pop_back();    
            }
        }
    }
    
};