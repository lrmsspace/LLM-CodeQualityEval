/**https://leetcode.com/problems/count-number-of-nice-subarrays/ */
//Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
//Return the number of nice sub-arrays.
// 
//Example 1:
//Input: nums = [1,1,2,1,1], k = 3
//Output: 2
//Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
//Example 2:
//Input: nums = [2,4,6], k = 1
//Output: 0
//Explanation: There are no odd numbers in the array.
//Example 3:
//Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
//Output: 16
// 
//Constraints:
//	1 <= nums.length <= 50000
//	1 <= nums[i] <= 10^5
//	1 <= k <= nums.length
int numberOfSubarrays(int* nums, int numsSize, int k) {
    int count = 0;
    int oddCount = 0;
    int left = 0;
    int right = 0;
    while (right < numsSize) {
        if (nums[right] % 2 == 1) {
            oddCount++;
        }
        while (oddCount > k) {
            if (nums[left] % 2 == 1) {
                oddCount--;
            }
            left++;
        }
        if (oddCount == k) {
            int temp = right;
            while (temp < numsSize && nums[temp] % 2 == 0) {
                temp++;
            }
            count += temp - left + 1;
        }
        right++;
    }
    return count;
}