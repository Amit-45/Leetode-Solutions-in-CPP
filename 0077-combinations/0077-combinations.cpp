class Solution {
public:

    void solve(int n , int k , vector<vector<int>> &ans , vector<int>&a) {
        if(k == 0) {
         ans.push_back(a);
         return;
        }
        if(n == 0) {
          return;
        }
        solve(n-1,k,ans,a);
        a.push_back(n);
        solve(n-1,k-1,ans,a);
        a.pop_back();
    }  

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>a;
        solve(n,k,ans,a);
        return ans;
    }
};