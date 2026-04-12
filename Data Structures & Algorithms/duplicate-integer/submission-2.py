class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        
        checkSuccess = set()

        for num in nums:
            if num in checkSuccess:
                return True
            checkSuccess.add(num)
        
        return False
            