class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;

        if (height.size() == 0){
            return ret;
        }

        int lIndex = 0, rIndex = height.size() - 1;
        int theMostLeft = height[lIndex], theMostRight = height[rIndex];

        while (lIndex < rIndex){
            if (theMostLeft < theMostRight){
                lIndex++;
                theMostLeft = max(theMostLeft, height[lIndex]);
                ret += theMostLeft - height[lIndex];
            }
            else{
                rIndex--;
                theMostRight = max(theMostRight, height[rIndex]);
                ret += theMostRight - height[rIndex];
            }
        }
        
        return ret;
    }
};
