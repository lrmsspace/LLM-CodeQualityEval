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
    int count[50000] = {0};
    int minLen = numsSize + 1;
    int minCount = INT_MAX;
    int start = 0;
    int end = 0;
    int degree = 0;
    
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
        if (count[nums[i]] == 1) {
            degree = 1;
        } else {
            degree = i - start + 1;
        }
        
        if (degree == minCount) {
            minLen = min(minLen, i - start + 1);
        } else if (degree < minCount) {
            minCount = degree;
            minLen = i - start + 1;
        }
        
        while (count[nums[start]] > 1) {
            count[nums[start]]--;
            start++;
        }
    }
    
    return minLen;
}