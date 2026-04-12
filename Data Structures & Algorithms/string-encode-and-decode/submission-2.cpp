class Solution {
public:

    string encode(vector<string>& strs) {
        string ret;
        for(auto& str : strs){
            ret += to_string(str.length()) + "#" + str;
        }

        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        int strIndex = 0;
        while(strIndex < s.length()){
            int keyIndex = strIndex;
            
            while (keyIndex < s.length()){
                if(s[keyIndex] == '#'){
                    break;
                }
                keyIndex++;
            }

            int len = stoi(s.substr(strIndex, keyIndex - strIndex));
            int wordStartIndex = keyIndex + 1;
            ret.push_back(s.substr(wordStartIndex, len));
            strIndex = wordStartIndex + len;
        }

        return ret;
        
    }
};
