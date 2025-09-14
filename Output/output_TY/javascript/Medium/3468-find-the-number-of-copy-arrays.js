/*
 You are given an array original of length n and a 2D array bounds of length n x 2, where bounds[i] = [ui, vi].
 You need to find the number of possible arrays copy of length n such that:
 (copy[i] - copy[i - 1]) == (original[i] - original[i - 1]) for 1 <= i <= n - 1.
 ui <= copy[i] <= vi for 0 <= i <= n - 1.
 Return the number of such arrays.
 Example 1:
 Input: original = [1,2,3,4], bounds = [[1,2],[2,3],[3,4],[4,5]]
 Output: 2
 Explanation:
 The possible arrays are:
 [1, 2, 3, 4]
 [2, 3, 4, 5]
 Example 2:
 Input: original = [1,2,3,4], bounds = [[1,10],[2,9],[3,8],[4,7]]
 Output: 4
 Explanation:
 The possible arrays are:
 [1, 2, 3, 4]
 [2, 3, 4, 5]
 [3, 4, 5, 6]
 [4, 5, 6, 7]
 Example 3:
 Input: original = [1,2,1,2], bounds = [[1,1],[2,3],[3,3],[2,3]]
 Output: 0
 Explanation:
 No array is possible.
 Constraints:
 2 <= n == original.length <= 105
 1 <= original[i] <= 109
 bounds.length == n
 bounds[i].length == 2
 1 <= bounds[i][0] <= bounds[i][1] <= 109
*/

/**
 * @param {number[]} original
 * @param {number[][]} bounds
 * @return {number}
 */
var countArrays = function(original, bounds) {
    let n = original.length;
    let dp = new Array(n+1).fill().map(() => new Array(n+1).fill(0));
    for(let i = 0; i < n; i++){
        for(let j = 0; j <= i; j++){
            if(j == 0){
                dp[i+1][j] = dp[i][j] + (original[i] == bounds[i][0] ? 1 : 0);
            }else{
                dp[i+1][j] = dp[i][j] + (original[i] == bounds[i][0] ? 1 : 0) - (original[j-1] == bounds[i][1] ? 1 : 0) + (changed[i] == bounds[i][0] ? 1 : 0) - (changed[j-1] == bounds[i][1] ? 1 : 0);
            }
        }
    }
    return Math.min(...dp[n]);
    
};