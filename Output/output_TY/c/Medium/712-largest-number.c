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
char * largestNumber(int* nums, int numsSize){
    char *res = (char *)malloc(sizeof(char) * 1000);
    memset(res, 0, sizeof(char) * 1000);
    int i, j, k;
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] < nums[j]) {
                int tmp = nums[i];
            }
        }
    }
    return res;
}