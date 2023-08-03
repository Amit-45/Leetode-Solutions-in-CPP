class Solution {
public:
    bool checkInclusion(string s, string t) {
        int n = (int)s.size();
        int m = (int)t.size();
        vector<int>cnt(26,0);
        for(int i = 0 ; i < n ; i++) {
            cnt[s[i]-'a']++;
        }
        vector<int>cnt2(26,0);
        int l = 0;
        bool ok = 0;
        for(int r = 0 ; r < m ; r++) {
          cnt2[t[r]-'a']++;
          if(r >= n) {
            cnt2[t[l]-'a']--;
            l++;
          }
          bool good = 1;
          for(int i = 0 ; i < 26 ; i++) {
            if(cnt[i] != cnt2[i]) good = 0;
          }
          if(good) ok  = 1;
        }
        return ok;
    }
};
