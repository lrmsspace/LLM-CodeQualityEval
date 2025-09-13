/**https://leetcode.com/problems/ugly-number-iii/ */
//An ugly number is a positive integer that is divisible by a, b, or c.
//Given four integers n, a, b, and c, return the nth ugly number.
// 
//Example 1:
//Input: n = 3, a = 2, b = 3, c = 5
//Output: 4
//Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
//Example 2:
//Input: n = 4, a = 2, b = 3, c = 4
//Output: 6
//Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.
//Example 3:
//Input: n = 5, a = 2, b = 11, c = 13
//Output: 10
//Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.
// 
//Constraints:
//	1 <= n, a, b, c <= 109
//	1 <= a * b * c <= 1018
//	It is guaranteed that the result will be in range [1, 2 * 109].
int nthUglyNumber(int n, int a, int b, int c){
    int l = 1, r = 2e9;
    while (l < r) {
        int m = (l + r) / 2;
        if (m / a + m / b + m / c - m / (a * b / __gcd(a, b)) - m / (a * c / __gcd(a, c)) - m / (b * c / __gcd(b, c)) + m / (a* b * c / __gcd(a, b, c))) >= n) r = m;
        else l = m + 1;
    }
    return l;
}