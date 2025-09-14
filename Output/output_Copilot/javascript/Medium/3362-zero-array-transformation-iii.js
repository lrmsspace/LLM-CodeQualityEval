/*
 You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].
 Each queries[i] represents the following action on nums:
 Decrement the value at each index in the range [li, ri] in nums by at most 1.
 The amount by which the value is decremented can be chosen independently for each index.
 A Zero Array is an array with all its elements equal to 0.
 Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.
 Example 1:
 Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]
 Output: 1
 Explanation:
 After removing queries[2], nums can still be converted to a zero array.
 Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
 Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
 Example 2:
 Input: nums = [1,1,1,1], queries = [[1,3],[0,2],[1,3],[1,2]]
 Output: 2
 Explanation:
 We can remove queries[2] and queries[3].
 Example 3:
 Input: nums = [1,2,3,4], queries = [[0,3]]
 Output: -1
 Explanation:
 nums cannot be converted to a zero array even after using all the queries.
 Constraints:
 1 <= nums.length <= 105
 0 <= nums[i] <= 105
 1 <= queries.length <= 105
 queries[i].length == 2
 0 <= li <= ri < nums.length
*/

/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {number}
 */
var maxRemoval = function(nums, queries) {
    const n = nums.length;
    const m = queries.length;
    const prefixSum = new Array(n + 1).fill(0);
    
    // Calculate the prefix sum of nums
    for (let i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
    
    // Sort queries by their right index
    queries.sort((a, b) => a[1] - b[1]);
    
    let left = 0, right = 0, maxRemovals = 0;
    
    while (right < m) {
        const [l, r] = queries[right];
        
        // Check if we can remove this query
        if (prefixSum[r + 1] - prefixSum[l] <= r - l + 1) {
            maxRemovals++;
            right++;
        } else {
            left++;
            if (left > right) {
                right++;
            }
        }
    }
    
    return maxRemovals === m ? maxRemovals : -1;
        
};