/**https://leetcode.com/problems/number-of-squareful-arrays/ */
//An array is squareful if the sum of every pair of adjacent elements is a perfect square.
//Given an integer array nums, return the number of permutations of nums that are squareful.
//Two permutations perm1 and perm2 are different if there is some index i such that perm1[i] != perm2[i].
// 
//Example 1:
//Input: nums = [1,17,8]
//Output: 2
//Explanation: [1,8,17] and [17,8,1] are the valid permutations.
//Example 2:
//Input: nums = [2,2,2]
//Output: 1
// 
//Constraints:
//	1 <= nums.length <= 12
//	0 <= nums[i] <= 109
/**
 * @param {number[]} nums
 * @return {number}
 */
var numSquarefulPerms = function(nums) {
    let n = nums.length;
    let count = 0;
    let visited = new Array(n).fill(false);
    let map = new Map();
    for(let i=0;i<n;i++){
        if(map.has(nums[i])){
            map.set(nums[i],map.get(nums[i])+1);
        }else{
            map.set(nums[i],1);
        }
    }
    let dfs = (i,j) => {
        if(i==n){
            count++;
            return;
        }
        for(let k=0;k<n;k++){
            if(visited[k] || map.get(nums[k])){
                continue;
            }
        }
    }
    return count;
};