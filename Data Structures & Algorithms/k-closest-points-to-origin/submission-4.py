class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        dis = []

        for item in points:
            tmp = item[0]**2 + item[1]**2
            heapq.heappush(dis, [-tmp, item])

            if len(dis) > k:
                heapq.heappop(dis)
        
        return [p for d, p in dis]

            