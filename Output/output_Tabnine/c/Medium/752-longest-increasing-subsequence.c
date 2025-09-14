/**https://leetcode.com/problems/longest-increasing-subsequence/ */
//Given an integer array nums, return the length of the longest strictly increasing subsequence.
// 
//Example 1:
//Input: nums = [10,9,2,5,3,7,101,18]
//Output: 4
//Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
//Example 2:
//Input: nums = [0,1,0,3,2,3]
//Output: 4
//Example 3:
//Input: nums = [7,7,7,7,7,7,7]
//Output: 1
// 
//Constraints:
//	1 <= nums.length <= 2500
//	-104 <= nums[i] <= 104
// 
//Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    
    int* tails = (int*)malloc(numsSize * sizeof(int));
    int size = 1;
    tails[0] = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > tails[size - 1]) {
            tails[size++] = nums[i];
        } else {
            int left = 0;
            int right = size - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (tails[mid] < nums[i]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            tails[left] = nums[i];
        }
    }
    
    free(tails);
    return size;
    
}