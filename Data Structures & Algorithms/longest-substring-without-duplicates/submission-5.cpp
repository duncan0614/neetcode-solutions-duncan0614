class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charList;
        int lIndex = 0;
        int ret = 0;
        for (int rIndex = 0; rIndex < s.length(); rIndex++){

            while (charList.find(s[rIndex]) != charList.end()){
                charList.erase(s[lIndex]);
                lIndex++;
            }

            charList.insert(s[rIndex]);
            ret = max(ret, rIndex - lIndex + 1);
        }

        return ret;
    }
};
