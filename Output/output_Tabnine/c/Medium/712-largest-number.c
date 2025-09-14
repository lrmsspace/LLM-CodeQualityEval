/**https://leetcode.com/problems/largest-number/ */
//Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
//Since the result may be very large, so you need to return a string instead of an integer.
// 
//Example 1:
//Input: nums = [10,2]
//Output: "210"
//Example 2:
//Input: nums = [3,30,34,5,9]
//Output: "9534330"
// 
//Constraints:
//	1 <= nums.length <= 100
//	0 <= nums[i] <= 109
char* largestNumber(int* nums, int numsSize) {
    // Sort the numbers in descending order using a custom comparator
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Convert the sorted numbers to strings
    char** strNums = malloc(numsSize * sizeof(char*));
    for (int i = 0; i < numsSize; i++) {
        strNums[i] = malloc((numDigits(nums[i]) + 1) * sizeof(char));
        sprintf(strNums[i], "%d", nums[i]);
    }
    
    // Merge the strings to form the largest number
    char* result = mergeStrings(strNums, numsSize);
    
    // Free the allocated memory
    for (int i = 0; i < numsSize; i++) {
        free(strNums[i]);
    }
    free(strNums);
    
    return result;
    
}