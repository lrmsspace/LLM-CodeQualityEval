/**https://leetcode.com/problems/number-of-digit-one/ */
//Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
// 
//Example 1:
//Input: n = 13
//Output: 6
//Example 2:
//Input: n = 0
//Output: 0
// 
//Constraints:
//	0 <= n <= 109
class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        if (n < 10) return 1;
        int res = 0;
        string s = to_string(n);
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            int high = stoi(s.substr(0, i));
            int low = stoi(s.substr(i + 1));
            int cur = s[i] - '0';
            if (cur == 0) res += high * pow(10, len - i - 1);
            else if (cur == 1) res += high * pow(10, len - i - 1) + low + 1;
            else res += (high + 1) * pow(10, len - i - 1);
        }
        return res;        
    }
};