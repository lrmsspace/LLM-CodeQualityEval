/*
 An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
 You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that subarray nums[fromi..toi] is special or not.
 Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.
 Example 1:
 Input: nums = [3,4,1,2,6], queries = [[0,4]]
 Output: [false]
 Explanation:
 The subarray is [3,4,1,2,6]. 2 and 6 are both even.
 Example 2:
 Input: nums = [4,3,1,6], queries = [[0,2],[2,3]]
 Output: [false,true]
 Explanation:
 The subarray is [4,3,1]. 3 and 1 are both odd. So the answer to this query is false.
 The subarray is [1,6]. There is only one pair: (1,6) and it contains numbers with different parity. So the answer to this query is true.
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 105
 1 <= queries.length <= 105
 queries[i].length == 2
 0 <= queries[i][0] <= queries[i][1] <= nums.length - 1
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* isArraySpecial(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    
    int i, j, k, n, m, sum, count;
    int *a, *b;
    bool *c;
    
    a = (int *)malloc(sizeof(int) * numsSize);
    b = (int *)malloc(sizeof(int) * numsSize);
    c = (bool *)malloc(sizeof(bool) * queriesSize);
    
    for (i = 0; i < numsSize; i++) {
        a[i] = nums[i];
    }
    
    for (i = 0; i < queriesSize; i++) {
        n = queries[i][0];
        m = queries[i][1];  
    }
    for (i = 0; i < numsSize; i++) {
        sum = 0;
        for (j = 0; j < numsSize; j++) {
            if (a[j] > a[i]) {
                sum++;
            }
        }
        b[i] = sum;
    }
    return b[n] - b[m];
}