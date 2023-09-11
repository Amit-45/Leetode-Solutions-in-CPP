#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int firstOccurrence = findBound(nums, target, true);

        if (firstOccurrence == -1) {
            return {-1, -1};
        }

        int lastOccurrence = findBound(nums, target, false);

        return {firstOccurrence, lastOccurrence};
    }

private:
    int findBound(std::vector<int>& nums, int target, bool isFirst) {
        int N = nums.size();
        int begin = 0, end = N - 1;

        while (begin <= end) {
            int mid = (begin + end) / 2;

            if (nums[mid] == target) {
                if (isFirst) {
                    // This means we found our lower bound.
                    if (mid == begin || nums[mid - 1] != target) {
                        return mid;
                    }
                    // Search on the left side for the bound.
                    end = mid - 1;
                } else {
                    // This means we found our upper bound.
                    if (mid == end || nums[mid + 1] != target) {
                        return mid;
                    }
                    // Search on the right side for the bound.
                    begin = mid + 1;
                }
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }

        return -1;
    }
};
