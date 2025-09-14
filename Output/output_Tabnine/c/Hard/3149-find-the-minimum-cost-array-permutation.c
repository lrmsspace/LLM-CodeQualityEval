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
    int* perm = malloc(sizeof(int) * numsSize);
    int* cost = malloc(sizeof(int) * numsSize);
    int* visited = malloc(sizeof(int) * numsSize);
    
    for (int i = 0; i < numsSize; i++) {
        perm[i] = nums[i];
        cost[i] = 0;
        visited[i] = 0;
    }
    
    for (int i = 0; i < numsSize - 1; i++) {
        int diff = abs(perm[i] - perm[i + 1]);
        cost[i] += diff;
        cost[i + 1] += diff;
    }
    
    int minCost = INT_MAX;  
    int* minPerm = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        minPerm[i] = perm[i];
    }
    int minIndex = 0;
    for (int i = 0; i < numsSize; i++) {
        int min = INT_MAX;
        int minIndex = -1;
        for (int j = 0; j < numsSize; j++) {
            if (visited[j] == 0 && cost[j] < min) {
                min = cost[j];
                minIndex = j;
            }
        }
        visited[minIndex] = 1;
        perm[i] = minIndex + 1;
        for (int j = 0; j < numsSize; j++) {
            if (j!= minIndex && j!= i) {
                cost[j] -= abs(perm[i] - perm[j]);
            }
        }
        if (min < minCost) {
            minCost = min;
            for (int j = 0; j < numsSize; j++) {
                minPerm[j] = perm[j];
            }
            minIndex = i;
        }
    }
    *returnSize = numsSize;
    return minPerm;
    
}