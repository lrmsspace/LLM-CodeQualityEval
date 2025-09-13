/*
 You are given a string num which represents a positive integer, and an integer t.
 A number is called zero-free if none of its digits are 0.
 Return a string representing the smallest zero-free number greater than or equal to num such that the product of its digits is divisible by t. If no such number exists, return "-1".
 Example 1:
 Input: num = "1234", t = 256
 Output: "1488"
 Explanation:
 The smallest zero-free number that is greater than 1234 and has the product of its digits divisible by 256 is 1488, with the product of its digits equal to 256.
 Example 2:
 Input: num = "12355", t = 50
 Output: "12355"
 Explanation:
 12355 is already zero-free and has the product of its digits divisible by 50, with the product of its digits equal to 150.
 Example 3:
 Input: num = "11111", t = 26
 Output: "-1"
 Explanation:
 No number greater than 11111 has the product of its digits divisible by 26.
 Constraints:
 2 <= num.length <= 2 * 105
 num consists only of digits in the range ['0', '9'].
 num does not contain leading zeros.
 1 <= t <= 1014
*/

class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long product = 1;
        for (char c : num) {
            if (c != '0') {
                product *= (c - '0');
            }
        }

        if (product % t == 0) {
            return num; // Already zero-free and divisible by t
        }

        // Try to find the smallest zero-free number greater than or equal to num
        for (int i = num.size() - 1; i >= 0; --i) {
            for (char c = '1'; c <= '9'; ++c) {
                if (c > num[i]) {
                    string candidate = num.substr(0, i) + c;
                    while (candidate.size() < num.size()) {
                        candidate += '1'; // Fill with smallest digit
                    }
                    if (isZeroFree(candidate) && productOfDigits(candidate) % t == 0) {
                        return candidate;
                    }
                }
            }
        }

        return "-1"; // No valid number found
        
    }
};