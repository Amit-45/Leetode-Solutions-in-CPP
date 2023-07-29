class Solution {
public:

    int countPrimes(int n) {
        int ans = 0;
        vector<int>prime(n+2,0);
        prime[0] = 1;
        prime[1] = 1;
        for(int i = 2 ; i < n ; i++) {
            if(!prime[i]) {
                ++ans;
                for(int j = 2*i ; j < n ; j += i) {
                    prime[j] = 1;
                }
            }
        }
        return ans;
    }
};