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
    let memo = new Map();
    function dfs(l, r, k) {
        if (l > r) return 0;
        if (memo.has(`${l}-${r}-${k}`)) return memo.get(`${l}-${r}-${k}`);
        while (l < r && boxes[r] == boxes[r-1]) {
            r--;
            k++;
        }
        let res = (k+1)*(k+1) + dfs(l, r-1, 0);
        for (let i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {
                res = Math.max(res, dfs(l, i, k+1) + dfs(i+1, r-1, 0));
            }
        }
        memo.set(`${l}-${r}-${k}`, res);
        return res;
    }
    return dfs(0, boxes.length-1, 0);
};