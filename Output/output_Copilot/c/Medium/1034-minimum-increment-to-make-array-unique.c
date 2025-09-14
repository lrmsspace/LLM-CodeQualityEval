/**https://leetcode.com/problems/minimum-increment-to-make-array-unique/ */
//You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.
//Return the minimum number of moves to make every value in nums unique.
//The test cases are generated so that the answer fits in a 32-bit integer.
// 
//Example 1:
//Input: nums = [1,2,2]
//Output: 1
//Explanation: After 1 move, the array could be [1, 2, 3].
//Example 2:
//Input: nums = [3,2,1,2,1,7]
//Output: 6
//Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
//It can be shown that it is impossible for the array to have all unique values with 5 or less moves.
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= nums[i] <= 105
int minIncrementForUnique(int* nums, int numsSize) {
    int *count = (int *)malloc(sizeof(int) * 100000);
    memset(count, 0, sizeof(int) * 100000);
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }
    int ans = 0, taken = 0;
    for (int i = 0; i < 100000; i++) {
        if (count[i] >= 2) {
            taken += count[i] - 1;
            ans -= i * (count[i] - 1);
        } else if (taken > 0 && count[i] == 0) {
            taken--;
            ans += i;
        }
    }
    return ans;    
}