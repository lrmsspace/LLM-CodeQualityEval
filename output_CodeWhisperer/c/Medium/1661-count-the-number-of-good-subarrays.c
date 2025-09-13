/**https://leetcode.com/problems/count-the-number-of-good-subarrays/ */
//Given an integer array nums and an integer k, return the number of good subarrays of nums.
//A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [1,1,1,1,1], k = 10
//Output: 1
//Explanation: The only good subarray is the array nums itself.
//Example 2:
//Input: nums = [3,1,4,3,2,2,4], k = 2
//Output: 4
//Explanation: There are 4 different good subarrays:
//- [3,1,4,3,2,2] that has 2 pairs.
//- [3,1,4,3,2,2,4] that has 3 pairs.
//- [1,4,3,2,2,4] that has 2 pairs.
//- [4,3,2,2,4] that has 2 pairs.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i], k <= 109
long long countGood(int* nums, int numsSize, int k) {
    
    int count = 0;
    int left = 0;
    int right = 0;
    int pairs = 0;
    int* hash = (int*)calloc(100001, sizeof(int));
    while (right < numsSize) {
        hash[nums[right]]++;
        if (hash[nums[right]] > 1) {
            pairs += hash[nums[right]] - 1;
        }
        while (pairs >= k) {
            count += numsSize - right;
            hash[nums[left]]--;
            if (hash[nums[left]] > 0) {
                pairs -= hash[nums[left]];
            }
            left++;
        }
        right++;
    }
    free(hash);
    return count;
}