/**https://leetcode.com/problems/summary-ranges/ */
//You are given a sorted unique integer array nums.
//A range [a,b] is the set of all integers from a to b (inclusive).
//Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
//Each range [a,b] in the list should be output as:
//	"a->b" if a != b
//	"a" if a == b
// 
//Example 1:
//Input: nums = [0,1,2,4,5,7]
//Output: ["0->2","4->5","7"]
//Explanation: The ranges are:
//[0,2] --> "0->2"
//[4,5] --> "4->5"
//[7,7] --> "7"
//Example 2:
//Input: nums = [0,2,3,4,6,8,9]
//Output: ["0","2->4","6","8->9"]
//Explanation: The ranges are:
//[0,0] --> "0"
//[2,4] --> "2->4"
//[6,6] --> "6"
//[8,9] --> "8->9"
// 
//Constraints:
//	0 <= nums.length <= 20
//	-231 <= nums[i] <= 231 - 1
//	All the values of nums are unique.
//	nums is sorted in ascending order.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    char** result = (char**)malloc(sizeof(char*) * numsSize);
    *returnSize = 0;
    int start = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1] + 1) {
            result[*returnSize] = (char*)malloc(sizeof(char) * 20);
            if (start == i - 1) {
                sprintf(result[*returnSize], "%d", nums[start]);
            } else {
                sprintf(result[*returnSize], "%d->%d", nums[start], nums[i - 1]);
            }
            (*returnSize)++;
            start = i;
        }
    }
    result[*returnSize] = (char*)malloc(sizeof(char) * 20);
    if (start == numsSize - 1) {
        sprintf(result[*returnSize], "%d", nums[start]);
    } else {
        sprintf(result[*returnSize], "%d->%d", nums[start], nums[numsSize - 1]);
    }
    (*returnSize)++;
    return result;    
}