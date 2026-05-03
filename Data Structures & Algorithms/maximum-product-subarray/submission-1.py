class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ret = max(nums)
        curMin, curMax = 1, 1

        for n in nums:
            tmp = n * curMax
            curMax = max(tmp, n * curMin, n)
            curMin = min(tmp, n * curMin, n)
            ret = max(ret, curMax)

        return ret