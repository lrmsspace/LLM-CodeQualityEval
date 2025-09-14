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
int numDupDigitsAtMostN(int n) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        int num = i;
        bool seen[10] = {false};
        bool dup = false;
        while (num > 0) {
            int digit = num % 10;
            if (seen[digit]) {
                dup = true;
                break;
            }
            seen[digit] = true;
            num /= 10;
        }
        if (dup) {
            ++count;
        }
    }
    return count;
}