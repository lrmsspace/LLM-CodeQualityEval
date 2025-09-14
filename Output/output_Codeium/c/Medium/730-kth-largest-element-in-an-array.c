/**https://leetcode.com/problems/kth-largest-element-in-an-array/ */
//Given an integer array nums and an integer k, return the kth largest element in the array.
//Note that it is the kth largest element in the sorted order, not the kth distinct element.
//Can you solve it without sorting?
// 
//Example 1:
//Input: nums = [3,2,1,5,6,4], k = 2
//Output: 5
//Example 2:
//Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
//Output: 4
// 
//Constraints:
//	1 <= k <= nums.length <= 105
//	-104 <= nums[i] <= 104
int findKthLargest(int* nums, int numsSize, int k) {
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int pivot = nums[right];
        int i = left;
        for (int j = left; j < right; j++) {
            if (nums[j] >= pivot) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
            }
        }
        int temp = nums[i];
        nums[i] = nums[right];
        nums[right] = temp;
        if (i == k - 1)
            return nums[i];
        else if (i > k - 1)
            right = i - 1;
        else
            left = i + 1;
    }
    return 0;
    
}