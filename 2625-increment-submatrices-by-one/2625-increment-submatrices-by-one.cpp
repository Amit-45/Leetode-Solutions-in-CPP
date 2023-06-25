class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    vector<vector<int>> temp(n + 2, vector<int>(n + 2, 0));
    for (auto& it : queries) {
        int x1 = it[0], y1 = it[1], x2 = it[2], y2 = it[3];
        x1++;
        y1++;
        x2++;
        y2++;
        for (int i = x1; i <= x2; i++) {
            temp[i][y1] ++;
            temp[i][y2 + 1] --;
        }
    }

    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++) {
        vector<int> v;
        int s = 0;
        for (int j = 1; j <= n; ++j) {
            s += temp[i][j];
            v.push_back(s);
        }
        ans.push_back(v);
    }

    return ans;
}

};
