class Solution {
public:
    int brokenCalc(int i, int j) {
        if(i>=j){
            return (i-j);
        }
        if(j%2){
            return 1+brokenCalc(i,j+1);
        }
        else{
            return 1+brokenCalc(i,(j>>1));
        }
        return 0;
    }
};