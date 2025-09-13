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
    let left = 1, right = n;
    while (left < right) {
        let mid = left + Math.floor((right - left) / 2);
        let count = countNumbers(mid);
        if (count < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
    
    function countNumbers(mid) {
        let count = 0;
        let i = 1;
        while (i <= n) {
            let next = Math.min(i + mid - 1, n);
            count += next - i + 1;
            i = next + 1;
        }
        return count;
    }
};