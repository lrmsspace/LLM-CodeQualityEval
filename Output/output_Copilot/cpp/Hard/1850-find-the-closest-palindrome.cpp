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
        long num = stol(n);
        if (num == 0) return "1";
        if (num == 1) return "0";
        long ans = num - 1;
        long diff = num - 1;
        if (num % 10 == 0) {
            long temp = num;
            while (temp % 10 == 0) {
                temp /= 10;
            }
            if (temp == 1 && num / 10 != 0) {
                ans = num - 1;
                diff = num - 1;
            }
        }
        long temp = num;
        long temp2 = 0;
        while (temp) {
            temp2 = temp2 * 10 + temp % 10;
            temp /= 10;
        }
        if (temp2 != num) {
            if (abs(temp2 - num) < diff) {
                ans = temp2;
                diff = abs(temp2 - num);
            } else if (abs(temp2 - num) == diff) {
                ans = min(ans, temp2);
            }
        }
        temp = num;
        temp2 = 0;
        while (temp) {
            temp2 = temp2 * 10 + temp % 10;
            temp /= 10;
        }
        if (temp2 != num) {
            if (abs(temp2 - num) < diff) {
                ans = temp2;
                diff = abs(temp2 - num);
            } else if (abs(temp2 - num) == diff) {
                ans = min(ans, temp2);
            }
        }
        temp = num;
        temp2 = 0;
        while (temp) {
            temp2 = temp2 * 10 + temp % 10;
            temp /= 10;
        }
        if (temp2 != num) {
            if (abs(temp2 - num) < diff) {
                ans = temp2;
                diff = abs(temp2 - num);
            } else if (abs(temp2 - num) == diff) {
                ans = min(ans, temp2);
            }
        }
        return to_string(ans);        
    }
};