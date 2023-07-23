class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes[0].size();
        vector<vector<int>> v(26,vector<int>(n));
        string res = votes[0];
        
        for(auto i : votes){
            for(int j=0;j<n;j++){
                v[i[j]-'A'][j]++; // adding the values
            }
        }
        
        sort(res.begin(),res.end(),[=](int a, int b){
            if(v[a-'A'] == v[b - 'A']) return a<b; //a
            return v[a-'A'] > v[b-'A'];
            
        });
        return res;
    }
};

