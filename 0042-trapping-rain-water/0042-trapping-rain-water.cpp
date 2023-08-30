class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        
        int left = 0, right = n - 1;
        int leftBar = height[left], rightBar = height[right];
        
        while (left <= right) {
            // Check which bar is the limiting bar - left or right
            if (leftBar < rightBar) {
                // If element that you are seeing now becomes the highest left,
                // it will not store any water
                if (height[left] > leftBar) {
                    leftBar = height[left];
                } else {
                    ans += leftBar - height[left];
                }
                left++;
            } else {
                // If element that you are seeing now becomes the highest right,
                // it will not store any water
                if (height[right] > rightBar) {
                    rightBar = height[right];
                } else {
                    ans += rightBar - height[right];
                }
                right--;
            }
        }
        
        return ans;
    }
};
