class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        int N = 9;
        vector<int>a = {1,2,3,4,5,6,7,8,9};
        for(int i = 0 ; i < (1 << N) ; i++) {
           int sum = 0;
           vector<int>b;
           for(int j = 0 ; j < N ; j++) {
               if(((1 << j) & i)) {
                   sum += a[j];
                   b.push_back(a[j]);
               } 
           }
           if((int)b.size() == k && sum == n) {
               ans.push_back(b);
           }
        }
        return ans;
    }
};
