/**https://leetcode.com/problems/monotone-increasing-digits/ */
//An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.
//Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.
// 
//Example 1:
//Input: n = 10
//Output: 9
//Example 2:
//Input: n = 1234
//Output: 1234
//Example 3:
//Input: n = 332
//Output: 299
// 
//Constraints:
//	0 <= n <= 109
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int len = s.length(), marker = len;
        for (int i = len - 1; i > 0; --i) {
            if (s[i] < s[i - 1]) {
                marker = i;
                s[i - 1]--;
            }
        }
        for (int i = marker; i < len; ++i) {
            s[i] = '9';
        }
        return stoi(s);

    }
};