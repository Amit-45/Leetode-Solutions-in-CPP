class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        const int MOD = 1e9 + 7; 

        int low = 0;
        int high = numbers.size() - 1;
        while (low < high) {
            int sum = (numbers[low] % MOD + numbers[high] % MOD) % MOD;
                          
            if (sum == target) {
                return {low + 1, high + 1};
            } else if (sum < target) {
                ++low;
            } else {
                --high;
            }
        }
        // In case there is no solution, return {-1, -1}.
        return {-1, -1};
    }
};
