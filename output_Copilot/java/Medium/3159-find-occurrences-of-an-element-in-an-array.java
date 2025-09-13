/*
 You are given an integer array nums, an integer array queries, and an integer x.
 For each queries[i], you need to find the index of the queries[i]th occurrence of x in the nums array. If there are fewer than queries[i] occurrences of x, the answer should be -1 for that query.
 Return an integer array answer containing the answers to all queries.
 Example 1:
 Input: nums = [1,3,1,7], queries = [1,3,2,4], x = 1
 Output: [0,-1,2,-1]
 Explanation:
 For the 1st query, the first occurrence of 1 is at index 0.
 For the 2nd query, there are only two occurrences of 1 in nums, so the answer is -1.
 For the 3rd query, the second occurrence of 1 is at index 2.
 For the 4th query, there are only two occurrences of 1 in nums, so the answer is -1.
 Example 2:
 Input: nums = [1,2,3], queries = [10], x = 5
 Output: [-1]
 Explanation:
 For the 1st query, 5 doesn't exist in nums, so the answer is -1.
 Constraints:
 1 <= nums.length, queries.length <= 105
 1 <= queries[i] <= 105
 1 <= nums[i], x <= 104
*/

class Solution {
    public int[] occurrencesOfElement(int[] nums, int[] queries, int x) {
        int n = nums.length;
        int[] result = new int[queries.length];
        int[] occurrenceIndices = new int[n + 1]; // Store indices of occurrences of x

        // Fill occurrenceIndices with -1
        for (int i = 0; i <= n; i++) {
            occurrenceIndices[i] = -1;
        }

        // Find occurrences of x and store their indices
        for (int i = 0; i < n; i++) {
            if (nums[i] == x) {
                occurrenceIndices[i + 1] = i; // Store the index of the (i+1)th occurrence
            } else {
                occurrenceIndices[i + 1] = occurrenceIndices[i]; // Carry forward the last index
            }
        }

        // Process each query
        for (int i = 0; i < queries.length; i++) {
            int queryIndex = queries[i];
            if (queryIndex <= n && occurrenceIndices[queryIndex] != -1) {
                result[i] = occurrenceIndices[queryIndex];
            } else {
                result[i] = -1;
            }
        }

        return result;        
    }
}