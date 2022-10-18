#include <string>
#include <algorithm>
class Solution {
public:
        char toLower(char c)
        {
            return 'a' + (c - 'A');
        }
    
    bool isPalindrome(string s)
     {
           // RemoveSpecialCharactersAndSpaces
                    string str;
                    for (int i = 0; i < s.size(); i++)
                    {
                    if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
                    {
                        str.push_back(s[i]);
                    }
                    }
            // palindrome logic(2 pointers)
                    int start = 0;

                    int end = str.size() - 1;

                    while (start <= end)
                    {
                    if (tolower(str[start]) != tolower(str[end]))
                        return false;
                    else
                    {
                        start++;
                        end--;
                    }
                    }
                    return true;
        
     }
     
    
};
