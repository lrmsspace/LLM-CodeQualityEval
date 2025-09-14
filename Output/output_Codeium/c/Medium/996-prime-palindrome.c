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
    int is_prime(int n) {
        if (n < 2) return 0;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return 0;
        }
        return 1;
    }

    int is_palindrome(int n) {
        int r = 0;
        for (int x = n; x; x /= 10) {
            r = r * 10 + x % 10;
        }
        return r == n;
    }

    for (int i = n; ; i++) {
        if (is_prime(i) && is_palindrome(i)) return i;
    }

    return 0;
}