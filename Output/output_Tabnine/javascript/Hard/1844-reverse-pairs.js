/**https://leetcode.com/problems/reverse-pairs/ */
//Given an integer array nums, return the number of reverse pairs in the array.
//A reverse pair is a pair (i, j) where:
//	0 <= i < j < nums.length and
//	nums[i] > 2 * nums[j].
// 
//Example 1:
//Input: nums = [1,3,2,3,1]
//Output: 2
//Explanation: The reverse pairs are:
//(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
//(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
//Example 2:
//Input: nums = [2,4,3,5,1]
//Output: 3
//Explanation: The reverse pairs are:
//(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
//(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
//(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
// 
//Constraints:
//	1 <= nums.length <= 5 * 104
//	-231 <= nums[i] <= 231 - 1
/**
 * @param {number[]} nums
 * @return {number}
 */
var reversePairs = function(nums) {
    // Merge Sort
    const mergeSort = (arr) => {
        if (arr.length <= 1) return arr;
        const mid = Math.floor(arr.length / 2);
        const left = mergeSort(arr.slice(0, mid));
        const right = mergeSort(arr.slice(mid));
        return merge(left, right);
    };
    
    // Merge Function
    const merge = (left, right) => {
        const result = [];
        let i = 0, j = 0;
        while (i < left.length && j < right.length) {
            if (left[i] <= 2 * right[j]) {
                result.push(left[i]);
                i++;
            } else {
                result.push(right[j]);
                j++;
                // Increment the count by the number of remaining elements in the left array
                // that are greater than 2 * the current right element
                result.length += left.length - i;
            }
        }
        return result.concat(left.slice(i)).concat(right.slice(j));
    };
    
    return mergeSort(nums).length;
    
};