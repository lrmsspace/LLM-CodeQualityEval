/*
 You are given an integer array nums.
 The factor score of an array is defined as the product of the LCM and GCD of all elements of that array.
 Return the maximum factor score of nums after removing at most one element from it.
 Note that both the LCM and GCD of a single number are the number itself, and the factor score of an empty array is 0.
 Example 1:
 Input: nums = [2,4,8,16]
 Output: 64
 Explanation:
 On removing 2, the GCD of the rest of the elements is 4 while the LCM is 16, which gives a maximum factor score of 4 * 16 = 64.
 Example 2:
 Input: nums = [1,2,3,4,5]
 Output: 60
 Explanation:
 The maximum factor score of 60 can be obtained without removing any elements.
 Example 3:
 Input: nums = [3]
 Output: 9
 Constraints:
 1 <= nums.length <= 100
 1 <= nums[i] <= 30
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxScore = function(nums) {
    const gcd = (a, b) => {
        while (b) {
            [a, b] = [b, a % b];
        }
        return a;
    };

    const lcm = (a, b) => (a * b) / gcd(a, b);

    const overallGCD = nums.reduce((acc, num) => gcd(acc, num), nums[0]);
    const overallLCM = nums.reduce((acc, num) => lcm(acc, num), nums[0]);

    let maxScore = overallGCD * overallLCM;

    for (let i = 0; i < nums.length; i++) {
        const newNums = nums.slice(0, i).concat(nums.slice(i + 1));
        if (newNums.length === 0) continue;

        const newGCD = newNums.reduce((acc, num) => gcd(acc, num), newNums[0]);
        const newLCM = newNums.reduce((acc, num) => lcm(acc, num), newNums[0]);

        maxScore = Math.max(maxScore, newGCD * newLCM);
    }

    return maxScore;    
};