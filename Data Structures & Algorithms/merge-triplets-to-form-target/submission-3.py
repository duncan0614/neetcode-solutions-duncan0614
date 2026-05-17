class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        ret = set()

        for item in triplets:
            if item[0] > target[0] or item[1] > target[1] or item[2] > target[2]:
                continue
            
            for i, v in enumerate(item):
                if v == target[i]:
                    ret.add(i)
        
        return len(ret) == 3