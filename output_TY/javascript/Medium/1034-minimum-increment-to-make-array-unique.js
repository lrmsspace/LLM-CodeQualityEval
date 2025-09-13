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
/**
 * @param {number[]} nums
 * @return {number}
 */
var minIncrementForUnique = function(nums) {
    let count = 0;
    let map = {};
    for(let i=0;i<nums.length;i++){
        if(map[nums[i]]){
            map[nums[i]]++;
        }else{
            map[nums[i]] = 1;
        }
    }
    let keys = Object.keys(map);
    for(let i=0;i<keys.length;i++){
        let key = keys[i];
        if(map[key]>1){
            let diff = map[key]-1;
            count += diff;
            map[key] = 1;
            for(let j=key+1;j<=key+diff;j++){
                if(map[j]){
                    map[j]++;
                }else{
                    map[j] = 1;
                }
            }
        }
    }
    return count;
};