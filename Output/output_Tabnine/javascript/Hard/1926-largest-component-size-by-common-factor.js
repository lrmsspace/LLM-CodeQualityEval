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
    const n = nums.length;
    const parent = Array.from({ length: n }, (_, i) => i);
    const rank = Array.from({ length: n }, () => 1);
    
    function find(x) {
        if (parent[x]!== x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    function union(x, y) {
        const px = find(x);
        const py = find(y);
        if (px!== py) {
            if (rank[px] < rank[py]) {
                [parent[px], parent[py]] = [py, px];
            } else if (rank[px] > rank[py]) {
                [parent[px], parent[py]] = [px, py];
            } else {
                parent[py] = px;
                rank[px]++;
            }
        }
    }
    
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            if (nums[i] % nums[j] === 0 || nums[j] % nums[i] === 0) {
                union(i, j);
            }
        }
    }
    
    const size = Array.from({ length: n }, () => 0);
    for (let i = 0; i < n; i++) {
        size[find(i)]++;
    }
    
    return Math.max(...size);
    
};