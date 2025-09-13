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

    let n = boxes.length;
    let dp = new Array(n).fill(0).map(() => new Array(n).fill(0).map(() => new Array(n).fill(0)));
    
    for(let i = 0; i < n; i++){
        dp[i][i][1] = (boxes[i] + 1) * (boxes[i] + 1);
    }
    
    for(let len = 2; len <= n; len++){
        for(let i = 0; i <= n - len; i++){
            let j = i + len - 1;
            for(let k = i; k < j; k++){
                dp[i][j][k + 1] = Math.max(dp[i][j][k + 1], dp[i][k][1] + dp[k + 1][j][k + 1]);
                if(boxes[k] === boxes[j]){
                    dp[i][j][k + 1] = Math.max(dp[i][j][k + 1], dp[i][k][k + 1] + (boxes[k] + 1) * (boxes[k] + 1) + dp[k + 1][j][1]);
                }
           }
        }
    }
    return dp[0][n - 1][1];
};