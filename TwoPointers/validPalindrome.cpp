#include<iostream>

using namespace std;

//approach 1
class Solution1 {
public:
    bool isPalindrome(string s) {
        
 int len = s.length();    

        int i = 0;
        int j = len - 1;

        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;



    }
};