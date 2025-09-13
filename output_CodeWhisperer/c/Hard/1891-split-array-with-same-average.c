/**https://leetcode.com/problems/split-array-with-same-average/ */
//You are given an integer array nums.
//You should move each element of nums into one of the two arrays A and B such that A and B are non-empty, and average(A) == average(B).
//Return true if it is possible to achieve that and false otherwise.
//Note that for an array arr, average(arr) is the sum of all the elements of arr over the length of arr.
// 
//Example 1:
//Input: nums = [1,2,3,4,5,6,7,8]
//Output: true
//Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have an average of 4.5.
//Example 2:
//Input: nums = [3,1]
//Output: false
// 
//Constraints:
//	1 <= nums.length <= 30
//	0 <= nums[i] <= 104
bool splitArraySameAverage(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    int* dp = (int*)calloc(sum + 1, sizeof(int));
    dp[0] = 1;
    for (int i = 0; i < numsSize; i++) {
        for (int j = sum; j >= nums[i]; j--) {
            dp[j] |= dp[j - nums[i]] << 1;
        }
    }
    for (int i = 1; i < numsSize; i++) {
        if ((sum * i) % numsSize == 0 && dp[sum * i / numsSize] & (1 << i)) {
            return true;
        }
    }
    return false;
    
}