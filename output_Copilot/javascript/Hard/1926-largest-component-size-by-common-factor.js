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
    const maxNum = Math.max(...nums);
    const parent = Array.from({ length: maxNum + 1 }, (_, i) => i);
    const size = Array.from({ length: maxNum + 1 }, () => 1);

    function find(x) {
        if (parent[x] !== x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    function union(x, y) {
        const rootX = find(x);
        const rootY = find(y);
        if (rootX !== rootY) {
            if (size[rootX] < size[rootY]) {
                [rootX, rootY] = [rootY, rootX];
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }

    for (const num of nums) {
        for (let j = 2; j * j <= num; j++) {
            if (num % j === 0) {
                union(num, j);
                union(num, num / j);
            }
        }
    }

    const componentSize = new Map();
    let maxSize = 0;

    for (const num of nums) {
        const root = find(num);
        componentSize.set(root, (componentSize.get(root) || 0) + 1);
        maxSize = Math.max(maxSize, componentSize.get(root));
    }

    return maxSize;    
};