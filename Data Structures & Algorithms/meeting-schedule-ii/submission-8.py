"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        intervals.sort(key = lambda i : i.start)
        
        ret = []
        for interval in intervals:
            if ret and ret[0] <= interval.start:
                heapq.heappop(ret)
            heapq.heappush(ret, interval.end)

        return len(ret)
                