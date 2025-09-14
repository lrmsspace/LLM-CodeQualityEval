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
    const MOD = 1e9 + 7;
    const n = nums.length;
    if (n < 5) return 0; // Not enough elements to form a subsequence of size 5

    // Count occurrences of each number
    const count = {};
    for (const num of nums) {
        count[num] = (count[num] || 0) + 1;
    }

    // Convert count object to an array of [number, frequency]
    const freqArray = Object.entries(count).map(([num, freq]) => [Number(num), freq]);
    
    // Sort by frequency in descending order
    freqArray.sort((a, b) => b[1] - a[1]);

    let result = 0;

    // Iterate through all combinations of numbers to find valid subsequences
    for (let i = 0; i < freqArray.length; i++) {
        for (let j = i + 1; j < freqArray.length; j++) {
            for (let k = j + 1; k < freqArray.length; k++) {
                for (let l = k + 1; l < freqArray.length; l++) {
                    for (let m = l + 1; m < freqArray.length; m++) {
                        const middleIndex = Math.floor((i + j + k + l + m) / 2);
                        const middleValue = freqArray[middleIndex][0];
                        const middleFreq = freqArray[middleIndex][1];

                        // Check if the middle value is unique
                        if (middleFreq === 1) {
                            result = (result + 1) % MOD;
                        }
                    }
                }
            }
        }
    }

    return result;
        
};