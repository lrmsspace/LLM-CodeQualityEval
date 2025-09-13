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
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {

        // Step 1: Sort the conflicting pairs by the first element
        sort(conflictingPairs.begin(), conflictingPairs.end(), [](const vector<int>& pair1, const vector<int>& pair2) {
            return pair1[0] < pair2[0];
        });
        // Step 2: Create a vector to store the prefix sum of the array
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + i;
        }
        // Step 3: Create a vector to store the count of subarrays that do not contain both a and b for each remaining conflicting pair
        vector<long long> count(conflictingPairs.size(), 0);
        for (int i = 0; i < conflictingPairs.size(); ++i) {
            int a = conflictingPairs[i][0];
            int b = conflictingPairs[i][1];
            // Calculate the count of subarrays that do not contain both a and b
            count[i] = prefixSum[n] - prefixSum[a - 1] - prefixSum[b - 1] + prefixSum[a - 1] * (b - a);
        }
        // Step 4: Calculate the maximum number of subarrays possible after removing exactly one conflicting pair
        long long maxSubarrays = 0;
        for (int i = 0; i < count.size(); ++i) {
            maxSubarrays = max(maxSubarrays, count[i]);
        }
        return maxSubarrays;
        
    }
};