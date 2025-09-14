/*
 Given an array nums, you can perform the following operation any number of times:
 Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
 Replace the pair with their sum.
 Return the minimum number of operations needed to make the array non-decreasing.
 An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).
 Example 1:
 Input: nums = [5,2,3,1]
 Output: 2
 Explanation:
 The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
 The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
 The array nums became non-decreasing in two operations.
 Example 2:
 Input: nums = [1,2,2]
 Output: 0
 Explanation:
 The array nums is already sorted.
 Constraints:
 1 <= nums.length <= 105
 -109 <= nums[i] <= 109
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumPairRemoval = function(nums) {
    let operations = 0;
    let n = nums.length;

    // Function to check if the array is non-decreasing
    const isNonDecreasing = (arr) => {
        for (let i = 1; i < arr.length; i++) {
            if (arr[i] < arr[i - 1]) return false;
        }
        return true;
    };

    // While the array is not non-decreasing
    while (!isNonDecreasing(nums)) {
        let minSum = Infinity;
        let minIndex = -1;

        // Find the leftmost pair with the minimum sum
        for (let i = 0; i < n - 1; i++) {
            let sum = nums[i] + nums[i + 1];
            if (sum < minSum) {
                minSum = sum;
                minIndex = i;
            }
        }

        // Replace the pair with their sum
        nums[minIndex] += nums[minIndex + 1];
        nums.splice(minIndex + 1, 1);
        operations++;
    }

    return operations;    
};