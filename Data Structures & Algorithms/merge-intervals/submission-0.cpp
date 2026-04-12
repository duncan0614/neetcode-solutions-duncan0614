class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int maxNum = 0;

        for (const auto& p : intervals) {
            maxNum = max(p[0], maxNum);
        }

        vector<int> newInterval(maxNum + 1, 0);
        for (const auto& p : intervals){
            int start = p[0];
            int end = p[1];
            newInterval[start] = max(end + 1, newInterval[start]);
        }

        vector<vector<int>> ret;
        int have = -1;
        int intervalStart = -1;
        for (int i = 0; i < newInterval.size(); i++) {
            if (newInterval[i] != 0) {
                if (intervalStart == -1) intervalStart = i;
                have = max(newInterval[i] - 1, have);
            }

            if (have == i) {
                ret.push_back({intervalStart, have});
                have = -1;
                intervalStart = -1;
            }
        }

        if (intervalStart != -1) {
            ret.push_back({intervalStart, have});
        }
        return ret;
    }
};
