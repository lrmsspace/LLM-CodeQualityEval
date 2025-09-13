/**https://leetcode.com/problems/special-permutations/ */
//You are given a 0-indexed integer array nums containing n distinct positive integers. A permutation of nums is called special if:
//	For all indexes 0 <= i < n - 1, either nums[i] % nums[i+1] == 0 or nums[i+1] % nums[i] == 0.
//Return the total number of special permutations. As the answer could be large, return it modulo 109 + 7.
// 
//Example 1:
//Input: nums = [2,3,6]
//Output: 2
//Explanation: [3,6,2] and [2,6,3] are the two special permutations of nums.
//Example 2:
//Input: nums = [1,4,3]
//Output: 2
//Explanation: [3,1,4] and [4,1,3] are the two special permutations of nums.
// 
//Constraints:
//	2 <= nums.length <= 14
//	1 <= nums[i] <= 109
int specialPerm(int* nums, int numsSize) {
    int i, j, k, n, m, res = 0;
    int *dp = (int*)malloc(sizeof(int) * (1 << numsSize));
    memset(dp, 0, sizeof(int) * (1 << numsSize));
    for (i = 0; i < numsSize; i++) {
        dp[1 << i] = 1;
    }
    for (i = 1; i < (1 << numsSize); i++) {
        n = 0;
        for (j = 0; j < numsSize; j++) {
            if (i & (1 << j)) {
                n++;
            }
        }
        for (j = 0; j < numsSize; j++) {
            if (i & (1 << j)) {
                continue;
            }
            m = 0;
            for (k = 0; k < numsSize; k++) {
                if (i & (1 << k)) {
                    if (nums[j] % nums[k] == 0 || nums[k] % nums[j] == 0) {
                        m++;
                    }
                }
            }
            if (m == n - 1) {
                dp[i | (1 << j)] += dp[i];
            }
        }
    }
    for (i = 0; i < (1 << numsSize); i++) {
        res += dp[i];
    }
    free(dp);
    return res;    
}