class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        dis = []

        for item in points:
            tmp = item[0]**2 + item[1]**2
            dis.append([-tmp, item])
            heapq.heapify(dis)

            if len(dis) > k:
                heapq.heappop(dis)
        
        return [p for d, p in dis]

            