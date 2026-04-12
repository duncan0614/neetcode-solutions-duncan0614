class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        tempnums = []
        
        if len(nums) != 0:
            tempnums.append(nums[0])

        for i in range(1,len(nums)):
            if nums[i] in tempnums:
                return True
            else:
                tempnums.append(nums[i])
                continue
        
        return False
            