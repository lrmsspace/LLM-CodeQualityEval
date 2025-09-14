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
    // Use QuickSelect algorithm
    return quickSelect(nums, 0, numsSize - 1, numsSize - k);
    
    // Recursive helper function for QuickSelect
    int partition(int* nums, int left, int right) {
        int pivot = nums[right];
        int i = left - 1;
        for (int j = left; j <= right - 1; j++) {
            if (nums[j] > pivot) {
                i++;
                swap(nums, i, j);
            }
        }
        swap(nums, i + 1, right);
        return i + 1;
    }
    
    int quickSelect(int* nums, int left, int right, int k) {
        if (left == right) {
            return nums[left];
        }
        
        int pivotIndex = partition(nums, left, right);
        
        if (k == pivotIndex) {
            return nums[k];
        } else if (k < pivotIndex) {
            return quickSelect(nums, left, pivotIndex - 1, k);
        } else {
            return quickSelect(nums, pivotIndex + 1, right, k);
        }
    }
    
    void swap(int* nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    // Test the function
    int nums1[] = {3,2,1,5,6,4};
    int k1 = 2;
    printf("The kth largest element in nums1 is: %d\n", findKthLargest(nums1, sizeof(nums1) / sizeof(nums1[0]), k1));
    
    int nums2[] = {3,2,3,1,2,4,5,5,6};
    int k2 = 4;
    printf("The kth largest element in nums2 is: %d\n", findKthLargest(nums2, sizeof(nums2) / sizeof(nums2[0]), k2));
    
    return 0;
    
}