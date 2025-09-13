/**https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/ */
//Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
// 
//Example 1:
//Input: nums = [3,10,5,25,2,8]
//Output: 28
//Explanation: The maximum result is 5 XOR 25 = 28.
//Example 2:
//Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
//Output: 127
// 
//Constraints:
//	1 <= nums.length <= 2 * 105
//	0 <= nums[i] <= 231 - 1
int findMaximumXOR(int* nums, int numsSize){
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        int mask = ans | (1 << i);
        HashSet* set = HashSet_create();
        for (int j = 0; j < numsSize; j++) {
            HashSet_add(set, nums[j] & mask);
        }
        int found = 0;
        for (int j = 0; j < numsSize;j++) {
            if (HashSet_contains(set, nums[j] ^ mask)) {
                ans = mask;
                found = 1;
                break;
            }
        }
    }
    return ans;
}