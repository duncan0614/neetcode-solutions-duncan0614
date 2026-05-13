class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False
        
        numHash = {}
        for num in hand:
            numHash[num] = 1 + numHash.get(num, 0)
        
        numHeap = list(numHash.keys())
        heapq.heapify(numHeap)
        while numHeap:
            start = numHeap[0]
            for i in range(start, start + groupSize):
                if i not in numHash:
                    return False

                numHash[i] -= 1
                if numHash[i] == 0:
                    if numHeap[0] != i:
                        return False
                    heapq.heappop(numHeap)
        
        return True
