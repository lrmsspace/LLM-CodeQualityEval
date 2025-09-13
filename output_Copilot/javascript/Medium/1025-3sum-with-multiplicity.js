/**https://leetcode.com/problems/3sum-with-multiplicity/ */
//Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
//As the answer can be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
//Output: 20
//Explanation: 
//Enumerating by the values (arr[i], arr[j], arr[k]):
//(1, 2, 5) occurs 8 times;
//(1, 3, 4) occurs 8 times;
//(2, 2, 4) occurs 2 times;
//(2, 3, 3) occurs 2 times.
//Example 2:
//Input: arr = [1,1,2,2,2,2], target = 5
//Output: 12
//Explanation: 
//arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
//We choose one 1 from [1,1] in 2 ways,
//and two 2s from [2,2,2,2] in 6 ways.
//Example 3:
//Input: arr = [2,1,3], target = 6
//Output: 1
//Explanation: (1, 2, 3) occured one time in the array so we return 1.
// 
//Constraints:
//	3 <= arr.length <= 3000
//	0 <= arr[i] <= 100
//	0 <= target <= 300
/**
 * @param {number[]} arr
 * @param {number} target
 * @return {number}
 */
var threeSumMulti = function(arr, target) {
    const mod = 1e9 + 7;
    let count = 0;
    const freq = new Array(101).fill(0);
    
    for (const num of arr) {
        freq[num]++;
    }
    
    for (let i = 0; i <= 100; i++) {
        for (let j = i; j <= 100; j++) {
            const k = target - i - j;
            if (k < 0 || k > 100) continue;
            if (i === j && j === k) {
                count += (freq[i] * (freq[i] - 1) * (freq[i] - 2)) / 6;
            } else if (i === j) {
                count += (freq[i] * (freq[i] - 1)) / 2 * freq[k];
            } else if (j === k) {
                count += freq[i] * (freq[j] * (freq[j] - 1)) / 2;
            } else {
                count += freq[i] * freq[j] * freq[k];
            }
        }
    }
    
    return count % mod;    
};