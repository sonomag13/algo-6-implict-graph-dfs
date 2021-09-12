// LeetCode 47. Permutations II
// Medium

#include <vector>

using namespace std; 

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> result; 
        vector<bool> visited(nums.size(), false);        
        
        sort(nums.begin(), nums.end());
        
        vector<int> candidate; 
        
        dfs(nums, visited, candidate, result);
        
        return result;
        
    }
    
    void dfs(vector<int>& nums, vector<bool> visited, vector<int> candidate, vector<vector<int>>& result) {
        
        if (nums.size() == candidate.size()) {
            result.push_back(candidate); 
            return; 
        }
        
        for (int i = 0; i < nums.size(); ++i) {                                    
            
            if (visited[i]) {
                continue;                 
            }                        
            
            // IMPORTANT
            /**
             * using 1, 1, 2 for example
             * one of the solution is 1, 1, 2
             * but if we do not check !visited[i - 1]
             * the second 1 will never been appended to form the solution 1, 1, 2
             **/
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue; 
            }
            
            candidate.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, visited, candidate, result); 
            candidate.pop_back();
            visited[i] = false;
             
        }
        
    }
};