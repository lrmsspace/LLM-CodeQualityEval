/*
 You are given an array of integers nums of size 3.
 Return the maximum possible number whose binary representation can be formed by concatenating the binary representation of all elements in nums in some order.
 Note that the binary representation of any number does not contain leading zeros.
 Example 1:
 Input: nums = [1,2,3]
 Output: 30
 Explanation:
 Concatenate the numbers in the order [3, 1, 2] to get the result "11110", which is the binary representation of 30.
 Example 2:
 Input: nums = [2,8,16]
 Output: 1296
 Explanation:
 Concatenate the numbers in the order [2, 8, 16] to get the result "10100010000", which is the binary representation of 1296.
 Constraints:
 nums.length == 3
 1 <= nums[i] <= 127
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxGoodNumber = function(nums) {
    // Function to convert a number to its binary representation without leading zeros
    const toBinary = (num) => {
        return num.toString(2);
    };

    // Generate all permutations of the nums array
    const permute = (arr) => {
        if (arr.length === 0) return [[]];
        const result = [];
        for (let i = 0; i < arr.length; i++) {
            const current = arr[i];
            const remaining = arr.slice(0, i).concat(arr.slice(i + 1));
            for (const perm of permute(remaining)) {
                result.push([current].concat(perm));
            }
        }
        return result;
    };

    // Calculate the maximum possible number by concatenating binary representations
    let maxNumber = 0;
    const permutations = permute(nums);
    for (const perm of permutations) {
        const binaryString = perm.map(toBinary).join('');
        const number = parseInt(binaryString, 2);
        maxNumber = Math.max(maxNumber, number);
    }

    return maxNumber;
        
};