/*
 You are given an integer array rewardValues of length n, representing the values of rewards.
 Initially, your total reward x is 0, and all indices are unmarked. You are allowed to perform the following operation any number of times:
 Choose an unmarked index i from the range [0, n - 1].
 If rewardValues[i] is greater than your current total reward x, then add rewardValues[i] to x (i.e., x = x + rewardValues[i]), and mark the index i.
 Return an integer denoting the maximum total reward you can collect by performing the operations optimally.
 Example 1:
 Input: rewardValues = [1,1,3,3]
 Output: 4
 Explanation:
 During the operations, we can choose to mark the indices 0 and 2 in order, and the total reward will be 4, which is the maximum.
 Example 2:
 Input: rewardValues = [1,6,4,3,2]
 Output: 11
 Explanation:
 Mark the indices 0, 2, and 1 in order. The total reward will then be 11, which is the maximum.
 Constraints:
 1 <= rewardValues.length <= 2000
 1 <= rewardValues[i] <= 2000
*/

/**
 * @param {number[]} rewardValues
 * @return {number}
 */
var maxTotalReward = function(rewardValues) {
    let n = rewardValues.length;
    let dp = new Array(n).fill(0);
    for(let i = 0; i < n; i++){
        let j = i;
        let sum = 0;
        while(j >= 0 && rewardValues[j] > dp[j]){
            sum += rewardValues[j];
            j--;
        }
        dp[i] = sum;
    }
    return dp[n-1];
    
};