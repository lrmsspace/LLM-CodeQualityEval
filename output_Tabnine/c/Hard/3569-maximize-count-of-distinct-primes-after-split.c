/*
 You are given an integer array nums having length n and a 2D integer array queries where queries[i] = [idx, val].
 For each query:
 Update nums[idx] = val.
 Choose an integer k with 1 <= k < n to split the array into the non-empty prefix nums[0..k-1] and suffix nums[k..n-1] such that the sum of the counts of distinct prime values in each part is maximum.
 Note: The changes made to the array in one query persist into the next query.
 Return an array containing the result for each query, in the order they are given.
 Example 1:
 Input: nums = [2,1,3,1,2], queries = [[1,2],[3,3]]
 Output: [3,4]
 Explanation:
 Initially nums = [2, 1, 3, 1, 2].
 After 1st query, nums = [2, 2, 3, 1, 2]. Split nums into [2] and [2, 3, 1, 2]. [2] consists of 1 distinct prime and [2, 3, 1, 2] consists of 2 distinct primes. Hence, the answer for this query is 1 + 2 = 3.
 After 2nd query, nums = [2, 2, 3, 3, 2]. Split nums into [2, 2, 3] and [3, 2] with an answer of 2 + 2 = 4.
 The output is [3, 4].
 Example 2:
 Input: nums = [2,1,4], queries = [[0,1]]
 Output: [0]
 Explanation:
 Initially nums = [2, 1, 4].
 After 1st query, nums = [1, 1, 4]. There are no prime numbers in nums, hence the answer for this query is 0.
 The output is [0].
 Constraints:
 2 <= n == nums.length <= 5 * 104
 1 <= queries.length <= 5 * 104
 1 <= nums[i] <= 105
 0 <= queries[i][0] < nums.length
 1 <= queries[i][1] <= 105
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maximumCount(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int* result = malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;
    for (int i = 0; i < queriesSize; i++) {
        int idx = queries[i][0];
        int val = queries[i][1];
        nums[idx] = val;
        
        int count[10001] = {0};
        int distinctCount = 0;
        
        for (int j = 0; j <= idx; j++) {
            if (nums[j] > 1) {
                for (int k = 2; k * k <= nums[j]; k++) {
                    if (nums[j] % k == 0) {
                        if (k!= nums[j] / k) {
                            count[k]++;
                            count[nums[j] / k]++;
                        } else {
                            count[k]++;
                        }
                        distinctCount++;
                        break;
                    }
                }
            }
            else if (nums[j] == 1) {
                count[1]++;
                distinctCount++;
            }
            else {
                break;
            }

            if (distinctCount > 0 && (distinctCount == idx - j + 1 || count[nums[j]] > count[nums[j + 1]])) {
                result[i] = distinctCount;
                break;
            }
        }
        else {
            result[i] = distinctCount;
        }
        // Split nums into prefix and suffix with maximum distinct prime count  
        // Your code here
    }   
    return result;
    
}