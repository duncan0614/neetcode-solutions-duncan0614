class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]

        rob1, rob2, rob3, rob4 = 0, 0, 0, 0

        for i in range(n - 1):
            rob1, rob2 = rob2, max(rob2, rob1 + nums[i])
            rob3, rob4 = rob4, max(rob4, rob3 + nums[i + 1])
        
        return max(rob2, rob4)