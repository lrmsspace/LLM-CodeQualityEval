/**https://leetcode.com/problems/third-maximum-number/ */
//Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.
// 
//Example 1:
//Input: nums = [3,2,1]
//Output: 1
//Explanation:
//The first distinct maximum is 3.
//The second distinct maximum is 2.
//The third distinct maximum is 1.
//Example 2:
//Input: nums = [1,2]
//Output: 2
//Explanation:
//The first distinct maximum is 2.
//The second distinct maximum is 1.
//The third distinct maximum does not exist, so the maximum (2) is returned instead.
//Example 3:
//Input: nums = [2,2,3,1]
//Output: 1
//Explanation:
//The first distinct maximum is 3.
//The second distinct maximum is 2 (both 2's are counted together since they have the same value).
//The third distinct maximum is 1.
// 
//Constraints:
//	1 <= nums.length <= 104
//	-231 <= nums[i] <= 231 - 1
// 
//Follow up: Can you find an O(n) solution?
int thirdMax(int* nums, int numsSize){
    int i, j, k, temp, count = 0, max = 0, max1 = 0, max2 = 0, max3 = 0;
    
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != nums[i + 1]) {
            count++;
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > max) {
            max3 = max2;
            max2 = max1;
            max1 = max;
            max = nums[i];
        }
        else if (nums[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        }
    }
    if (count >= 3) {
        return max3;
    }
    else {
        return max;
    }
}