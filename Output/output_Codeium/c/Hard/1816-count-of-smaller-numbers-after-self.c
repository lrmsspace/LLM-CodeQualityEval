/**https://leetcode.com/problems/count-of-smaller-numbers-after-self/ */
//Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].
// 
//Example 1:
//Input: nums = [5,2,6,1]
//Output: [2,1,1,0]
//Explanation:
//To the right of 5 there are 2 smaller elements (2 and 1).
//To the right of 2 there is only 1 smaller element (1).
//To the right of 6 there is 1 smaller element (1).
//To the right of 1 there is 0 smaller element.
//Example 2:
//Input: nums = [-1]
//Output: [0]
//Example 3:
//Input: nums = [-1,-1]
//Output: [0,0]
// 
//Constraints:
//	1 <= nums.length <= 105
//	-104 <= nums[i] <= 104
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */ 
typedef struct {
    int num;
    int index;
} NumIndex;

int compare(const void* a, const void* b) {
    return ((NumIndex*)a)->num - ((NumIndex*)b)->num;
}

void merge(NumIndex* nums, int* count, int left, int mid, int right) {
    int n = right - left + 1;
    NumIndex* temp = (NumIndex*)malloc(n * sizeof(NumIndex));
    int i = left, j = mid + 1, k = 0;
    int rightCounter = 0;

    while (i <= mid && j <= right) {
        if (nums[i].num <= nums[j].num) {
            count[nums[i].index] += rightCounter;
            temp[k++] = nums[i++];
        } else {
            rightCounter++;
            temp[k++] = nums[j++];
        }
    }

    while (i <= mid) {
        count[nums[i].index] += rightCounter;
        temp[k++] = nums[i++];
    }

    while (j <= right) {
        temp[k++] = nums[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        nums[i] = temp[k];
    }

    free(temp);
}

void mergeSort(NumIndex* nums, int* count, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(nums, count, left, mid);
    mergeSort(nums, count, mid + 1, right);
    merge(nums, count, left, mid, right);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    NumIndex* numIndexArray = (NumIndex*)malloc(numsSize * sizeof(NumIndex));
    int* count = (int*)calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        numIndexArray[i].num = nums[i];
        numIndexArray[i].index = i;
    }

    mergeSort(numIndexArray, count, 0, numsSize - 1);

    free(numIndexArray);
    *returnSize = numsSize;
    return count;
}

