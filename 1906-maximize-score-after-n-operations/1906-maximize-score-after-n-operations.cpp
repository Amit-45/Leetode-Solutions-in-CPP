class Solution {
    int gcd(int n1, int n2) {
        while (n1 % n2 != 0) {
            int rem = n1 % n2;
            n1 = n2;
            n2 = rem;
        }
        return n2;
    }

    int helper(vector<int>& nums, int mask, unordered_map<int, int>& cache, int op) {
        if (cache.count(mask) == 1)
            return cache[mask];
        cache[mask] = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if ((1 << i) & mask || (1 << j) & mask)
                    continue;
                int score = op * gcd(nums[i], nums[j]);
                int newMask = mask | (1 << i) | (1 << j);
                cache[mask] = max(cache[mask], score + helper(nums, newMask, cache, op + 1));
            }
        }
        return cache[mask];
    }

public:
    int maxScore(vector<int>& nums) {
        unordered_map<int, int> cache;
        return helper(nums, 0, cache, 1);
    }
};
