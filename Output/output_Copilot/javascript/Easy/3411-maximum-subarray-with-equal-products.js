/*
 You are given an array of positive integers nums.
 An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr), where:
 prod(arr) is the product of all elements of arr.
 gcd(arr) is the GCD of all elements of arr.
 lcm(arr) is the LCM of all elements of arr.
 Return the length of the longest product equivalent subarray of nums.
 Example 1:
 Input: nums = [1,2,1,2,1,1,1]
 Output: 5
 Explanation: 
 The longest product equivalent subarray is [1, 2, 1, 1, 1], where prod([1, 2, 1, 1, 1]) = 2, gcd([1, 2, 1, 1, 1]) = 1, and lcm([1, 2, 1, 1, 1]) = 2.
 Example 2:
 Input: nums = [2,3,4,5,6]
 Output: 3
 Explanation: 
 The longest product equivalent subarray is [3, 4, 5].
 Example 3:
 Input: nums = [1,2,3,1,4,5,1]
 Output: 5
 Constraints:
 2 <= nums.length <= 100
 1 <= nums[i] <= 10
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxLength = function(nums) {
    const gcd = (a, b) => b === 0 ? a : gcd(b, a % b);
    const lcm = (a, b) => (a * b) / gcd(a, b);

    let maxLength = 0;
    const n = nums.length;

    for (let i = 0; i < n; i++) {
        let product = nums[i];
        let currentGCD = nums[i];
        let currentLCM = nums[i];
        let length = 1;

        for (let j = i + 1; j < n; j++) {
            product *= nums[j];
            currentGCD = gcd(currentGCD, nums[j]);
            currentLCM = lcm(currentLCM, nums[j]);

            if (product === currentLCM * currentGCD) {
                length++;
                maxLength = Math.max(maxLength, length);
            } else {
                break;
            }
        }
    }

    return maxLength;
    
};