class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        for (int& num:nums) {
            maxHeap.push(num);
        }
        
        int ret = 0;
        while (k > 0) {
            ret = maxHeap.top();
            maxHeap.pop();
            k--;
        }

        return ret;
    }
};
