/**https://leetcode.com/problems/largest-palindromic-number/ */
//You are given a string num consisting of digits only.
//Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. It should not contain leading zeroes.
//Notes:
//	You do not need to use all the digits of num, but you must use at least one digit.
//	The digits can be reordered.
// 
//Example 1:
//Input: num = "444947137"
//Output: "7449447"
//Explanation: 
//Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
//It can be shown that "7449447" is the largest palindromic integer that can be formed.
//Example 2:
//Input: num = "00009"
//Output: "9"
//Explanation: 
//It can be shown that "9" is the largest palindromic integer that can be formed.
//Note that the integer returned should not contain leading zeroes.
// 
//Constraints:
//	1 <= num.length <= 105
//	num consists of digits.
class Solution {
public:
    string largestPalindromic(string num) {
        int n = num.size();
        vector<int> freq(10, 0);
        for (int i = 0; i < n; i++) freq[num[i] - '0']++;
        string ans = "";
        int mid = -1;
        for (int i = 9; i >= 0; i--) {
            if (freq[i] % 2 == 0) {
                string s(freq[i] / 2, '0' + i);
                ans += s;
            }
            else {
                if (mid == -1) {
                    mid = i;
                    string s(freq[i] / 2, '0' + i);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        if (mid != -1) ans += '0' + mid;
        for (int i = 9; i >= 0; i--) {
            if (freq[i] % 2 == 1) {
                string s(freq[i] / 2, '0' + i);
                ans += s;
            }
        }
        return ans;
    }
};