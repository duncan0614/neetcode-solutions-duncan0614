class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        ret = 0
        curr = 0
        prefix = {0 : 1}

        for num in nums:
            curr += num
            diff = curr - k
            ret += prefix.get(diff, 0)
            prefix[curr] = 1 + prefix.get(curr, 0)
        
        return ret