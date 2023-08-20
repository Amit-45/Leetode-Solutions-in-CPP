class Solution {
private:
    void generateSubsets(int index, const vector<int>& nums, vector<int>& curr, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(curr);
            return;
        }

        generateSubsets(index + 1, nums, curr, result); // Exclude current element

        curr.push_back(nums[index]); // Include current element
        generateSubsets(index + 1, nums, curr, result);
        curr.pop_back(); // Backtrack
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans1;
        vector<int> curr;
        generateSubsets(0, nums, curr, ans1);
        return ans1;
    }
};