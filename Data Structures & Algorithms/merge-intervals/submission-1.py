class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ret = []
        intervals.sort(key = lambda x : x[0])

        curInterval = intervals[0]
        for i in range(1, len(intervals)):
            if intervals[i][0] > curInterval[1]:
                ret.append(curInterval)
                curInterval = intervals[i]
            elif intervals[i][1] < curInterval[0]:
                ret.append(intervals[i])
            else:
                curInterval = [min(intervals[i][0], curInterval[0]), max(intervals[i][1], curInterval[1])]
        
        ret.append(curInterval)
        return ret
        