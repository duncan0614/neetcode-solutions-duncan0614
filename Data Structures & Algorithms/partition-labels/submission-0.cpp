class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> charMap;
        for (int i = 0; i < s.length(); i++){
            charMap[s[i]] = i;
        }

        vector<int> subCount;
        int size = 0, end = 0;
        for (int i = 0; i < s.length(); i++){
            size++;
            end = max(end, charMap[s[i]]);

            if (end == i){
                subCount.push_back(size);
                size = 0;
            }
        }
        
        return subCount;
    }
};
