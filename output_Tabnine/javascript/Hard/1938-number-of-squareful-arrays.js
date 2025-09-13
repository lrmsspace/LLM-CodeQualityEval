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
    //Sort the array in ascending order
    nums.sort((a, b) => a - b);
    
    //Create a map to store the count of each number
    let countMap = new Map();
    nums.forEach(num => countMap.set(num, (countMap.get(num) || 0) + 1));
    
    //Create a helper function to check if a number can be added to the current number to form a square
    function isSquare(num) {
        return Math.sqrt(num) % 1 === 0;
    }
    
    //Create a recursive function to find the number of squareful permutations
    function dfs(index, used, path) {
        //If all numbers have been used, return 1
        if (index === nums.length) return 1;
        
        let count = countMap.get(nums[index]) || 0;
        let result = 0;
        
        //For each possible number to add to the current number
        for (let i = 0; i < count; i++) {
            //If the number is already used or the current number is smaller than the next number, skip it
            if (used[index] || (index > 0 && nums[index] === nums[index - 1] &&!used[index - 1])) continue;
            
            //Add the number to the used array and the path
            used[index] = true;
            path.push(nums[index]);
            
            //Recursively find the number of squareful permutations
            result += dfs(index + 1, used, path);
            
            //Remove the number from the used array and the path
            used[index] = false;
            path.pop();
        }
        
        //Update the count of the current number in the map
        countMap.set(nums[index], count - result);
        
        return result;
    }
    
    //Start the recursive function with an empty used array and an empty path
    return dfs(0, Array(nums.length).fill(false), []);
    
};