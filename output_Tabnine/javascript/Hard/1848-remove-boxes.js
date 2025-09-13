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
    const memo = {};
    
    function dp(i, j, k) {
        if (i > j) return 0;
        if (memo[i + '|' + j + '|' + k]) return memo[i + '|' + j + '|' + k];
        
        let ans = 0;
        while (j > i && boxes[j] === boxes[j - 1]) {
            j--;
            k++;
        }
        
        for (let m = i; m < j; m++) {
            if (boxes[m] === boxes[i]) {
                ans = Math.max(ans, dp(i + 1, m, 0) + dp(m + 1, j, k + 1));
            }
        }
        
        ans += k * k;
        
        memo[i + '|' + j + '|' + k] = ans;
        return ans;
    }
    
    return dp(0, boxes.length - 1, 0);
    
};