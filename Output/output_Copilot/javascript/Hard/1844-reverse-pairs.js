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
    let count = 0;
    const mergeSort = (left, right) => {
        if (left >= right) return;
        const mid = Math.floor((left + right) / 2);
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        let j = mid + 1;
        for (let i = left; i <= mid; i++) {
            while (j <= right && nums[i] > 2 * nums[j]) {
                j++;
            }
            count += j - (mid + 1);
        }
        merge(left, mid, right);
    };
    const merge = (left, mid, right) => {
        const temp = [];
        let i = left;
        let j = mid + 1;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push(nums[i++]);
            } else {
                temp.push(nums[j++]);
            }
        }
        while (i <= mid) {
            temp.push(nums[i++]);
        }
        while (j <= right) {
            temp.push(nums[j++]);
        }
        for (let k = left; k <= right; k++) {
            nums[k] = temp[k - left];
        }
    };
    mergeSort(0, nums.length - 1);
    return count;    
};