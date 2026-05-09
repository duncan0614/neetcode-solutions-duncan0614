class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxNum, cur = nums[0], 0

        for num in nums:
            if cur < 0:
                cur = 0
            cur += num
            maxNum = max(maxNum, cur)
        return maxNum