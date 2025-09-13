/**https://leetcode.com/problems/find-longest-awesome-substring/ */
//You are given a string s. An awesome substring is a non-empty substring of s such that we can make any number of swaps in order to make it a palindrome.
//Return the length of the maximum length awesome substring of s.
// 
//Example 1:
//Input: s = "3242415"
//Output: 5
//Explanation: "24241" is the longest awesome substring, we can form the palindrome "24142" with some swaps.
//Example 2:
//Input: s = "12345678"
//Output: 1
//Example 3:
//Input: s = "213123"
//Output: 6
//Explanation: "213123" is the longest awesome substring, we can form the palindrome "231132" with some swaps.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists only of digits.
class Solution {
public:
    int longestAwesome(string s) {
        int n = s.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                string sub = s.substr(i, j-i);
                int count[10] = {0};
                for (char c: sub)
                    count[c-'0']++;
                int odd = 0;
                for (int k = 0; k < 10; ++k) {
                    if (count[k] % 2 == 1)
                        odd++;
                    if (odd > 1)
                        break;
                }
                if (odd <= 1)
                    res = max(res, j - i);
            }
        }
        return res;
    }
};