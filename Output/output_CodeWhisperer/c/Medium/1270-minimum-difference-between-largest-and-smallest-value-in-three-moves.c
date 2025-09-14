/**https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/ */
//You are given an integer array nums.
//In one move, you can choose one element of nums and change it to any value.
//Return the minimum difference between the largest and smallest value of nums after performing at most three moves.
// 
//Example 1:
//Input: nums = [5,3,2,4]
//Output: 0
//Explanation: We can make at most 3 moves.
//In the first move, change 2 to 3. nums becomes [5,3,3,4].
//In the second move, change 4 to 3. nums becomes [5,3,3,3].
//In the third move, change 5 to 3. nums becomes [3,3,3,3].
//After performing 3 moves, the difference between the minimum and maximum is 3 - 3 = 0.
//Example 2:
//Input: nums = [1,5,0,10,14]
//Output: 1
//Explanation: We can make at most 3 moves.
//In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
//In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
//In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
//After performing 3 moves, the difference between the minimum and maximum is 1 - 0 = 1.
//It can be shown that there is no way to make the difference 0 in 3 moves.
//Example 3:
//Input: nums = [3,100,20]
//Output: 0
//Explanation: We can make at most 3 moves.
//In the first move, change 100 to 7. nums becomes [3,7,20].
//In the second move, change 20 to 7. nums becomes [3,7,7].
//In the third move, change 3 to 7. nums becomes [7,7,7].
//After performing 3 moves, the difference between the minimum and maximum is 7 - 7 = 0.
// 
//Constraints:
//	1 <= nums.length <= 105
//	-109 <= nums[i] <= 109
int minDifference(int* nums, int numsSize) {
    if (numsSize <= 4) {
        return 0;
    }
    int min = nums[0];
    int max = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    if (max - min <= 3) {
        return max - min;
    }
    int min1 = min;
    int min2 = min;
    int max1 = max;
    int max2 = max;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < min1) {
            if (nums[i] < min2) {
                min1 = min2;
                min2 = nums[i];
            }
            else {
                min1 = nums[i];
            }
        }
        if (nums[i] > max1) {
            if (nums[i] > max2) {
                max1 = max2;
                max2 = nums[i];
            }
            else {
                max1 = nums[i];
            }
        }
    }
    int diff1 = max1 - min2;
    int diff2 = max2 - min1;
    if (diff1 < diff2) {
        return diff1 < max - min1 ? diff1 : max - min1;
    }
    else {
        return diff2 < max - min2 ? diff2 : max - min2;
    }
}