/**https://leetcode.com/problems/largest-component-size-by-common-factor/ */
//You are given an integer array of unique positive integers nums. Consider the following graph:
//	There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
//	There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
//Return the size of the largest connected component in the graph.
// 
//Example 1:
//Input: nums = [4,6,15,35]
//Output: 4
//Example 2:
//Input: nums = [20,50,9,63]
//Output: 2
//Example 3:
//Input: nums = [2,3,6,7,4,12,21,39]
//Output: 8
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	1 <= nums[i] <= 105
//	All the values of nums are unique.
/**
 * @param {number[]} nums
 * @return {number}
 */
var largestComponentSize = function(nums) {
    let max = Math.max(...nums);
    let parent = new Array(max+1).fill(0).map((x,i)=>i);
    let size = new Array(max+1).fill(1);
    let maxSize = 1;
    
    for(let i=0;i<nums.length;i++){
        for(let j=2;j<=Math.sqrt(nums[i]);j++){
            if(nums[i]%j==0){
                let p1 = find(nums[i]);
                let p2 = find(j);
                let p3 = find(nums[i]/j);
               if(p1!=p2){
                  union(p1,p2);
                  union(p1,p3);
               }
            }
        }
    }
    for(let i=0;i<nums.length;i++){
        maxSize = Math.max(maxSize,size[find(nums[i])]);
    }
    return maxSize;
};