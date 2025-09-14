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

long long maxSubarrays(int n, int** conflictingPairs, int conflictingPairsSize, int* conflictingPairsColSize) {
    long long maxSubarraysCount = 0;

    for (int i = 0; i < conflictingPairsSize; i++) {
        int a = conflictingPairs[i][0];
        int b = conflictingPairs[i][1];

        // Create a new array remainingPairs by excluding the selected conflicting pair
        int remainingPairsSize = conflictingPairsSize - 1;
        int** remainingPairs = (int**)malloc(remainingPairsSize * sizeof(int*));
        int j = 0;
        for (int k = 0; k < conflictingPairsSize; k++) {
            if (k != i) {
                remainingPairs[j] = (int*)malloc(2 * sizeof(int));
                remainingPairs[j][0] = conflictingPairs[k][0];
                remainingPairs[j][1] = conflictingPairs[k][1];
                j++;
            }
        }

        // Count the number of non-empty subarrays in nums that do not contain both a and b
        long long subarraysCount = 0;
        for (int start = 0; start < n; start++) {
            for (int end = start; end < n; end++) {
                bool containsConflictingPair = false;
                for (int k = 0; k < remainingPairsSize; k++) {
                    int x = remainingPairs[k][0];
                    int y = remainingPairs[k][1];
                    if ((start < x && x < end) || (start < y && y < end)) {
                        containsConflictingPair = true;
                        break;
                    }
                }
                if (!containsConflictingPair) {
                    subarraysCount++;
                }
            }
        }

        // Update maxSubarraysCount if the calculated subarraysCount is greater
        if (subarraysCount > maxSubarraysCount) {
            maxSubarraysCount = subarraysCount;
        }

        // Free the memory allocated for remainingPairs
        for (int k = 0; k < remainingPairsSize; k++) {
            free(remainingPairs[k]);
        }
        free(remainingPairs);
    }

    return maxSubarraysCount;
}