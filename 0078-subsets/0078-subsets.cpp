class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        generateSubsets(0, nums, curr, result);
        return result;
    }

private:
    void generateSubsets(int index, const vector<int>& nums, vector<int>& curr, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(curr);
            return;
        }
        
        // Exclude current element
        generateSubsets(index + 1, nums, curr, result);
        
        // Include current element
        curr.push_back(nums[index]);
        generateSubsets(index + 1, nums, curr, result);
        curr.pop_back(); // Backtrack
    }
};