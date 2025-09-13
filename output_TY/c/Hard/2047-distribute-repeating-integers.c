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
bool canDistribute(int* nums, int numsSize, int* quantity, int quantitySize){
    int i, j, k, cnt[1001] = {0}, sum = 0, max_cnt = 0;
    for (i = 0; i < numsSize; i++) cnt[nums[i]]++;
    for (i = 0; i < 1001; i++) sum += cnt[i], max_cnt = max(max_cnt, cnt[i]);
    for (i = 0; i < quantitySize; i++) sum -= quantity[i];
    if (sum < 0) return false;
    for (i= 0; i < quantitySize; i++) {
        for (j = 0; j < 1001; j++) {
            if (cnt[j] >= quantity[i] && cnt[j] - quantity[i] <= sum) {
                cnt[j] -= quantity[i];
                sum -= quantity[i];
                break;
            }
        }
    }
    return sum == 0;
}