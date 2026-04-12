class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int lIndex = 0, rIndex = heights.size() - 1;

        while (lIndex < rIndex){
            
            int tempArea = 0;
            if (heights[lIndex] >= heights[rIndex]){
                tempArea = heights[rIndex] * (rIndex - lIndex);
                rIndex--;
            }
            else{
                tempArea = heights[lIndex] * (rIndex - lIndex);
                lIndex++;
            }

            if (tempArea > maxArea){
                maxArea = tempArea;
            }

        }
        
        return maxArea;
    }
};
