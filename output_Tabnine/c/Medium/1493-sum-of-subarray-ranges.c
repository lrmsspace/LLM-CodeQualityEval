/**https://leetcode.com/problems/sum-of-subarray-ranges/ */
//You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
//Return the sum of all subarray ranges of nums.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [1,2,3]
//Output: 4
//Explanation: The 6 subarrays of nums are the following:
//[1], range = largest - smallest = 1 - 1 = 0 
//[2], range = 2 - 2 = 0
//[3], range = 3 - 3 = 0
//[1,2], range = 2 - 1 = 1
//[2,3], range = 3 - 2 = 1
//[1,2,3], range = 3 - 1 = 2
//So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
//Example 2:
//Input: nums = [1,3,3]
//Output: 4
//Explanation: The 6 subarrays of nums are the following:
//[1], range = largest - smallest = 1 - 1 = 0
//[3], range = 3 - 3 = 0
//[3], range = 3 - 3 = 0
//[1,3], range = 3 - 1 = 2
//[3,3], range = 3 - 3 = 0
//[1,3,3], range = 3 - 1 = 2
//So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
//Example 3:
//Input: nums = [4,-2,-3,4,1]
//Output: 59
//Explanation: The sum of all subarray ranges of nums is 59.
// 
//Constraints:
//	1 <= nums.length <= 1000
//	-109 <= nums[i] <= 109
// 
//Follow-up: Could you find a solution with O(n) time complexity?
long long subArrayRanges(int* nums, int numsSize) {
    long long res = 0;
    int minVal[numsSize];
    int maxVal[numsSize];
    
    minVal[0] = nums[0];
    maxVal[numsSize - 1] = nums[numsSize - 1];
    
    for (int i = 1; i < numsSize; i++) {
        minVal[i] = nums[i] < minVal[i - 1]? nums[i] : minVal[i - 1];
    }
    
    for (int i = numsSize - 2; i >= 0; i--) {
        maxVal[i] = nums[i] > maxVal[i + 1]? nums[i] : maxVal[i + 1];
    }
    
    for (int i = 0; i < numsSize; i++) {
        res += (maxVal[i] - minVal[i]);
    }
    
    return res;
    
}