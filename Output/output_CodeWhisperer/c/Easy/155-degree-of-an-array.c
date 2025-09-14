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
    int max = 0;
    int* count = (int*)malloc(sizeof(int) * 50000);
    int* first = (int*)malloc(sizeof(int) * 50000);
    int* last = (int*)malloc(sizeof(int) * 50000);
    for (int i = 0; i < 50000; i++) {
        count[i] = 0;
        first[i] = -1;
        last[i] = -1;
    }
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
        if (first[nums[i]] == -1) {
            first[nums[i]] = i;
        }
        last[nums[i]] = i;
        if (count[nums[i]] > max) {
            max = count[nums[i]];
        }
    }
    int min = numsSize;
    for (int i = 0; i < 50000; i++) {
        if (count[i] == max) {
            int length = last[i] - first[i] + 1;
            if (length < min) {
                min = length;
            }
        }
    }
    free(count);
    free(first);
    free(last);
    return min;
    
}