class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0

        ret = 0
        checked = set()
        for r in range(len(s)):
            while s[r] in checked:
                checked.remove(s[l])
                l += 1
            
            ret = max(ret, r - l + 1)
            checked.add(s[r])
        
        return ret