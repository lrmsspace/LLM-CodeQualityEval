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
    int i, j, l, r, count, ans;
    int *left, *right;
    left = (int*)malloc(sizeof(int)*numsSize);
    right = (int*)malloc(sizeof(int)*numsSize);
    i = 0;
    count = 0;
    for (j = 0; j < numsSize; j++) {
        if (nums[j] % 2 == 1) {
            left[i] = count;
            count = 0;
            i++;
        } else {
            count++;
        }
    }
    left[i] = count;
    i = 0;
    count = 0;
    for (j = numsSize - 1; j >= 0; j--) {
        if (nums[j] % 2 == 1) {
            right[i] = count;
            count = 0;
            i++;
        } else {
            count++;
        }
    }
    right[i] = count;
    ans = 0;
    for (i = 0; i < numsSize; i++) {
        l = i;
        r = i;
        count = 0;
        while (l < numsSize && left[l] < k) {
            count++;
            l++;
        }
        while (r < numsSize && right[r] < k) {
            count++;
            r++;
        }
        ans += count;
    }
    return ans;    
}