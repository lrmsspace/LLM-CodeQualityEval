/**https://leetcode.com/problems/maximum-gap/ */
//Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
//You must write an algorithm that runs in linear time and uses linear extra space.
// 
//Example 1:
//Input: nums = [3,6,9,1]
//Output: 3
//Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
//Example 2:
//Input: nums = [10]
//Output: 0
//Explanation: The array contains less than 2 elements, therefore return 0.
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= nums[i] <= 109
int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) {
        return 0;
    }
    int max = 0;
    int min = 0x7fffffff;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    int bucketSize = fmax(1, (max - min) / (numsSize - 1));
    int bucketNum = (max - min) / bucketSize + 1;
    int* bucketMax = (int*)malloc(bucketNum * sizeof(int));
    int* bucketMin = (int*)malloc(bucketNum * sizeof(int));
    for (int i = 0; i < bucketNum; i++) {
        bucketMax[i] = -1;
        bucketMin[i] = -1;
    }
    for (int i = 0; i < numsSize; i++) {
        int index = (nums[i] - min) / bucketSize;
        if (bucketMax[index] == -1) {
            bucketMax[index] = nums[i];
            bucketMin[index] = nums[i];
        } else {
            if (nums[i] > bucketMax[index]) {
                bucketMax[index] = nums[i];
            }
            if (nums[i] < bucketMin[index]) {
                bucketMin[index] = nums[i];
            }
        }
    }
    int res = 0;
    int pre = -1;
    for (int i = 0; i < bucketNum; i++) {
        if (bucketMin[i] == -1) {
            continue;
        }
        if (pre != -1) {
            res = fmax(res, bucketMin[i] - bucketMax[pre]);
        }
        pre = i;
    }
    return res;    
}