class Solution {
public:
    int sum(int num1, int num2) {
        int newint = num1;
        int newint2 = num2;

        if(newint2 > 0)
        {
            for(int i = 1; i <= newint2; i++)
            {
            newint++;
            }
        }
        else
        {
            for(int i = 1; i <= abs(newint2); i++)
            {
            newint--;
            }
        }
        
        return newint;
    }
};