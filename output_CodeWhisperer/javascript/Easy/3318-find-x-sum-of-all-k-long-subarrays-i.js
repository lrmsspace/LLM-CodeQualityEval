/*
 You are given an array nums of n integers and two integers k and x.
 The x-sum of an array is calculated by the following procedure:
 Count the occurrences of all elements in the array.
 Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
 Calculate the sum of the resulting array.
 Note that if an array has less than x distinct elements, its x-sum is the sum of the array.
 Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].
 Example 1:
 Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2
 Output: [6,10,12]
 Explanation:
 For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
 For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
 For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.
 Example 2:
 Input: nums = [3,8,7,8,7,5], k = 2, x = 2
 Output: [11,15,15,15,12]
 Explanation:
 Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k - 1].
 Constraints:
 1 <= n == nums.length <= 50
 1 <= nums[i] <= 50
 1 <= x <= k <= nums.length
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} x
 * @return {number[]}
 */
var findXSum = function(nums, k, x) {
    let result = [];
    let sum = 0;
    let map = new Map();
    for (let i = 0; i < k; i++) {
        map.set(nums[i], (map.get(nums[i]) || 0) + 1);
    }
    for (let i = 0; i < k; i++) {
        let max = 0;
        let maxKey = 0;
        for (let [key, value] of map) {
            if (value > max || (value == max && key > maxKey)) {
                max = value;
                maxKey = key;
            }
        }
        sum += maxKey;
        map.set(maxKey, max - 1);
        if (map.get(maxKey) == 0) {
            map.delete(maxKey);
        }
    }
    result.push(sum);
    for (let i = k; i < nums.length; i++) {
        map.set(nums[i], (map.get(nums[i]) || 0) + 1);
        let max = 0;
        let maxKey = 0;
        for (let [key, value] of map) {
            if (value > max || (value == max && key > maxKey)) {
                max = value;
                maxKey = key;
            }
        }
        sum = sum - nums[i - k] + maxKey;
        map.set(nums[i - k], (map.get(nums[i - k]) || 0) - 1);
        if (map.get(nums[i - k]) == 0) {
            map.delete(nums[i - k]);
        }
        result.push(sum);
    }
    return result;
    
};