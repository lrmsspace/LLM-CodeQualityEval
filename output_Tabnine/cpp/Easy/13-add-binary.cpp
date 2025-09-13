/**https://leetcode.com/problems/add-binary/ */
//Given two binary strings a and b, return their sum as a binary string.
// 
//Example 1:
//Input: a = "11", b = "1"
//Output: "100"
//Example 2:
//Input: a = "1010", b = "1011"
//Output: "10101"
// 
//Constraints:
//	1 <= a.length, b.length <= 104
//	a and b consist only of '0' or '1' characters.
//	Each string does not contain leading zeros except for the zero itself.
class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length(), m = b.length();
        string res(max(n, m) + 1, '0');
        int carry = 0;
        for (int i = n - 1, j = m - 1; i >= 0 || j >= 0; --i, --j) {
            int sum = carry + (i >= 0? a[i] - '0' : 0) + (j >= 0? b[j] - '0' : 0);
            res[max(i, j) + 1] = '0' + sum % 2;
            carry = sum / 2;
        }
        return carry == 0? res.substr(1) : res;
        
    }
};