/**https://leetcode.com/problems/gcd-sort-of-an-array/ */
//You are given an integer array nums, and you can perform the following operation any number of times on nums:
//	Swap the positions of two elements nums[i] and nums[j] if gcd(nums[i], nums[j]) > 1 where gcd(nums[i], nums[j]) is the greatest common divisor of nums[i] and nums[j].
//Return true if it is possible to sort nums in non-decreasing order using the above swap method, or false otherwise.
// 
//Example 1:
//Input: nums = [7,21,3]
//Output: true
//Explanation: We can sort [7,21,3] by performing the following operations:
//- Swap 7 and 21 because gcd(7,21) = 7. nums = [21,7,3]
//- Swap 21 and 3 because gcd(21,3) = 3. nums = [3,7,21]
//Example 2:
//Input: nums = [5,2,6,2]
//Output: false
//Explanation: It is impossible to sort the array because 5 cannot be swapped with any other element.
//Example 3:
//Input: nums = [10,5,9,3,15]
//Output: true
//We can sort [10,5,9,3,15] by performing the following operations:
//- Swap 10 and 15 because gcd(10,15) = 5. nums = [15,5,9,3,10]
//- Swap 15 and 3 because gcd(15,3) = 3. nums = [3,5,9,15,10]
//- Swap 10 and 15 because gcd(10,15) = 5. nums = [3,5,9,10,15]
// 
//Constraints:
//	1 <= nums.length <= 3 * 104
//	2 <= nums[i] <= 105
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var gcdSort = function(nums) {
function gcd(a, b) {
    if (b === 0) return a;
    return gcd(b, a % b);
}

function find(parent, x) {
    if (parent[x] !== x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

function union(parent, rank, x, y) {
    let rootX = find(parent, x);
    let rootY = find(parent, y);
    if (rootX !== rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

var gcdSort = function(nums) {
    const maxNum = Math.max(...nums);
    const parent = Array.from({ length: maxNum + 1 }, (_, i) => i);
    const rank = Array(maxNum + 1).fill(0);

    for (let num of nums) {
        for (let factor = 2; factor <= Math.sqrt(num); factor++) {
            if (num % factor === 0) {
                union(parent, rank, num, factor);
                union(parent, rank, num, num / factor);
            }
        }
    }

    const sortedNums = [...nums].sort((a, b) => a - b);
    for (let i = 0; i < nums.length; i++) {
        if (find(parent, nums[i]) !== find(parent, sortedNums[i])) {
            return false;
        }
    }
    return true;
};
};