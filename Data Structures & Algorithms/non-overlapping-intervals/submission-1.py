class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        ret = 0

        intervals.sort(key = lambda x : x[0])
        cur = intervals[0]
        for i in range(1, len(intervals)):
            if intervals[i][0] >= cur[1]:
                cur = intervals[i]
            elif intervals[i][1] < cur[0]:
                continue
            else:
                ret += 1
                cur[1] = min(intervals[i][1], cur[1])
        
        return ret