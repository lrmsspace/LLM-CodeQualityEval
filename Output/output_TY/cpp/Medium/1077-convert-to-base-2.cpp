/**https://leetcode.com/problems/convert-to-base-2/ */
//Given an integer n, return a binary string representing its representation in base -2.
//Note that the returned string should not have leading zeros unless the string is "0".
// 
//Example 1:
//Input: n = 2
//Output: "110"
//Explantion: (-2)2 + (-2)1 = 2
//Example 2:
//Input: n = 3
//Output: "111"
//Explantion: (-2)2 + (-2)1 + (-2)0 = 3
//Example 3:
//Input: n = 4
//Output: "100"
//Explantion: (-2)2 = 4
// 
//Constraints:
//	0 <= n <= 109
class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        string ans;
        while (n) {
            if (n % 2 == 1) {
                ans = "1" + ans;
                n -= 3;
            }
            else {
                ans = "0" + ans;
                n /= -2;
            }
        }
        return ans;
    }
};