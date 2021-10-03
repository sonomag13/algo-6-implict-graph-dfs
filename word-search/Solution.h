#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        _rowNum = board.size(); 
        if (!_rowNum) {
            return false; 
        }        
        _colNum = board[0].size(); 
        if (!_colNum) {
            return false; 
        }
        
        _word = move(word);
        
        bool isFound{false}; 
        
        for (int i = 0; i < _rowNum; ++i) {
            for (int j = 0; j < _colNum; ++j) {                     
                if (_searchWord(board, 0, i, j, "")) {
                    return true; 
                }
            }
        }
        
        return false; 
        
    }
    
private:
    int _rowNum{0}, _colNum{0}; 
    string _word; 
    
    bool _searchWord(vector<vector<char>>& board, int charIdx, int i, int j, string currWord) {
        
        // the string is found
        if (currWord == _word) {
            return true; 
        }
        
        // the current string has the same size to the target string, but they do not match
        // actually there is no need to check this since the string will never grow to the size
        // of the word if it is not a match
        // if (currWord.size() == _word.size()) {
        //     return false; 
        // }
        
        // the indices are out of the bounds                
        if (i < 0 || i >= _rowNum || j < 0 || j >= _colNum) {
            return false; 
        }
        
        // if the current character match with the desired character in the target string
        if (board[i][j] != _word[charIdx]) {
            return false; 
        }        
        
        // append the current character to the string
        currWord += _word[charIdx];         
        charIdx++; 
        
        /**
         * search for the neighbors in the four directions
         * Ideally we can pass a visited matrix in DFS, but the tricky part is that there
         * will a run time exceed limit error if using this method. 
         * 
         * LeetCode perfer to mark the visited in-place, e.g. to directly mark num[i][j] 
         * a special character, e.g. '#'. 
         * 
         * But after the searching, we need to reset with nums[i][j] with its original value. 
         * Ohterwise, for the next coordindate i, j, nums is a modified version (with a lot of
         * special characters in it), not its original version making the searching illegal
         **/
        char tmp = board[i][j];
        board[i][j] = '#';         
        bool isFound{_searchWord(board, charIdx, i + 1, j, currWord) || 
                     _searchWord(board, charIdx, i - 1, j, currWord) ||
                     _searchWord(board, charIdx, i, j + 1, currWord) ||
                     _searchWord(board, charIdx, i, j - 1, currWord)};
        board[i][j] = tmp;

        return isFound; 
        
    }
    
};