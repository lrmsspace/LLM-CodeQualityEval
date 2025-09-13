/**https://leetcode.com/problems/maximum-xor-with-an-element-from-array/ */
//You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].
//The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.
//Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.
// 
//Example 1:
//Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
//Output: [3,3,7]
//Explanation:
//1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
//2) 1 XOR 2 = 3.
//3) 5 XOR 2 = 7.
//Example 2:
//Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
//Output: [15,-1,5]
// 
//Constraints:
//	1 <= nums.length, queries.length <= 105
//	queries[i].length == 2
//	0 <= nums[j], xi, mi <= 109
/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {number[]}
 */
var maximizeXor = function(nums, queries) {
    const root = {};
    for (const num of nums) {
        let node = root;
        for (let i = 31; i >= 0; i--) {
            const bit = (num >> i) & 1;
            if (!node[bit]) {
                node[bit] = {};
            }
            node = node[bit];
        }
    }
    const result = [];
    for (const query of queries) {
        let node = root;
        let xor = 0;
        for (let i = 31; i >= 0; i--) {
            const bit = (query[0] >> i) & 1;
            if (node[1 - bit] && node[1 - bit][query[1] >> i] & 1) {
                xor |= 1 << i;
                node = node[1 - bit];
            } else {
                node = node[bit];
            }
        }
        result.push(xor);
    }
    return result;
};