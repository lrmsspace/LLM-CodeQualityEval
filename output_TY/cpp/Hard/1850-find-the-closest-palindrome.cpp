/**https://leetcode.com/problems/find-the-closest-palindrome/ */
//Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.
//The closest is defined as the absolute difference minimized between two integers.
// 
//Example 1:
//Input: n = "123"
//Output: "121"
//Example 2:
//Input: n = "1"
//Output: "0"
//Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
// 
//Constraints:
//	1 <= n.length <= 18
//	n consists of only digits.
//	n does not have leading zeros.
//	n is representing an integer in the range [1, 1018 - 1].
class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.length();
        if (len == 1) {
            return to_string(stoi(n) - 1);
        }
        string res = n;
        long long num = stoll(n);
        long long left = stoll(n.substr(0, (len + 1) / 2));
        long long left_palindrome = left;
        if (len % 2 == 1) {
            left_palindrome = left * 10 + left / 10;
        } else {
            left_palindrome = left * 10 + left / 10;
        }
        long long right = left;
        if (len % 2 ==1) {
            right = left / 10;
        }
        while (left_palindrome > 0) {
            string left_str = to_string(left_palindrome);
            string right_str = left_str;
            if (len % 2 == 1) {
                right_str += to_string(left / 10);
            }
            reverse(right_str.begin(), right_str.end());
            string palindrome = left_str + right_str;
            long long palindrome_num = stoll(palindrome);
            if (palindrome_num < num) {
                res = palindrome;
            }
            left_palindrome -= 9;
        }
        while (right > 0) {
            string left_str = to_string(right);
            string right_str = left_str;
            string palindrome = left_str + right_str;
            long long palindrome_num = stoll(palindrome);
            if (palindrome_num < num) {
                res = palindrome;
            }
            right -= 9;
        }
        if (n[0] == '1') {
            return "9";
        }
        for (int i = 0; i < len; i++) {
            if (n[i] != '9') {
                res[i] = '9';
                return res;
            }
        }
        return "9";
    }
};