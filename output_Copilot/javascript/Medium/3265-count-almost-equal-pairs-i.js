/*
 You are given an array nums consisting of positive integers.
 We call two integers x and y in this problem almost equal if both integers can become equal after performing the following operation at most once:
 Choose either x or y and swap any two digits within the chosen number.
 Return the number of indices i and j in nums where i < j such that nums[i] and nums[j] are almost equal.
 Note that it is allowed for an integer to have leading zeros after performing an operation.
 Example 1:
 Input: nums = [3,12,30,17,21]
 Output: 2
 Explanation:
 The almost equal pairs of elements are:
 3 and 30. By swapping 3 and 0 in 30, you get 3.
 12 and 21. By swapping 1 and 2 in 12, you get 21.
 Example 2:
 Input: nums = [1,1,1,1,1]
 Output: 10
 Explanation:
 Every two elements in the array are almost equal.
 Example 3:
 Input: nums = [123,231]
 Output: 0
 Explanation:
 We cannot swap any two digits of 123 or 231 to reach the other.
 Constraints:
 2 <= nums.length <= 100
 1 <= nums[i] <= 106
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var countPairs = function(nums) {
    const n = nums.length;
    let count = 0;

    // Function to check if two numbers are almost equal
    const areAlmostEqual = (x, y) => {
        const strX = x.toString();
        const strY = y.toString();
        if (strX.length !== strY.length) return false;

        // Check if they can become equal by swapping one digit
        for (let i = 0; i < strX.length; i++) {
            for (let j = 0; j < strY.length; j++) {
                if (i !== j && strX[i] === strY[j]) {
                    const newStrX = strX.slice(0, i) + strY[j] + strX.slice(i + 1);
                    const newStrY = strY.slice(0, j) + strX[i] + strY.slice(j + 1);
                    if (newStrX === newStrY) return true;
                }
            }
        }
        return false;
    };

    // Count almost equal pairs
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            if (areAlmostEqual(nums[i], nums[j])) {
                count++;
            }
        }
    }

    return count;
        
};