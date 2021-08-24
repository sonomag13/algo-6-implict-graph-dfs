#include <vector>

using namespace std;

struct TrieNode {

    bool is_end;    // mark if the node is an end of an pre-added word
    vector<TrieNode*> children;  // vector of the next character

    TrieNode(): is_end(false), children(26, nullptr) {
    }

    ~TrieNode() {
        for (auto child : children) {
            if (child) {
                delete child;
            }
        }
    }

};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary(): root(new TrieNode()) {
    }

    void addWord(string word) {

        TrieNode * currNode{root};

        for (auto c : word) {
            // traverse all the characteris in the word
            int idx = c - 'a'; // the index of the character in TrieNode->children
            if (!currNode->children[idx]) {
                // the character does not have an entry in the children yet
                currNode->children[idx] = new TrieNode();
            }
            // move the current node for the next entry of the character
            currNode = currNode->children[idx];
        }

        currNode->is_end = true;  // this node is an end of the word

    }

    bool search(string word) {
        
        // DFS is used
        return _search(word, 0, root);
    }

private:
    TrieNode* root; // a dummy node as the entrance

    bool _search(const string& word, int idx, TrieNode* currNode) {
        /**
         * Args:
         * word -- the word to be searched
         * idx -- the index of the character in the word
         * currNode -- current node 
         **/


        if (idx == word.length()) {
            // base case and return is_end flag
            // e.g. if is_end == true, the word if found, and vice versa
            return currNode->is_end;
        }

        bool found{false};

        if (word[idx] == '.') {
            // the character is '.', search all the non-trival childen
            for (auto child : currNode->children) {
                if (child) {
                    found |= _search(word, idx + 1, child);
                }
            }
        }
        else {
            // the character is not '.', check if the chracter links to a non-trivial
            // node in the children
            //      - if no such node, return false
            //      - if yes, go the next iteration of searching 
            int idxNode = word[idx] - 'a';  // index of the character
            if (currNode->children[idxNode]) {
                // the node of the character exist in the children
                found |= _search(word, idx + 1, currNode->children[idxNode]);
            }
        }

        return found;
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */