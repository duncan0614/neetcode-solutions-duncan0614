class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> minHeap;
        for (int stone : stones) {
            minHeap.push(stone);
        }

        while (minHeap.size() > 1) {
            int x = minHeap.top();
            minHeap.pop();
            int y = minHeap.top();
            minHeap.pop();

            if (x == y) {
                minHeap.push(0);
            }
            else{
                int z = abs(x - y);
                minHeap.push(z);
            }
        }
        return minHeap.top();
    }
};
