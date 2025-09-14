/**https://leetcode.com/problems/prime-palindrome/ */
//Given an integer n, return the smallest prime palindrome greater than or equal to n.
//An integer is prime if it has exactly two divisors: 1 and itself. Note that 1 is not a prime number.
//	For example, 2, 3, 5, 7, 11, and 13 are all primes.
//An integer is a palindrome if it reads the same from left to right as it does from right to left.
//	For example, 101 and 12321 are palindromes.
//The test cases are generated so that the answer always exists and is in the range [2, 2 * 108].
// 
//Example 1:
//Input: n = 6
//Output: 7
//Example 2:
//Input: n = 8
//Output: 11
//Example 3:
//Input: n = 13
//Output: 101
// 
//Constraints:
//	1 <= n <= 108
int primePalindrome(int n) {
    if (n == 1) return 2;
    while (1) {
        if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11) return n;
        if (n % 2 == 0) n++;
        if (n > 11 && n % 10 == 5) n += 2;
        if (n > 11 && n % 10 == 0) n += 1;
        if (n > 11 && n % 10 == 2) n += 1;
        if (n > 11 && n % 10 == 4) n += 1;
        if (n > 11 && n % 10 == 6) n += 1;
        if (n > 11 && n % 10 == 8) n += 1;
        if (n > 11 && n % 10 == 9) n += 1;
        int i = 2;
        while (i * i <= n) {
            if (n % i == 0) break;
            i++;
        }
        if (i * i > n) return n;
        n++;
    }    
}