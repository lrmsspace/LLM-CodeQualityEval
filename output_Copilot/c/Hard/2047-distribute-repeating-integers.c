/**https://leetcode.com/problems/distribute-repeating-integers/ */
//You are given an array of n integers, nums, where there are at most 50 unique values in the array. You are also given an array of m customer order quantities, quantity, where quantity[i] is the amount of integers the ith customer ordered. Determine if it is possible to distribute nums such that:
//	The ith customer gets exactly quantity[i] integers,
//	The integers the ith customer gets are all equal, and
//	Every customer is satisfied.
//Return true if it is possible to distribute nums according to the above conditions.
// 
//Example 1:
//Input: nums = [1,2,3,4], quantity = [2]
//Output: false
//Explanation: The 0th customer cannot be given two different integers.
//Example 2:
//Input: nums = [1,2,3,3], quantity = [2]
//Output: true
//Explanation: The 0th customer is given [3,3]. The integers [1,2] are not used.
//Example 3:
//Input: nums = [1,1,2,2], quantity = [2,2]
//Output: true
//Explanation: The 0th customer is given [1,1], and the 1st customer is given [2,2].
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 105
//	1 <= nums[i] <= 1000
//	m == quantity.length
//	1 <= m <= 10
//	1 <= quantity[i] <= 105
//	There are at most 50 unique values in nums.
bool canDistribute(int* nums, int numsSize, int* quantity, int quantitySize) {
    int cnt[1001];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < numsSize; i++) {
        cnt[nums[i]]++;
    }
    int m = 0;
    for (int i = 1; i <= 1000; i++) {
        if (cnt[i] > 0) {
            nums[m++] = cnt[i];
        }
    }
    numsSize = m;
    int dp[1 << quantitySize];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int mask = 1; mask < (1 << quantitySize); mask++) {
        for (int i = 0; i < numsSize; i++) {
            if (dp[mask]) {
                break;
            }
            if (nums[i] == 0) {
                continue;
            }
            int newMask = mask;
            for (int j = 0; j < quantitySize; j++) {
                if (mask & (1 << j)) {
                    continue;
                }
                if (nums[i] >= quantity[j]) {
                    newMask |= (1 << j);
                }
            }
            if (newMask != mask) {
                nums[i] -= quantity[newMask ^ mask];
                dp[newMask] = 1;
            }
        }
    }
    return dp[(1 << quantitySize) - 1];    
}