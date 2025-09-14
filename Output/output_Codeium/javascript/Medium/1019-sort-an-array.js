/**https://leetcode.com/problems/sort-an-array/ */
//Given an array of integers nums, sort the array in ascending order and return it.
//You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
// 
//Example 1:
//Input: nums = [5,2,3,1]
//Output: [1,2,3,5]
//Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
//Example 2:
//Input: nums = [5,1,1,2,0,0]
//Output: [0,0,1,1,2,5]
//Explanation: Note that the values of nums are not necessairly unique.
// 
//Constraints:
//	1 <= nums.length <= 5 * 104
//	-5 * 104 <= nums[i] <= 5 * 104
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums) {
    // using merge sort
    // divide the array into two parts, left and right, both length is n/2
    // sort each part recursively
    // merge two sorted array into one sorted array
    function mergeSort(nums, left, right) {
        if (left < right) {
            let mid = Math.floor((left + right) / 2);
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }

    function merge(nums, left, mid, right) {
        let i = left;
        let j = mid + 1;
        let k = 0;
        let temp = new Array(right - left + 1);

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = nums[i++];
        }

        while (j <= right) {
            temp[k++] = nums[j++];
        }

        for (i = left; i <= right; i++) {
            nums[i] = temp[i - left];
        }
    }

    mergeSort(nums, 0, nums.length - 1);
    return nums;
};