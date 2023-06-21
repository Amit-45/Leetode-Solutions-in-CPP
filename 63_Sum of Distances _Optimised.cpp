class Solution {
public:
    vector<long long> distance(vector<int>& a) {
        int n = (int)a.size();
        map<long long, long long>mp;
        map<long long,long long>h;
        vector<long long>ans(n,0);
        for(int i = 0 ; i < n ; i++) {
            long long have = h[a[i]];
            long long score = (have * i) - (mp[a[i]]);
            ans[i] += score;
            h[a[i]]++;
            mp[a[i]] += i;
        }
        mp.clear();
        h.clear();
        for(int i = n-1 ; i >= 0 ; i--) {
            long long have = h[a[i]];
            long long score = (have * i) - (mp[a[i]]);
            ans[i] += abs(score);
            h[a[i]]++;
            mp[a[i]] += i;
        }
        return ans;
    }
};
