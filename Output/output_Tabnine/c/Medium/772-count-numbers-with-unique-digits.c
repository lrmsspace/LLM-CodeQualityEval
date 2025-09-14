/**https://leetcode.com/problems/count-numbers-with-unique-digits/ */
//Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.
// 
//Example 1:
//Input: n = 2
//Output: 91
//Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99
//Example 2:
//Input: n = 0
//Output: 1
// 
//Constraints:
//	0 <= n <= 8
int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1;
    int res = 10; // 10 unique digits from 0-9
    int uniqueDigits = 9; // 9 digits excluding 0
    int availableDigits = 9; // 9 digits to choose from
    
    for (int i = 1; i < n; i++) {
        availableDigits *= uniqueDigits--; // Reduce the number of available digits for each digit
        res += availableDigits; // Add the number of combinations for the current digit
    }
    
    return res;
    
}