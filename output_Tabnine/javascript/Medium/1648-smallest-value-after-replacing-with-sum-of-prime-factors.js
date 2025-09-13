/**https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/ */
//You are given a positive integer n.
//Continuously replace n with the sum of its prime factors.
//	Note that if a prime factor divides n multiple times, it should be included in the sum as many times as it divides n.
//Return the smallest value n will take on.
// 
//Example 1:
//Input: n = 15
//Output: 5
//Explanation: Initially, n = 15.
//15 = 3 * 5, so replace n with 3 + 5 = 8.
//8 = 2 * 2 * 2, so replace n with 2 + 2 + 2 = 6.
//6 = 2 * 3, so replace n with 2 + 3 = 5.
//5 is the smallest value n will take on.
//Example 2:
//Input: n = 3
//Output: 3
//Explanation: Initially, n = 3.
//3 is the smallest value n will take on.
// 
//Constraints:
//	2 <= n <= 105
/**
 * @param {number} n
 * @return {number}
 */
var smallestValue = function(n) {
    function isPrime(num) {
        if (num <= 1) return false;
        for (let i = 2; i <= Math.sqrt(num); i++) {
            if (num % i === 0) return false;
        }
        return true;
    }
    
    while (true) {
        let sum = 0;
        let factors = [];
        for (let i = 2; i <= Math.sqrt(n); i++) {
            if (n % i === 0) {
                factors.push(i);
                if (i!== n / i) factors.push(n / i);
            }
        }
        
        factors.forEach(factor => {
            if (isPrime(factor)) sum += factor;
        });
        
        if (sum === 0) return n;
        n = sum;
    }
    
};