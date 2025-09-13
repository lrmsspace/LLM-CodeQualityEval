/**https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/ */
//You are given an m x n matrix mat that has its rows sorted in non-decreasing order and an integer k.
//You are allowed to choose exactly one element from each row to form an array.
//Return the kth smallest array sum among all possible arrays.
// 
//Example 1:
//Input: mat = [[1,3,11],[2,4,6]], k = 5
//Output: 7
//Explanation: Choosing one element from each row, the first k smallest sum are:
//[1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.
//Example 2:
//Input: mat = [[1,3,11],[2,4,6]], k = 9
//Output: 17
//Example 3:
//Input: mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
//Output: 9
//Explanation: Choosing one element from each row, the first k smallest sum are:
//[1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]. Where the 7th sum is 9.  
// 
//Constraints:
//	m == mat.length
//	n == mat.length[i]
//	1 <= m, n <= 40
//	1 <= mat[i][j] <= 5000
//	1 <= k <= min(200, nm)
//	mat[i] is a non-decreasing array.
/**
 * @param {number[][]} mat
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(mat, k) {
    let m = mat.length;
    let n = mat[0].length;
    let heap = [[mat[0][0], 0, 0]];
    let seen = new Set().add(0);
    let ans = 0;
    while(k--) {
        let [cur, i, j] = heap.shift();
        ans = cur;
        if(j + 1 < n && !seen.has((i * n) + j + 1)) {
            seen.add((i * n) + j + 1);
            heap.push([mat[i][j + 1] + cur, i, j + 1]);
        }
        if(i + 1 < m && !seen.has(((i + 1) * n) + j)) {
            seen.add(((i + 1) * n) + j);
            heap.push([mat[i + 1][j] + cur, i + 1, j]);
        }
        heap.sort((a, b) => a[0] - b[0]);
    }
    return ans;
};