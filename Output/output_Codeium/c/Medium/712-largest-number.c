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

int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    int div1 = 1;
    int div2 = 1;
    while (num1 / div1 != 0) {
        div1 *= 10;
    }
    while (num2 / div2 != 0) {
        div2 *= 10;
    }
    int num1_first = (num1 / div1) * 10 + (num2 / div2);
    int num2_first = (num2 / div2) * 10 + (num1 / div1);
    return num2_first - num1_first;
}
char* largestNumber(int* nums, int numsSize) {
    
    int nums_str[numsSize];
    for (int i = 0; i < numsSize; i++) {
        nums_str[i] = nums[i];
    }
    qsort(nums_str, numsSize, sizeof(int), compare);
    char* res = (char*)malloc((numsSize + 1) * sizeof(char));
    int idx = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums_str[i];
        if (num == 0 && idx == 0) {
            continue;
        }
        int div = 1;
        while (num / div != 0) {
            res[idx++] = (num / div) % 10 + '0';
            div *= 10;
        }
    }
    res[idx] = '\0';
    return res;
}
    