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
    int prime[n+1];
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= n; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i)
                prime[j] = 0;
        }
    }
    int cnt = 0;
    for (int i = 2; i <= n; ++i)
        cnt += prime[i];
    int res = 1;
    for (int i = 1; i <= cnt; ++i)
        res = (long long)res * i % (1e9 + 7);
    for (int i = 1; i <= n - cnt; ++i)
        res = (long long)res * i % (1e9 + 7);
    return res;
}