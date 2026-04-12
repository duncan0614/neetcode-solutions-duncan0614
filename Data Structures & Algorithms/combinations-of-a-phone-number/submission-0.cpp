class Solution {
public:
    vector<string> ret;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return ret;
        }
        backtrack(digits, 0, "");
        return ret;
    }

private:
    void backtrack(string& digits, int index, string curstr) {
        if (curstr.size() == digits.size()) {
            ret.push_back(curstr);
            return;
        }

        string chars = digitToChar[digits[index] - '0'];
        for (const auto& c : chars) {
            backtrack(digits, index + 1, curstr + c);
        }

        return;
    }   
};
