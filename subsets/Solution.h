/*
    17. Subsets
    Given a set of distinct integers, return all possible subsets.

    Example
    Example 1:

    Input: [0]
    Output:
    [
      [],
      [0]
    ]
    Example 2:

    Input: [1,2,3]
    Output:
    [
      [3],
      [1],
      [2],
      [1,2,3],
      [1,3],
      [2,3],
      [1,2],
      []
    ]
    Challenge
    Can you do it in both recursively and iteratively?

    Notice
    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.
 */

/*
    Summary:
        - sort the array to exclude the duplications
        - use two loops:
            - the outter loop controls the target size of the subset, e.g. from 0 to nums.size()
            - the inner loop is inside the DFS, and it is the typical one to loop through the nums and add element to candidate
 */

class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end());
        vector<vector<int>> solution; 
        for (int i = 0; i <= nums.size(); ++i) {
            vector<int> candidate; 
            _subsets(nums, i, 0, candidate, solution); 
        }
        return solution; 
    }
    
private:
    void _subsets(vector<int>& nums, int target, int start, vector<int> candidate, vector<vector<int>>& solution) {
        if (candidate.size() == target) {
            solution.push_back(candidate);
            return; 
        }
        for (int i = start; i < nums.size(); ++i) {
            candidate.push_back(nums[i]);
            _subsets(nums, target, i + 1, candidate, solution); 
            candidate.pop_back();
        }
    }
    
};