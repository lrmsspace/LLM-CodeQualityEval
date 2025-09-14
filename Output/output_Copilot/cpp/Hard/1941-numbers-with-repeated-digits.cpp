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
        vector<int> digits;
        for (int i = n + 1; i > 0; i /= 10) {
            digits.push_back(i % 10);
        }
        reverse(digits.begin(), digits.end());
        int len = digits.size();
        int res = 0;
        for (int i = 1; i < len; i++) {
            res += 9 * A(9, i - 1);
        }
        unordered_set<int> s;
        for (int i = 0; i < len; i++) {
            for (int j = i > 0 ? 0 : 1; j < digits[i]; j++) {
                if (s.count(j)) {
                    continue;
                }
                res += A(9 - i, len - i - 1);
            }
            if (s.count(digits[i])) {
                break;
            }
            s.insert(digits[i]);
        }
        return n - res;        
    }
};