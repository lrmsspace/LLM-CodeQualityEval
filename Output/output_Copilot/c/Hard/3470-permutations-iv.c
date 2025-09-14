/*
 Given two integers, n and k, an alternating permutation is a permutation of the first n positive integers such that no two adjacent elements are both odd or both even.
 Return the k-th alternating permutation sorted in lexicographical order. If there are fewer than k valid alternating permutations, return an empty list.
 Example 1:
 Input: n = 4, k = 6
 Output: [3,4,1,2]
 Explanation:
 The lexicographically-sorted alternating permutations of [1, 2, 3, 4] are:
 [1, 2, 3, 4]
 [1, 4, 3, 2]
 [2, 1, 4, 3]
 [2, 3, 4, 1]
 [3, 2, 1, 4]
 [3, 4, 1, 2] ← 6th permutation
 [4, 1, 2, 3]
 [4, 3, 2, 1]
 Since k = 6, we return [3, 4, 1, 2].
 Example 2:
 Input: n = 3, k = 2
 Output: [3,2,1]
 Explanation:
 The lexicographically-sorted alternating permutations of [1, 2, 3] are:
 [1, 2, 3]
 [3, 2, 1] ← 2nd permutation
 Since k = 2, we return [3, 2, 1].
 Example 3:
 Input: n = 2, k = 3
 Output: []
 Explanation:
 The lexicographically-sorted alternating permutations of [1, 2] are:
 [1, 2]
 [2, 1]
 There are only 2 alternating permutations, but k = 3, which is out of range. Thus, we return an empty list [].
 Constraints:
 1 <= n <= 100
 1 <= k <= 1015
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* permute(int n, long long k, int* returnSize) {
    int* result = (int*)malloc(n * sizeof(int));
    int oddCount = (n + 1) / 2; // Count of odd numbers
    int evenCount = n / 2;      // Count of even numbers
    long long totalPermutations = 1;

    // Calculate the total number of alternating permutations
    for (int i = 1; i <= oddCount; i++) {
        totalPermutations *= i;
    }
    for (int i = 1; i <= evenCount; i++) {
        totalPermutations *= i;
    }

    if (k > totalPermutations) {
        *returnSize = 0;
        free(result);
        return result; // Return empty array if k is out of range
    }

    // Fill the result array with alternating odd and even numbers
    int oddIndex = 0, evenIndex = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            result[i] = 2 * (oddIndex++) + 1; // Odd numbers
        } else {
            result[i] = 2 * (evenIndex++) + 2; // Even numbers
        }
    }

    *returnSize = n;
    return result;
    
}