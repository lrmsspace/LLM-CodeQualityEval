25
/*
 * Return the number of ways you can make this split.
 */
int beautifulSplits(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize - 2; i++) {
        int prefix1[51] = {0};
        int prefix2[51] = {0};
        for (int j = 0; j <= i; j++) {
            prefix1[nums[j]]++;
        }
        for (int j = i + 1; j < numsSize - 1; j++) {
            prefix2[nums[j]]++;
        }
        for (int j = 0; j < 51; j++) {
            if (prefix1[j] && prefix2[j]) {
                count++;
                break;
            }
        }
    }
    return count;
}
 You are given an array nums.
 A split of an array nums is beautiful if:
 The array nums is split into three subarrays: nums1, nums2, and nums3, such that nums can be formed by concatenating nums1, nums2, and nums3 in that order.
 The subarray nums1 is a prefix of nums2 OR nums2 is a prefix of nums3.
 Return the number of ways you can make this split.
 Example 1:
 Input: nums = [1,1,2,1]
 Output: 2
 Explanation:
 The beautiful splits are:
 A split with nums1 = [1], nums2 = [1,2], nums3 = [1].
 A split with nums1 = [1], nums2 = [1], nums3 = [2,1].
 Example 2:
 Input: nums = [1,2,3,4]
 Output: 0
 Explanation:
 There are 0 beautiful splits.
 Constraints:
 1 <= nums.length <= 5000
 0 <= nums[i] <= 50
*/

int beautifulSplits(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize - 2; i++) {
        int prefix1[51] = {0};
        int prefix2[51] = {0};
        for (int j = 0; j <= i; j++) {
            prefix1[nums[j]]++;
        }
        for (int j = i + 1; j < numsSize - 1; j++) {
            prefix2[nums[j]]++;
        }
        for (int j = 0; j < 51; j++) {
            if (prefix1[j] && prefix2[j]) {
                count++;
                break;
            }
        }
    }
    return count;
    
}