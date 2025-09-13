/**https://leetcode.com/problems/reverse-pairs/ */
//Given an integer array nums, return the number of reverse pairs in the array.
//A reverse pair is a pair (i, j) where:
//	0 <= i < j < nums.length and
//	nums[i] > 2 * nums[j].
// 
//Example 1:
//Input: nums = [1,3,2,3,1]
//Output: 2
//Explanation: The reverse pairs are:
//(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
//(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
//Example 2:
//Input: nums = [2,4,3,5,1]
//Output: 3
//Explanation: The reverse pairs are:
//(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
//(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
//(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
// 
//Constraints:
//	1 <= nums.length <= 5 * 104
//	-231 <= nums[i] <= 231 - 1  
int mergeAndCount(int* nums, int* temp, int left, int mid, int right) {
    int i = left;    // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;    // Starting index to be sorted
    int count = 0;

    while (i <= mid && j <= right) {
        if (nums[i] <= 2LL * nums[j]) {
            i++;
        } else {
            count += (mid - i + 1);
            j++;
        }
    }

    i = left;
    j = mid + 1;
    
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = nums[i++];
    }

    while (j <= right) {
        temp[k++] = nums[j++];
    }

    for (i = left; i <= right; i++) {
        nums[i] = temp[i];
    }

    return count;
}

int mergeSortAndCount(int* nums, int* temp, int left, int right) {
    int mid, count = 0;
    if (left < right) {
        mid = (left + right) / 2;

        count += mergeSortAndCount(nums, temp, left, mid);
        count += mergeSortAndCount(nums, temp, mid + 1, right);

        count += mergeAndCount(nums, temp, left, mid, right);
    }
    return count;
}

int reversePairs(int* nums, int numsSize) {
    int* temp = (int*)malloc(sizeof(int) * numsSize);
    int result = mergeSortAndCount(nums, temp, 0, numsSize - 1);
    free(temp);
    return result;
}

