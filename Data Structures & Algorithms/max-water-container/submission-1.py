class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l, r = 0, len(heights) - 1
        curr = 0

        while l < r:
            area = (r - l) * min(heights[l], heights[r])
            curr = max(area, curr)

            if heights[l] > heights[r]:
                r -= 1
            else:
                l += 1
        
        return curr