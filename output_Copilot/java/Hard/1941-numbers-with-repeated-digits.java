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
    public int numDupDigitsAtMostN(int n) {
        String s = String.valueOf(n);
        int len = s.length();
        int ans = 0;
        for (int i = 1; i < len; i++) {
            ans += 9 * permutation(9, i - 1);
        }
        boolean[] visited = new boolean[10];
        for (int i = 0; i < len; i++) {
            int curDigit = s.charAt(i) - '0';
            for (int j = (i == 0 ? 1 : 0); j < curDigit; j++) {
                if (!visited[j]) {
                    ans += permutation(9 - i, len - i - 1);
                }
            }
            if (visited[curDigit]) {
                break;
            }
            visited[curDigit] = true;
        }
        return n - ans;        
    }
}