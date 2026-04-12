class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize){
            return false;
        }
        unordered_map<int, int> numMap;
        for (const auto& num : hand){
            numMap[num] += 1;
        }

        priority_queue<int, vector<int>, greater<>> minHeap;
        for (auto& pair : numMap){
            minHeap.push(pair.first);
        }

        while (!minHeap.empty()){
            int first = minHeap.top();
            for (int i = first; i < first + groupSize; i++){
                if (numMap.find(i) == numMap.end()){
                    return false;
                }

                numMap[i] -= 1;
                if (numMap[i] == 0){
                    if (i != minHeap.top()){
                        return false;
                    }
                    minHeap.pop();
                }
            }
        }
        return true;
    }
};
