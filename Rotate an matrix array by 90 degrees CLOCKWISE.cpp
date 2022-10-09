https://leetcode.com/problems/rotate-image/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
         //transpose 
         int n =matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)     //diagonal elements 
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //swap columns
        for(int i=0;i<n;i++)               
        {
            for(int j=0;j<n/2;j++)    
            {
                swap(matrix[i][j],matrix[i][n-1-j]); // inddex pair of j for swap=n-1-j
            }
        }
    }
};
