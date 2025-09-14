/**https://leetcode.com/problems/prime-arrangements/ */
//Return the number of permutations of 1 to n so that prime numbers are at prime indices (1-indexed.)
//(Recall that an integer is prime if and only if it is greater than 1, and cannot be written as a product of two positive integers both smaller than it.)
//Since the answer may be large, return the answer modulo 10^9 + 7.
// 
//Example 1:
//Input: n = 5
//Output: 12
//Explanation: For example [1,2,5,4,3] is a valid permutation, but [5,2,3,4,1] is not because the prime number 5 is at index 1.
//Example 2:
//Input: n = 100
//Output: 682289015
// 
//Constraints:
//	1 <= n <= 100
int numPrimeArrangements(int n) {
    int MOD = 1000000007;
    int primes[n+1];
    memset(primes, 0, sizeof(primes));
    primes[2] = 1;
    for (int i = 3; i <= n; i += 2) {
        primes[i] = 1;
        for (int j = 3; j * j <= i; j += 2) {
            if (i % j == 0) {
                primes[i] = 0;
                break;
            }
        }
    }
    long long ans = 1;
    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            ans = (ans * i) % MOD;
        }
    }
    for (int i = 2; i <= n / 2; i++) {
        ans = (ans * (n - i + 1)) % MOD;
    }
    return ans;
}