class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []

        numberMap = {   "2":["a", "b", "c"],
                        "3":["d", "e", "f"],
                        "4":["g", "h", "i"],
                        "5":["j", "k", "l"],
                        "6":["m", "n", "o"],
                        "7":["p", "q", "r", "s"],
                        "8":["t", "u", "v"],
                        "9":["w", "x", "y", "z"],
                    }

        ret = []
        

        def dfs(i, letter):
            if i == len(digits):
                ret.append(letter)
                return
            
            nums = numberMap[digits[i]]
            for j in range(len(nums)):
                dfs(i + 1, letter + nums[j])
        
        dfs(0, "")
        return ret
