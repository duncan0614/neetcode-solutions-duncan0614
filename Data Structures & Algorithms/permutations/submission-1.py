class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 0:
            return [[]]

        ret = []
        perms = self.permute(nums[1:])
        for perm in perms:
            for i in range(len(perm) + 1):
                permCopy = perm.copy()
                permCopy.insert(i, nums[0])
                ret.append(permCopy)

        return ret