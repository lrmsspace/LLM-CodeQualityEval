/**https://leetcode.com/problems/remove-boxes/ */
//You are given several boxes with different colors represented by different positive numbers.
//You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (i.e., composed of k boxes, k >= 1), remove them and get k * k points.
//Return the maximum points you can get.
// 
//Example 1:
//Input: boxes = [1,3,2,2,2,3,4,3,1]
//Output: 23
//Explanation:
//[1, 3, 2, 2, 2, 3, 4, 3, 1] 
//----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
//----> [1, 3, 3, 3, 1] (1*1=1 points) 
//----> [1, 1] (3*3=9 points) 
//----> [] (2*2=4 points)
//Example 2:
//Input: boxes = [1,1,1]
//Output: 9
//Example 3:
//Input: boxes = [1]
//Output: 1
// 
//Constraints:
//	1 <= boxes.length <= 100
//	1 <= boxes[i] <= 100
/**
 * @param {number[]} boxes
 * @return {number}
 */
var removeBoxes = function(boxes) {
    const n = boxes.length;
    const dp = Array.from({ length: n }, () => Array.from({ length: n }, () => Array(n + 1).fill(0)));

    function dfs(l, r, k) {
        if (l > r) return 0;
        if (dp[l][r][k] !== 0) return dp[l][r][k];

        while (r > l && boxes[r] === boxes[r - 1]) {
            r--;
            k++;
        }

        dp[l][r][k] = dfs(l, r - 1, 0) + (k + 1) * (k + 1);

        for (let i = l; i < r; i++) {
            if (boxes[i] === boxes[r]) {
                dp[l][r][k] = Math.max(dp[l][r][k], dfs(l, i, k + 1) + dfs(i + 1, r - 1, 0));
            }
        }

        return dp[l][r][k];
    }

    return dfs(0, n - 1, 0);    
};