/*
 Given an integer array nums, find the number of subsequences of size 5 of nums with a unique middle mode.
 Since the answer may be very large, return it modulo 109 + 7.
 A mode of a sequence of numbers is defined as the element that appears the maximum number of times in the sequence.
 A sequence of numbers contains a unique mode if it has only one mode.
 A sequence of numbers seq of size 5 contains a unique middle mode if the middle element (seq[2]) is a unique mode.
 Example 1:
 Input: nums = [1,1,1,1,1,1]
 Output: 6
 Explanation:
 [1, 1, 1, 1, 1] is the only subsequence of size 5 that can be formed, and it has a unique middle mode of 1. This subsequence can be formed in 6 different ways, so the output is 6. 
 Example 2:
 Input: nums = [1,2,2,3,3,4]
 Output: 4
 Explanation:
 [1, 2, 2, 3, 4] and [1, 2, 3, 3, 4] each have a unique middle mode because the number at index 2 has the greatest frequency in the subsequence. [1, 2, 2, 3, 3] does not have a unique middle mode because 2 and 3 appear twice.
 Example 3:
 Input: nums = [0,1,2,3,4,5,6,7,8]
 Output: 0
 Explanation:
 There is no subsequence of length 5 with a unique middle mode.
 Constraints:
 5 <= nums.length <= 1000
 -109 <= nums[i] <= 109
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var subsequencesWithMiddleMode = function(nums) {
    let count = 0;
    let mod = 1e9 + 7;
    for (let i = 0; i < nums.length - 4; i++) {
        for (let j = i + 1; j < nums.length - 3; j++) {
            for (let k = j + 1; k < nums.length - 2; k++) {
                for (let l = k + 1; l < nums.length - 1; l++) {
                    for (let m = l + 1; m < nums.length; m++) {
                        let map = {};
                        let a = [nums[i], nums[j], nums[k], nums[l], nums[m]];
                        for (let num of a) {
                            map[num] = (map[num] || 0) + 1;
                        }
                        let max = 0;
                        let flag = true;
                        for (let key in map) {
                            if (map[key] > max) {
                                max = map[key];
                                flag = true;
                            } else if (map[key] === max) {
                                flag = false;
                            }
                        }
                        if (flag && map[nums[k]] === max) {
                            count = (count + 1) % mod;
                        }
                    }
                }
            }
        }
    }
    return count;
};