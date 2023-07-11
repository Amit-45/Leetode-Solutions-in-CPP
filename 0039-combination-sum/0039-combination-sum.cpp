class Solution {
    void combination(vector<int>& nums, int target, vector<int> currComb, int currSum, int currIndex, vector<vector<int>>& result) {
        if (currSum > target)
            return;
        if (currSum == target) {
            result.push_back(currComb);
            return;
        }
        
        for (int i = currIndex; i < nums.size(); i++) {
            currComb.push_back(nums[i]);
            currSum += nums[i];
            combination(nums, target, currComb, currSum, i, result);
            currComb.pop_back();
            currSum -= nums[i];
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currComb;
        combination(candidates, target, currComb, 0, 0, result);
        return result;
    }
};
