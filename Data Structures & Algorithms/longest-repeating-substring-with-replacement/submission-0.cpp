class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int ret = 0;

        int lIndex = 0, maxf = 0;
        for (int rIndex = 0; rIndex < s.length(); rIndex++){
            count[s[rIndex]]++;
            maxf = max(maxf, count[s[rIndex]]);

            while ((rIndex - lIndex + 1) - maxf > k){
                count[s[lIndex]]--;
                lIndex++;
            }

            ret = max(ret, rIndex - lIndex + 1);
        }

        return ret;
    }
};
