class Solution {
public:
    bool ok(int x, vector<int> &a) {
        long long remove = 0;
        for(auto t : a) {
         if(t < x) {
            remove += (x-t);
         } else {
            int need = (t - x);
            if(need > remove) return 0;
            remove -= need;
         }
        }
        return 1;
    }
    int minimizeArrayValue(vector<int>& a) {
      int l = -1;
      int r = 1e9;
      while(r > l + 1) {
        int m = (l+r) >> 1;
        if(ok(m,a)) {
          r = m;
        } else  {
          l = m;
        }
      }
      return r;
    }
};