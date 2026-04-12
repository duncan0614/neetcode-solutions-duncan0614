class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()){
            return false;
        }
        
        unordered_map<char, int> sCharMap;
        unordered_map<char, int> tCharMap;

        for(int i = 0; i <s.size(); i++){
            sCharMap[s[i]] += 1; 
            tCharMap[t[i]] += 1; 
        }

        for(auto item : sCharMap){
            if(sCharMap[item.first] != tCharMap[item.first]){
                return false;
            }
        }

        return true;
    }
};
