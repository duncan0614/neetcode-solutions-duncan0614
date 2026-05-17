class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        charLastIdx = {}
        for i, v in enumerate(s):
            charLastIdx[v] = i

        ret = []
        size, end = 0, 0
        for i, v in enumerate(s):
            size += 1
            end = max(end, charLastIdx[v])

            if end == i:
                ret.append(size)
                size = 0
        
        return ret
                