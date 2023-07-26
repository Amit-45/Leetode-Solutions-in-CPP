class Solution {
public:
     vector<int> prev(vector<int> v,int n){
         vector<int> ans(n);
         stack<int> s;
         s.push(-1);
         for(int i=0;i<n;i++){
        int curr=v[i];
        while(s.top()!=-1 && v[s.top()]>=curr){
            s.pop();
        }
        //top me hi ans h;
         ans[i]=s.top();
         s.push(i);
         }
         return ans;
     }

     vector<int> next(vector<int> v,int n){
         vector<int> ans(n);
         stack<int> s;
           s.push(-1);
         for(int i=n-1;i>=0;i--){
        int curr=v[i];
        while(s.top()!=-1 && v[s.top()]>=curr){
            s.pop();
        }
        //top me hi ans h;
         ans[i]=s.top();
         s.push(i);
         }
         return ans;
     }

    int maxHisto(vector<int> v){
        int nt=v.size();
        vector<int> p(nt);
        p=prev(v,nt);
        vector<int> n(nt);
        n=next(v,nt);
        int sum=INT_MIN;
        for(int i=0;i<nt;i++){
          if(n[i]==-1){
              n[i]=nt;
          }
        int a= v[i]*(n[i]-p[i]-1);
        sum=max(a,sum);
        }
        return sum;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
       vector<vector<int>> v(matrix.size());
       for(int i=0;i<matrix.size();i++){
           for(int j=0;j<matrix[i].size();j++){
               if(matrix[i][j]=='0')
  v[i].push_back(0);
  else v[i].push_back(1);
           }
       } 
       int first= maxHisto(v[0]);
     for(int i=1;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]!=0){
                v[i][j]=v[i-1][j]+v[i][j];
            }
            else v[i][j]=0;
        }
        int a=  maxHisto(v[i]);
        first= max(first,a);
     }
return first;
    }
};