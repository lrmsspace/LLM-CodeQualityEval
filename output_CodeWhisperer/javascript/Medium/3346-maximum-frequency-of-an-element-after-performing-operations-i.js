/*
 You are given an integer array nums and two integers k and numOperations.
 You must perform an operation numOperations times on nums, where in each operation you:
 Select an index i that was not selected in any previous operations.
 Add an integer in the range [-k, k] to nums[i].
 Return the maximum possible frequency of any element in nums after performing the operations.
 Example 1:
 Input: nums = [1,4,5], k = 1, numOperations = 2
 Output: 2
 Explanation:
 We can achieve a maximum frequency of two by:
 Adding 0 to nums[1]. nums becomes [1, 4, 5].
 Adding -1 to nums[2]. nums becomes [1, 4, 4].
 Example 2:
 Input: nums = [5,11,20,20], k = 5, numOperations = 1
 Output: 2
 Explanation:
 We can achieve a maximum frequency of two by:
 Adding 0 to nums[1].
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 105
 0 <= k <= 105
 0 <= numOperations <= nums.length
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} numOperations
 * @return {number}
 */
var maxFrequency = function(nums, k, numOperations) {
    let maxFreq = 0;
    let freq = {};
    let max = 0;
    let maxFreqNum = 0;
    let operations = numOperations;
    for (let i = 0; i < nums.length; i++) {
        if (freq[nums[i]]) {
            freq[nums[i]]++;
        } else {
            freq[nums[i]] = 1;
        }
        if (freq[nums[i]] > maxFreq) {
            maxFreq = freq[nums[i]];
            maxFreqNum = nums[i];
        }
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    while (operations > 0) {
        if (maxFreqNum + k < max) {
            if (freq[maxFreqNum] > 1) {
                freq[maxFreqNum]--;
            } else {
                delete freq[maxFreqNum];
            }
            if (freq[maxFreqNum + k]) {
                freq[maxFreqNum + k]++;
            } else {
                freq[maxFreqNum + k] = 1;
            }
            maxFreqNum += k;
        } else {
            if (freq[maxFreqNum] > 1) {
                freq[maxFreqNum]--;
            } else {
                delete freq[maxFreqNum];
            }
            if (freq[max - k]) {
                freq[max - k]++;
            } else {
                freq[max - k] = 1;
            }
            maxFreqNum = max - k;
        }
        operations--;
    }
    for (let key in freq) {
        if (freq[key] > maxFreq) {
            maxFreq = freq[key];
        }
    }
    return maxFreq;
            
};