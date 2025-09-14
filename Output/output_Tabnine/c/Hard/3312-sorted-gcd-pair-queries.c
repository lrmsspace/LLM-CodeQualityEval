/*
 You are given an integer array nums of length n and an integer array queries.
 Let gcdPairs denote an array obtained by calculating the GCD of all possible pairs (nums[i], nums[j]), where 0 <= i < j < n, and then sorting these values in ascending order.
 For each query queries[i], you need to find the element at index queries[i] in gcdPairs.
 Return an integer array answer, where answer[i] is the value at gcdPairs[queries[i]] for each query.
 The term gcd(a, b) denotes the greatest common divisor of a and b.
 Example 1:
 Input: nums = [2,3,4], queries = [0,2,2]
 Output: [1,2,2]
 Explanation:
 gcdPairs = [gcd(nums[0], nums[1]), gcd(nums[0], nums[2]), gcd(nums[1], nums[2])] = [1, 2, 1].
 After sorting in ascending order, gcdPairs = [1, 1, 2].
 So, the answer is [gcdPairs[queries[0]], gcdPairs[queries[1]], gcdPairs[queries[2]]] = [1, 2, 2].
 Example 2:
 Input: nums = [4,4,2,1], queries = [5,3,1,0]
 Output: [4,2,1,1]
 Explanation:
 gcdPairs sorted in ascending order is [1, 1, 1, 2, 2, 4].
 Example 3:
 Input: nums = [2,2], queries = [0,0]
 Output: [2,2]
 Explanation:
 gcdPairs = [2].
 Constraints:
 2 <= n == nums.length <= 105
 1 <= nums[i] <= 5 * 104
 1 <= queries.length <= 105
 0 <= queries[i] < n * (n - 1) / 2
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* gcdValues(int* nums, int numsSize, long long* queries, int queriesSize, int* returnSize) {
    int* gcdPairs = (int*)malloc(sizeof(int) * queriesSize * (queriesSize - 1) / 2);
    int count = 0;
    
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            gcdPairs[count++] = gcd(nums[i], nums[j]);
        }
    }
    
    qsort(gcdPairs, count, sizeof(int), cmp);
    
    int* answer = (int*)malloc(sizeof(int) * queriesSize);
    for (int i = 0; i < queriesSize; i++) {
        answer[i] = gcdPairs[queries[i]];
    }
    
    *returnSize = queriesSize;
    return answer;
    
}