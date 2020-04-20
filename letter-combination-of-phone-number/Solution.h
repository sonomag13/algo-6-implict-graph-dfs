/*
    425. Letter Combinations of a Phone Number
    Given a digit string excluded 0 and 1, return all possible letter combinations that the number could represent.

    A mapping of digit to letters (just like on the telephone buttons) is given below.

    1   2
    ABC 3
    DEF
    4
    GHI 5
    JKL 6
    MNO
    7
    PQRS    8
    TUV 9
    WXYZ
    Example
    Example 1:

    Input: "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
    Explanation: 
    '2' could be 'a', 'b' or 'c'
    '3' could be 'd', 'e' or 'f'
    Example 2:

    Input: "5"
    Output: ["j", "k", "l"]
    Notice
    Although the answer above is in lexicographical order, your answer could be in any order you want.
 */

class Solution {
public:
    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        // write your code here
        vector<string> solution{}; 
        if (digits == "")
             return solution; 
        string currentState; 
        dfs(digits, 0, currentState, solution); 
        return solution; 
    }
    
private:
    vector<string> lookupTable { {""}, {""}, {"abc"}, {"def"}, {"ghi"}, {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"} };
    
    void dfs(const string& digits, int idx, string currentState, vector<string>& result) {
        if (idx == digits.length()) {
            result.push_back(currentState);
            return; 
        }
        for (auto ele : lookupTable[digits[idx] - '0']) {
            dfs(digits, idx + 1, currentState + ele, result);
        }
    }

};