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
        string res;
        int carry = 0;
        for(int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0 || carry; i--, j--){
            int x = i < 0 ? 0 : a[i] - '0';
            int y = j < 0 ? 0 : b[j] - '0';
            int sum = x + y + carry;
            res.push_back(sum %2 + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};