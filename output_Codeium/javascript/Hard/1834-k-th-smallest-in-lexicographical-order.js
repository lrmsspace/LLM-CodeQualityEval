/**https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/ */
//Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].
// 
//Example 1:
//Input: n = 13, k = 2
//Output: 10
//Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
//Example 2:
//Input: n = 1, k = 1
//Output: 1
// 
//Constraints:
//	1 <= k <= n <= 109
/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var findKthNumber = function(n, k) {
    let cur = 1;
    k--;
    while (k > 0) {
        let cnt = calcStep(n, cur, cur + 1);
        if (k >= cnt) {
            k -= cnt;
            cur += 1;
        } else {
            cur *= 10;
            k -= 1;
        }
    }
    return cur;
}

function calcStep(n, n1, n2) {
    let step = 0;
    while (n1 <= n) {
        step += Math.min(n + 1, n2) - n1;
        n1 *= 10;
        n2 *= 10;
    }
    return step;
};