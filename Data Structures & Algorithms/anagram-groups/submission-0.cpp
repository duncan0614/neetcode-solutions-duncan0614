class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> tempMap;
        for (const auto& s : strs){
            vector<int> count(26);
            for (char c : s){
                count[c - 'a'] += 1;
            }

            string key = to_string(count[0]);
            for(int i = 0; i < 26; ++i){
                key += ',' + to_string(count[i]);
            }

            tempMap[key].push_back(s);
        }

        vector<vector<string>> ret;
        for(const auto& pair : tempMap){
            ret.push_back(pair.second);
        }

        return ret;
    }
};
