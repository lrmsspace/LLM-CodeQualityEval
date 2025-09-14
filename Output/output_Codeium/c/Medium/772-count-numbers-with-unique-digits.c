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
    
    int res = 10;
    int uniqueDigits = 9;
    int availableNumber = 9;
    while (n > 0 && availableNumber > 0) {
        int cur = Math.Min(uniqueDigits, availableNumber);
        res += cur * (int)Math.Pow(10, n - 1);
        availableNumber -= cur;
        uniqueDigits--;
        n--;
    }
    return res;
}
