/**https://leetcode.com/problems/contains-duplicate-ii/ */
//Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
// 
//Example 1:
//Input: nums = [1,2,3,1], k = 3
//Output: true
//Example 2:
//Input: nums = [1,0,1,1], k = 1
//Output: true
//Example 3:
//Input: nums = [1,2,3,1,2,3], k = 2
//Output: false
// 
//Constraints:
//	1 <= nums.length <= 105
//	-109 <= nums[i] <= 109
//	0 <= k <= 105
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    int i, j;
    for (i = 0; i < numsSize - 1; i++) {
        for (j = i + 1; j < numsSize && j - i <= k; j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
    
}