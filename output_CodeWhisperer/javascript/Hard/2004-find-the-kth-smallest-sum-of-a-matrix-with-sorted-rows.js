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
    let pq = [];
    let sum = 0;
    for (let i = 0; i < m; i++) {
        sum += mat[i][0];
    }
    pq.push([sum, 0, mat]);
    let set = new Set();
    set.add(sum);
    while (k > 0) {
        let [sum, i, mat] = pq.shift();
        k--;
        if (k == 0) return sum;
        if (i == m - 1) continue;
        for (let j = 1; j < n; j++) {
            let newSum = sum - mat[i][0] + mat[i][j];
            let newMat = mat.map(row => row.slice());
            newMat[i] = mat[i].slice(0, j + 1);
            if (!set.has(newSum)) {
                pq.push([newSum, i + 1, newMat]);
                set.add(newSum);
            }
        }
        pq.sort((a, b) => a[0] - b[0]);
    }
    return -1;
};