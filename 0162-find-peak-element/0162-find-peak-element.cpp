class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // The peak element is on the right side
                low = mid + 1;
            } else {
                // The peak element is on the left side or at mid index
                high = mid;
            }
        }

        return low;
    }
};
