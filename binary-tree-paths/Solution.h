// 257. Binary Tree Paths
// Easy

#include <vector>

using namespace std; 

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {        
        vector<string> paths;        
        string candidate = ""; 
        dfs(root, candidate, paths);         
        return paths; 
    }

private: 
    void dfs(TreeNode* curr, string candidate, vector<string>& paths) {
        
        if (!curr->left && !curr->right) {            
            if (!candidate.size()) {
                candidate += to_string(curr->val);
            }
            else {
                candidate += "->" + to_string(curr->val);
            }                        
            paths.push_back(candidate);
            return;
        }
        
        if (!candidate.size()) {
            // the first number
            candidate += to_string(curr->val);    
        }
        else {
            // the following numbers
            candidate += "->" + to_string(curr->val);
        }
        
        if (curr->left) {
            dfs(curr->left, candidate, paths);
        }
        
        if (curr->right) {
            dfs(curr->right, candidate, paths);    
        }
        
        
    }
};