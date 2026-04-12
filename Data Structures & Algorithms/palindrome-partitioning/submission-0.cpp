class Solution {
    vector<vector<string>> ret;
public:
    vector<vector<string>> partition(string s) {
        vector<string> subset;
        backTrack(0, 0, s, subset);
        return ret;
    }

    void backTrack(int j, int i, string& s, vector<string>& subset) {
        if (i >= s.size()) {
            if (i == j) {
                ret.push_back(subset);
            }
            return;
        }

        if (isPali(s, j, i)) {
            subset.push_back(s.substr(j, i - j + 1));
            backTrack(i + 1, i + 1, s, subset);
            subset.pop_back();
        }

        backTrack(j, i + 1, s, subset);
        return;
    }

    bool isPali(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
