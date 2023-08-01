class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        int N = n;
        n += 3;
        vector<int>prime(n,0);
        prime[0] = 1;
        prime[1] = 1;
        for(int i = 2 ; i < n ; i++) {
          if(!prime[i]) {
            for(int j = 2*i ; j < n ; j += i) {
                prime[j] = 1;
            }
          }
        }
        vector<vector<int>>ans;
        for(int i = 2 ; i <= N ; i++) {
            if(!prime[i] && !prime[N-i] && i >= N-i) {
                ans.push_back({N-i,i});
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};