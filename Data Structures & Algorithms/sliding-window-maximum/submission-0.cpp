class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if (k > nums.size()) return ret;
        int l = 0, r = l + k;

        while (r <= nums.size()) {
            vector<int> tmpList;
            for (int i = l; i < l + k; i++) {
                tmpList.push_back(nums[i]);
            }

            auto maxPair = max_element(tmpList.begin(), tmpList.end());
            int maxNum = *maxPair;
            ret.push_back(maxNum);
            l++;
            r++;
        }

        return ret;
    }
};
