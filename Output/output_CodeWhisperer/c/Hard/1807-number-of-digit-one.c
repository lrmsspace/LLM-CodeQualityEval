/**https://leetcode.com/problems/number-of-digit-one/ */
//Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
// 
//Example 1:
//Input: n = 13
//Output: 6
//Example 2:
//Input: n = 0
//Output: 0
// 
//Constraints:
//	0 <= n <= 109
int countDigitOne(int n) {
    if (n <= 0) return 0;
    int res = 0;
    long long i = 1;
    for (; i <= n; i *= 10) {
        int a = n / i, b = n % i;
        res += (a + 8) / 10 * i + (a % 10 == 1) * (b + 1);
    }
    return res;
    
}