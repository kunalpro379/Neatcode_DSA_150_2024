//dynamic siding window
//Example
/*Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc",
 with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", 
with the length of 1.*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> visited(256, false);

        if (s.length() == 0)
            return 0;

        if (s.length() == 1)
            return 1;

        int left = 0, right = 0;
        int maxLength = 0;

        while (right < s.length()) {
            if (visited[s[right]] == true) {
                while (visited[s[right]] == true) {
                    visited[s[left]] = false;
                    left++;
                }
            }

            visited[s[right]] = true;
            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};


