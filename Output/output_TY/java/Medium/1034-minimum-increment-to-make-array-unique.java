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
class Solution {
    public int minIncrementForUnique(int[] nums) {
        int[] count = new int[100000];
        for(int num: nums)
            count[num]++;
        int ans = 0;
        for(int i=0;i<100000;i++){
            if(count[i]>1){
                int diff = count[i]-1;
                ans += diff*i;
                count[i] = 1;
            }
        }
        for(int i=1;i<100000;i++){
            if(count[i]>1){
                int diff = count[i]-1;
                ans += diff*(i-1);
                count[i] = 1;
            }
        }
        return ans;
    }
}