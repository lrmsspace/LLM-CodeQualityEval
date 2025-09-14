/**https://leetcode.com/problems/find-unique-binary-string/ */
//Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.
// 
//Example 1:
//Input: nums = ["01","10"]
//Output: "11"
//Explanation: "11" does not appear in nums. "00" would also be correct.
//Example 2:
//Input: nums = ["00","01"]
//Output: "11"
//Explanation: "11" does not appear in nums. "10" would also be correct.
//Example 3:
//Input: nums = ["111","011","001"]
//Output: "101"
//Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 16
//	nums[i].length == n
//	nums[i] is either '0' or '1'.
//	All the strings of nums are unique.
/**
 * @param {string[]} nums
 * @return {string}
 */
var findDifferentBinaryString = function(nums) {
    let n = nums.length;
    let res = '';
    let count = new Array(1 << n).fill(0);
    
    for (let i = 0; i < 1 << n; i++) {
        let binary = i.toString(2).padStart(n, '0');
        let diff = 0;
        for (let j = 0; j < n; j++) {
            if (binary[j] === '1' && nums.includes(binary.slice(0, j) + '0' + binary.slice(j + 1))) {
                diff++;
            }
        }
        if (diff === 0) {
            res = binary;
            break;
        }
    }
    
    return res;
    
};