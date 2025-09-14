/**https://leetcode.com/problems/count-primes/ */
//Given an integer n, return the number of prime numbers that are strictly less than n.
// 
//Example 1:
//Input: n = 10
//Output: 4
//Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
//Example 2:
//Input: n = 0
//Output: 0
//Example 3:
//Input: n = 1
//Output: 0
// 
//Constraints:
//	0 <= n <= 5 * 106
/**
 * @param {number} n
 * @return {number}
 */
var countPrimes = function(n) {
    if (n < 2) {
        return 0;
    }

    let primes = new Array(n).fill(true);
    primes[0] = false;
    primes[1] = false;

    for (let i = 2; i * i < n; i++) {
        if (primes[i]) {
            for (let j = i * i; j < n; j += i) {
                primes[j] = false;
            }
        }
    }

    let count = 0;
    for (let i = 0; i < n; i++) {
        if (primes[i]) {
            count++;
        }
    }

    return count;
};