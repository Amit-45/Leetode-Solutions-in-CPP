class Solution {
public:

    void dfs(int x , vector<int>&vis, vector<vector<int>>&a) {
     vis[x] = 1;
     for(auto u : a[x]) {
        if(!vis[u]) {
          dfs(u,vis,a);
        }
     }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if((int)connections.size() <  n - 1) return -1;
        vector<vector<int>>a(n);
        for(auto x : connections) {
            a[x[0]].push_back(x[1]);
            a[x[1]].push_back(x[0]);
        }
        int cc = 0;
        vector<int>vis(n,0);
        for(int i = 0 ; i < n ; i++) {
         if(!vis[i]) {
           dfs(i,vis,a);
           cc++;
         }
        }
        return cc-1;
    }
};