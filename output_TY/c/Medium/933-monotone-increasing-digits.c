/**https://leetcode.com/problems/monotone-increasing-digits/ */
//An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.
//Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.
// 
//Example 1:
//Input: n = 10
//Output: 9
//Example 2:
//Input: n = 1234
//Output: 1234
//Example 3:
//Input: n = 332
//Output: 299
// 
//Constraints:
//	0 <= n <= 109
int monotoneIncreasingDigits(int n){
    int i, j, k, l, m, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
    i = n / 100000000;
    j = (n - i * 100000000) / 10000000;
    k = (n - i * 100000000 - j * 10000000) / 1000000;
    l = (   n - i * 100000000 - j * 10000000 - k * 1000000) / 100000;
    m = (n - i * 100000000 - j * 10000000 - k * 1000000 - l * 100000) / 10000;
    n1 = (n - i * 100000000 - j * 10000000 - k * 1000000 - l * 100000 - m * 10000) / 1000;
    n2 = (n - i * 100000000 - j * 10000000 - k * 1000000 - l * 100000 - m * 10000 - n1 * 1000) / 100;
    n3 = (n - i * 100000000 - j * 10000000 - k * 1000000 - l * 100000 - m * 10000 - n1 * 1000 - n2 * 100) / 10;
    n4 = n - i * 100000000 - j * 10000000 - k * 1000000 - l * 100000 - m * 10000 - n1 * 1000 - n2 * 100 - n3 * 10;
    if (n4 == 0) return n;
    n5 = n4 - 1;
    return i * 100000000 + j * 10000000 + k * 1000000 + l * 100000 + m * 10000 + n1 * 1000 + n2 * 100 + n3 * 10 + n5;
}