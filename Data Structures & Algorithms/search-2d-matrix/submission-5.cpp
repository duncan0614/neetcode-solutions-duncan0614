class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& r : matrix){
            if (r[r.size() - 1] == target){
                return true;
            }
            else if(r[r.size() - 1] < target) {
                continue;
            }
            else{
                int lIndex = 0, rIndex = r.size() - 1;
                while (lIndex <= rIndex){
                    int mid = ((rIndex - lIndex) / 2) + lIndex;
                    if (r[mid] == target){
                        return true;
                    }
                    else if (r[mid] > target){
                        rIndex = mid - 1;
                    }
                    else{
                        lIndex = mid + 1;
                    }
                }
                
            }
        }

        return false;
    }
};
