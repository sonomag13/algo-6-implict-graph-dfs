/*
680. Split String
Give a string, you can choose to split the string after one character or two adjacent characters, and make the string to be composed of only one character or two characters. Output all possible results.

Example
Example1

Input: "123"
Output: [["1","2","3"],["12","3"],["1","23"]]
Example2

Input: "12345"
Output: [["1","23","45"],["12","3","45"],["12","34","5"],["1","2","3","45"],["1","2","34","5"],["1","23","4","5"],["12","3","4","5"],["1","2","3","4","5"]]
 */

class Solution {
public:
    /*
     * @param : a string to be split
     * @return: all possible split string array
     */
    vector<vector<string>> splitString(string& s) {
        // write your code here
        vector<vector<string>> result; 
        vector<string> path; 
        int idx{0}; 
        _splitString(s, idx, path, result); 
        return result; 
    }
private:
    
    void _splitString(string& s, int idx, vector<string> path, vector<vector<string>>& result) {
        
        //basic case
        if (idx == s.length()) {
            result.push_back(path);
            return; 
        }
        if (idx > s.length()) {
            return; 
        }
        
        string substr1 = s.substr(idx, 1);
        path.push_back(substr1); 
        _splitString(s, idx+1, path, result); 
        
        path.pop_back(); 
        
        string substr2 = s.substr(idx, 2); 
        path.push_back(substr2); 
        _splitString(s, idx+2, path, result); 
        
        
    }
    
    
};