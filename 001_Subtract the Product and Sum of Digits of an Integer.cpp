Link to the problem - https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0;
        int prod=1;
        while(n!=0){
        int last=n%10;
        sum=sum+last;
        prod=prod*last;
        n=n/10;
        }

      return prod-sum;   
    }
};
