class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string> result;

        _generateParenthesis(n, n, "", result);

        return result;
    }

private:
    void _generateParenthesis(int left, int right, string candidate, vector<string>& result) {

        // base case
        if (left == 0 and right == 0) {
            result.push_back(candidate);
            return;
        }

        // append '(' to the candidate
        if (left > 0) {
            string candidate1 = candidate + '(';
            _generateParenthesis(left - 1, right, candidate1, result);
        }

        // append ')' to the candidate
        if (right > 0 && right > left) {
            string candidate2 = candidate + ")";
            _generateParenthesis(left, right - 1, candidate2, result);
        }

    }

};