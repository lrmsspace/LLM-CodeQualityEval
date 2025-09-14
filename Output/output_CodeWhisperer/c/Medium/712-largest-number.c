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
    char* result = (char*)malloc(sizeof(char) * 100000);
    int i, j, k;
    char* str = (char*)malloc(sizeof(char) * 100000);
    char* temp = (char*)malloc(sizeof(char) * 100000);
    int* numsCopy = (int*)malloc(sizeof(int) * numsSize);
    for (i = 0; i < numsSize; i++) {
        numsCopy[i] = nums[i];
    }
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            sprintf(str, "%d%d", numsCopy[i], numsCopy[j]);
            sprintf(temp, "%d%d", numsCopy[j], numsCopy[i]);
            if (atoi(temp) > atoi(str)) {
                k = numsCopy[i];
                numsCopy[i] = numsCopy[j];
                numsCopy[j] = k;
            }
        }
    }
    sprintf(result, "");
    for (i = 0; i < numsSize; i++) {
        sprintf(str, "%d", numsCopy[i]);
        strcat(result, str);
    }
    if (result[0] == '0') {
        return "0";
    }
    return result;
}