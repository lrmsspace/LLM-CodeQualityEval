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
import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;
class Solution {
    public int numDupDigitsAtMostN(int n) {
        List<Integer> digits = new ArrayList<>();
        for (int x = n + 1; x > 0; x /= 10) {
            digits.add(0, x % 10);
        }
        int res = 0, k = digits.size();
        for (int i = 1; i < k; ++i) {
            res += 9 * A(9, i - 1);
        }
        Set<Integer> seen = new HashSet<>();
        for (int i = 0; i < k; ++i) {
            for (int j = i > 0 ? 0 : 1; j < digits.get(i); ++j) {
                if (!seen.add(j)) continue;
                res += A(9 - i, k - i - 1);
            }
            if (!seen.add(digits.get(i))) break;
        }
        return n - res;     
    }
}