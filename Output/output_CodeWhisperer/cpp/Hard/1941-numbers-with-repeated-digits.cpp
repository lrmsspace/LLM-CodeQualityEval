/**https://leetcode.com/problems/numbers-with-repeated-digits/ */
//Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.
// 
//Example 1:
//Input: n = 20
//Output: 1
//Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.
//Example 2:
//Input: n = 100
//Output: 10
//Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
//Example 3:
//Input: n = 1000
//Output: 262
// 
//Constraints:
//	1 <= n <= 109
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        int res = 0;
        int num = n;
        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        int len = digits.size();
        for (int i = 1; i < len; i++) {
            res += 9 * A(len - 1, i - 1);
        }
        vector<bool> used(10, false);
        for (int i = len - 1; i >= 0; i--) {
            int d = digits[i];
            for (int j = i == len - 1 ? 1 : 0; j < d; j++) {
                if (!used[j]) {
                    res += A(len - 1 - i, len - 1 - i);
                }
            }
            if (used[d]) {
                break;
            }
            used[d] = true;
            if (i == 0) {
                res++;
            }
        }
        return n - res;
        
    }
};