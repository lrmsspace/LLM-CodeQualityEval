/**https://leetcode.com/problems/degree-of-an-array/ */
//Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
//Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
// 
//Example 1:
//Input: nums = [1,2,2,3,1]
//Output: 2
//Explanation: 
//The input array has a degree of 2 because both elements 1 and 2 appear twice.
//Of the subarrays that have the same degree:
//[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
//The shortest length is 2. So return 2.
//Example 2:
//Input: nums = [1,2,2,3,1,4,2]
//Output: 6
//Explanation: 
//The degree is 3 because the element 2 is repeated 3 times.
//So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
// 
//Constraints:
//	nums.length will be between 1 and 50,000.
//	nums[i] will be an integer between 0 and 49,999.
int findShortestSubArray(int* nums, int numsSize) {
    int i, j, k, max = 0, min = numsSize, count = 0;
    int *num = (int *)malloc(sizeof(int) * 50000);
    int *start = (int *)malloc(sizeof(int) * 50000);
    int *end = (int *)malloc(sizeof(int) * 50000);
    for (i = 0; i < 50000; i++) {
        num[i] = 0;
        start[i] = -1;
        end[i] = -1;
    }
    for (i = 0; i < numsSize; i++) {
        num[nums[i]]++;
        if (start[nums[i]] == -1) {
            start[nums[i]] = i;
        }
        end[nums[i]] = i;
        if (num[nums[i]] > max) {
            max = num[nums[i]];
        }
    }
    for (i = 0; i < 50000; i++) {
        if (num[i] == max) {
            if (end[i] - start[i] + 1 < min) {
                min = end[i] - start[i] + 1;
            }
        }
    }
    return min;    
}