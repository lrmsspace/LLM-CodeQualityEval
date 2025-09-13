/*
 You are given an array of integers nums. Some values in nums are missing and are denoted by -1.
 You must choose a pair of positive integers (x, y) exactly once and replace each missing element with either x or y.
 You need to minimize the maximum absolute difference between adjacent elements of nums after replacements.
 Return the minimum possible difference.
 Example 1:
 Input: nums = [1,2,-1,10,8]
 Output: 4
 Explanation:
 By choosing the pair as (6, 7), nums can be changed to [1, 2, 6, 10, 8].
 The absolute differences between adjacent elements are:
 |1 - 2| == 1
 |2 - 6| == 4
 |6 - 10| == 4
 |10 - 8| == 2
 Example 2:
 Input: nums = [-1,-1,-1]
 Output: 0
 Explanation:
 By choosing the pair as (4, 4), nums can be changed to [4, 4, 4].
 Example 3:
 Input: nums = [-1,10,-1,8]
 Output: 1
 Explanation:
 By choosing the pair as (11, 9), nums can be changed to [11, 10, 9, 8].
 Constraints:
 2 <= nums.length <= 105
 nums[i] is either -1 or in the range [1, 109].
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var minDifference = function(nums) {
    let n = nums.length;
    if(n <= 1) return 0;
    let dp = new Array(n).fill().map(() => new Array(10).fill(0));
    for(let i = 0; i < n; i++){
        for(let j = 0; j < 10; j++){
            if(i == 0){
                if(nums[i] == j) dp[i][j] = 1;
                else dp[i][j] = 0;
            }else{
                if(nums[i] == j){
                    dp[i][j] = dp[i-1][j] + 1;
                }
            }
        }
    }

    for(let i = 1; i < n; i++){
        for(let j = 0; j < 10; j++){
            for(let k = 0; k < 10; k++){
                if(j == k) continue;
                dp[i][j] += dp[i-1][k];
            }
        }
    }
    return dp[n-1][0] % mod;
    
};