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
int primePalindrome(int n){
    int i, j, k, l, m, flag;
    if (n <= 11)
        return 11;
    for (i = 11; i <= 1000000000; i++) {
        flag = 1;
        j = i;
        k = 0;
        while (j != 0) {
            k = k * 10 + j % 10;
            j /= 10;
        }
       if (i == k) {
          for (l = 2; l <= sqrt(k); l++) {
              m = k / l;
              if (m * l == k && m <= 1000000000)
                  flag = 0;
          }
          if (flag == 1)
              return k;
       }
    }  
    return 0;
}