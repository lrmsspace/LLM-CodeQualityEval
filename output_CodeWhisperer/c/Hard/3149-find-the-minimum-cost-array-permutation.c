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
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    // Initialize the result array with the sorted order
    for (int i = 0; i < numsSize; i++) {
        result[i] = i;
    }
    
    // Find the lexicographically smallest permutation with minimum cost
    int minCost = INT_MAX;
    int* minPerm = (int*)malloc(numsSize * sizeof(int));
    
    do {
        int cost = 0;
        for (int i = 0; i < numsSize; i++) {
            cost += abs(result[i] - nums[(i + 1) % numsSize]);
        }
        
        if (cost < minCost) {
            minCost = cost;
            memcpy(minPerm, result, numsSize * sizeof(int));
        }
    } while (next_permutation(result, result + numsSize, greater<int>()));
    
    free(result);
    return minPerm;    
}