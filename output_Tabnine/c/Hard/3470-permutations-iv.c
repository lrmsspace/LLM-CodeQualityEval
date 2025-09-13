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
    int* res = (int*)malloc(sizeof(int) * n);
    *returnSize = n;
    
    // Initialize the first n odd numbers
    for (int i = 0; i < n; i += 2) {
        res[i] = i + 1;
    }
    
    // Generate the remaining even numbers
    int even = 2;
    for (int i = 1; i < n; i += 2) {
        res[i] = even;
        even += 2;
    }
    // Calculate the number of permutations with n odd numbers
    long long factorial = 1;
    for (int i = 2; i <= n; i++) {
        factorial *= i;
    }
    
    // Calculate the k-th permutation
    k--;
    for (int i = n - 1; i >= 0; i--) {
        long long index = k / factorial;
        k %= factorial;
        // Move the current number to its final position
        for (int j = i; j < n - 1; j++) {
            res[j] = res[j + 1];
        }
        res[n - 1] = res[index + i];
        factorial /= (n - i);
    }
    
    return res;
    
}