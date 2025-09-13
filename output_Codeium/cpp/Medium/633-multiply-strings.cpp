/**https://leetcode.com/problems/multiply-strings/ */
//Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
// 
//Example 1:
//Input: num1 = "2", num2 = "3"
//Output: "6"
//Example 2:
//Input: num1 = "123", num2 = "456"
//Output: "56088"
// 
//Constraints:
//	1 <= num1.length, num2.length <= 200
//	num1 and num2 consist of digits only.
//	Both num1 and num2 do not contain any leading zero, except the number 0 itself.
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()) return "0";
        int n1 = num1.size(), n2 = num2.size();
        vector<int> pos(n1 + n2, 0);
        for (int i = n1 - 1; i >= 0; --i) {
            for (int j = n2 - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + pos[p2];

                pos[p1] += sum / 10;
                pos[p2] = sum % 10;
            }
        }
        int idx = 0;
        while (idx < pos.size() && pos[idx] == 0) ++idx;
        if (idx == pos.size()) return "0";
        string res;
        while (idx < pos.size()) res += to_string(pos[idx++]);
        return res;
    }
};