/**https://leetcode.com/problems/super-ugly-number/ */
//A super ugly number is a positive integer whose prime factors are in the array primes.
//Given an integer n and an array of integers primes, return the nth super ugly number.
//The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
// 
//Example 1:
//Input: n = 12, primes = [2,7,13,19]
//Output: 32
//Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].
//Example 2:
//Input: n = 1, primes = [2,3,5]
//Output: 1
//Explanation: 1 has no prime factors, therefore all of its prime factors are in the array primes = [2,3,5].
// 
//Constraints:
//	1 <= n <= 105
//	1 <= primes.length <= 100
//	2 <= primes[i] <= 1000
//	primes[i] is guaranteed to be a prime number.
//	All the values of primes are unique and sorted in ascending order.
int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    int* dp = (int*)malloc(sizeof(int) * n);
    dp[0] = 1;
    int* index = (int*)malloc(sizeof(int) * primesSize);
    memset(index, 0, sizeof(int) * primesSize);
    for (int i = 1; i < n; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < primesSize; j++) {
            dp[i] = fmin(dp[i], dp[index[j]] * primes[j]);
        }
        for (int j = 0; j < primesSize; j++) {
            if (dp[i] == dp[index[j]] * primes[j]) {
                index[j]++;
            }
        }
    }
    int result = dp[n - 1];
    free(dp);
    free(index);
    return result;
}