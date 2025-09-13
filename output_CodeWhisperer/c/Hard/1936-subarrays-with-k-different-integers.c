/**https://leetcode.com/problems/subarrays-with-k-different-integers/ */
//Given an integer array nums and an integer k, return the number of good subarrays of nums.
//A good array is an array where the number of different integers in that array is exactly k.
//	For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
//A subarray is a contiguous part of an array.
// 
//Example 1:
//Input: nums = [1,2,1,2,3], k = 2
//Output: 7
//Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
//Example 2:
//Input: nums = [1,2,1,3,4], k = 3
//Output: 3
//Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	1 <= nums[i], k <= nums.length
int subarraysWithKDistinct(int* nums, int numsSize, int k) {
    int result = 0;

    int left = 0;

    int right = 0;

    int count = 0;

    int* hash = (int*)malloc(sizeof(int) * (numsSize + 1));

    memset(hash, 0, sizeof(int) * (numsSize + 1));

    while (right < numsSize) {

        if (hash[nums[right]] == 0) {

            count++;

        }

        hash[nums[right]]++;

        while (count > k) {

            hash[nums[left]]--;

            if (hash[nums[left]] == 0) {

                count--;

            }

            left++;

        }

        result += right - left + 1;

        right++;

    }


    free(hash);

    return result;
    
}