/*
 You are given an array of positive integers nums.
 Alice and Bob are playing a game. In the game, Alice can choose either all single-digit numbers or all double-digit numbers from nums, and the rest of the numbers are given to Bob. Alice wins if the sum of her numbers is strictly greater than the sum of Bob's numbers.
 Return true if Alice can win this game, otherwise, return false.
 Example 1:
 Input: nums = [1,2,3,4,10]
 Output: false
 Explanation:
 Alice cannot win by choosing either single-digit or double-digit numbers.
 Example 2:
 Input: nums = [1,2,3,4,5,14]
 Output: true
 Explanation:
 Alice can win by choosing single-digit numbers which have a sum equal to 15.
 Example 3:
 Input: nums = [5,5,5,25]
 Output: true
 Explanation:
 Alice can win by choosing double-digit numbers which have a sum equal to 25.
 Constraints:
 1 <= nums.length <= 100
 1 <= nums[i] <= 99
*/

/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canAliceWin = function(nums) {
    let sum = nums.reduce((a, b) => a + b, 0);
    if (sum % 2 === 1) return false;
    let dp = new Set();
    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            if (nums[i] + nums[j] <= sum) dp.add(nums[i] + nums[j]);
        }
    }
    let turn = true;
    while (dp.size > 0) {
        let newDp = new Set();
        for (let i of dp) {
            for (let j = 1; j <= k; j++) {
                if (i + j <= sum) newDp.add(i + j);
            }
        }
    }
    return turn;
    
};