/**https://leetcode.com/problems/wiggle-sort-ii/ */
//Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
//You may assume the input array always has a valid answer.
// 
//Example 1:
//Input: nums = [1,5,1,1,6,4]
//Output: [1,6,1,5,1,4]
//Explanation: [1,4,1,5,1,6] is also accepted.
//Example 2:
//Input: nums = [1,3,2,2,3,1]
//Output: [2,3,1,3,1,2]
// 
//Constraints:
//	1 <= nums.length <= 5 * 104
//	0 <= nums[i] <= 5000
//	It is guaranteed that there will be an answer for the given input nums.
// 
//Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?
void wiggleSort(int* nums, int numsSize) {
    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Calculate the median
    int mid = (numsSize - 1) / 2;
    int median = nums[mid];
    
    // Find the two pointers to the two halves of the sorted array
    int left = 0, right = numsSize - 1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < median) {
            swap(&nums[left++], &nums[i]);
        } else if (nums[i] > median) {
            swap(&nums[right--], &nums[i]);
        }
    }
    
    // Place the elements in the correct positions based on the parity of the index
    int n = numsSize;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            swap(&nums[i], &nums[left++]);
        } else {
            swap(&nums[i], &nums[right--]);
        }
    }
    
    // Reverse the array to get the final result
    reverseArray(nums, 0, n - 1);
    
    // Helper function to swap elements in the array
    void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
    // Helper function to reverse the elements in the array
    void reverseArray(int* nums, int start, int end) {
        while (start < end) {
            swap(&nums[start++], &nums[end--]);
        }
    }
    
    // Helper function to compare two integers
    int compare(const void* a, const void* b) {
        return *(int*)a - *(int*)b;
    }
    
    // Helper function to print the array
    void printArray(int* nums, int numsSize) {
        for (int i = 0; i < numsSize; i++) {
            printf("%d ", nums[i]);
        }
        printf("\n");
    }
    
    // Test the function
    int nums1[] = {1, 5, 1, 1, 6, 4};
    wiggleSort(nums1, sizeof(nums1) / sizeof(nums1[0]));
    printArray(nums1, sizeof(nums1) / sizeof(nums1[0]));
    
    int nums2[] = {1, 3, 2, 2, 3, 1};
    wiggleSort(nums2, sizeof(nums2) / sizeof(nums2[0]));
    printArray(nums2, sizeof(nums2) / sizeof(nums2[0]));
    
    return 0;
    
}