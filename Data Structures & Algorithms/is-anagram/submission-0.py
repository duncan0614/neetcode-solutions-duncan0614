class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        tempWord = []
        for chr_s in s:
            tempWord.append(chr_s)
        
        for chr_t in t:
            if tempWord == []:
                return False
                
            if chr_t in tempWord:
                tempWord.remove(chr_t)
        
        if tempWord != []:
            return False
        else:
            return True
        