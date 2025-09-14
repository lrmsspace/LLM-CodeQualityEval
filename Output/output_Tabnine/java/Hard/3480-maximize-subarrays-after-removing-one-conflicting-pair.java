/*
 You are given an integer n which represents an array nums containing the numbers from 1 to n in order. Additionally, you are given a 2D array conflictingPairs, where conflictingPairs[i] = [a, b] indicates that a and b form a conflicting pair.
 Remove exactly one element from conflictingPairs. Afterward, count the number of non-empty subarrays of nums which do not contain both a and b for any remaining conflicting pair [a, b].
 Return the maximum number of subarrays possible after removing exactly one conflicting pair.
 Example 1:
 Input: n = 4, conflictingPairs = [[2,3],[1,4]]
 Output: 9
 Explanation:
 Remove [2, 3] from conflictingPairs. Now, conflictingPairs = [[1, 4]].
 There are 9 subarrays in nums where [1, 4] do not appear together. They are [1], [2], [3], [4], [1, 2], [2, 3], [3, 4], [1, 2, 3] and [2, 3, 4].
 The maximum number of subarrays we can achieve after removing one element from conflictingPairs is 9.
 Example 2:
 Input: n = 5, conflictingPairs = [[1,2],[2,5],[3,5]]
 Output: 12
 Explanation:
 Remove [1, 2] from conflictingPairs. Now, conflictingPairs = [[2, 5], [3, 5]].
 There are 12 subarrays in nums where [2, 5] and [3, 5] do not appear together.
 The maximum number of subarrays we can achieve after removing one element from conflictingPairs is 12.
 Constraints:
 2 <= n <= 105
 1 <= conflictingPairs.length <= 2 * n
 conflictingPairs[i].length == 2
 1 <= conflictingPairs[i][j] <= n
 conflictingPairs[i][0] != conflictingPairs[i][1]
*/

class Solution {
    public long maxSubarrays(int n, int[][] conflictingPairs) {

        // Convert the conflictingPairs into a set for faster lookup
        Set<Integer> conflictingSet = new HashSet<>();
        for (int[] pair : conflictingPairs) {
            conflictingSet.add(pair[0]);
            conflictingSet.add(pair[1]);
        }
        // Initialize a boolean array to track the presence of conflicting pairs
        boolean[] conflicted = new boolean[n + 1];
        for (int i = 0; i < conflictingPairs.length; i++) {
            conflicted[conflictingPairs[i][0]] = true;
            conflicted[conflictingPairs[i][1]] = true;
        }

        // Initialize a prefix sum array and a prefix sum count array
        int[] prefixSum = new int[n + 1];
        int[] prefixSumCount = new int[n + 1];
        prefixSum[0] = 0;
        prefixSumCount[0] = 1;
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + (conflicted[i]? 0 : 1);
            prefixSumCount[i] = prefixSumCount[i - 1] + (conflicted[i]? 0 : 1);
        }
        // Initialize the result variable
        long result = 0;
        // Iterate over the prefix sums and prefix sum counts
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                result = Math.max(result, prefixSumCount[j] - prefixSumCount[i - 1]);
            }
        }
        // Return the maximum number of subarrays
        return result;
        
        
    }
}