/**https://leetcode.com/problems/contains-duplicate/ */
//Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
// 
//Example 1:
//Input: nums = [1,2,3,1]
//Output: true
//Explanation:
//The element 1 occurs at the indices 0 and 3.
//Example 2:
//Input: nums = [1,2,3,4]
//Output: false
//Explanation:
//All elements are distinct.
//Example 3:
//Input: nums = [1,1,1,3,3,4,3,2,4,2]
//Output: true
// 
//Constraints:
//	1 <= nums.length <= 105
//	-109 <= nums[i] <= 109
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int bsearch(int nums[], int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;   
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
bool containsDuplicate(int* nums, int numsSize) {
    int nums_set[numsSize];
    int nums_set_size = 0;
    for (int i = 0; i < numsSize; i++) {
        if (bsearch(nums, numsSize, nums[i]) != -1) {
            return true;
        }
        nums_set[nums_set_size++] = nums[i];
        qsort(nums_set, nums_set_size, sizeof(int), compare);
    }
    return false;
}   