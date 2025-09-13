/*
 You are given an array nums which is a permutation of [0, 1, 2, ..., n - 1]. The score of any permutation of [0, 1, 2, ..., n - 1] named perm is defined as:
 score(perm) = |perm[0] - nums[perm[1]]| + |perm[1] - nums[perm[2]]| + ... + |perm[n - 1] - nums[perm[0]]|
 Return the permutation perm which has the minimum possible score. If multiple permutations exist with this score, return the one that is lexicographically smallest among them.
 Example 1:
 Input: nums = [1,0,2]
 Output: [0,1,2]
 Explanation:
 The lexicographically smallest permutation with minimum cost is [0,1,2]. The cost of this permutation is |0 - 0| + |1 - 2| + |2 - 1| = 2.
 Example 2:
 Input: nums = [0,2,1]
 Output: [0,2,1]
 Explanation:
 The lexicographically smallest permutation with minimum cost is [0,2,1]. The cost of this permutation is |0 - 1| + |2 - 2| + |1 - 0| = 2.
 Constraints:
 2 <= n == nums.length <= 14
 nums is a permutation of [0, 1, 2, ..., n - 1].
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findPermutation(int* nums, int numsSize, int* returnSize) {
    int* perm = (int*)malloc(numsSize * sizeof(int));
    int* visited = (int*)calloc(numsSize, sizeof(int));
    int i, j;

    // Initialize the permutation with the smallest lexicographical order
    for (i = 0; i < numsSize; i++) {
        perm[i] = i;
        visited[i] = 0;
    }

    // Calculate the minimum cost permutation
    for (i = 0; i < numsSize; i++) {
        int minCost = INT_MAX;
        int bestIndex = -1;

        for (j = 0; j < numsSize; j++) {
            if (!visited[j]) {
                int cost = abs(perm[i] - nums[j]);
                if (cost < minCost || (cost == minCost && j < bestIndex)) {
                    minCost = cost;
                    bestIndex = j;
                }
            }
        }

        perm[i] = bestIndex;
        visited[bestIndex] = 1;
    }

    *returnSize = numsSize;
    free(visited);
    return perm;    
}