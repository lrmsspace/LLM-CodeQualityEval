/**https://leetcode.com/problems/find-k-th-smallest-pair-distance/ */
//The distance of a pair of integers a and b is defined as the absolute difference between a and b.
//Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.
// 
//Example 1:
//Input: nums = [1,3,1], k = 1
//Output: 0
//Explanation: Here are all the pairs:
//(1,3) -> 2
//(1,1) -> 0
//(3,1) -> 2
//Then the 1st smallest distance pair is (1,1), and its distance is 0.
//Example 2:
//Input: nums = [1,1,1], k = 2
//Output: 0
//Example 3:
//Input: nums = [1,6,1], k = 3
//Output: 5
// 
//Constraints:
//	n == nums.length
//	2 <= n <= 104
//	0 <= nums[i] <= 106
//	1 <= k <= n * (n - 1) / 2
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var smallestDistancePair = function(nums, k) {
    nums.sort((a,b)=>a-b);
    let left = 0;
    let right = nums[nums.length-1] - nums[0];
    while(left<right){
        let mid = Math.floor((left+right)/2);
        let count = 0;
        let j = 0;
        for(let i=0;i<nums.length;i++){
            while(nums[i]-nums[j]>mid){
                j++;
            }
            count += i-j;
        }
        if(count<k){
            left = mid+1;
        }else{
            right = mid;
        }
    }
    return left;
};