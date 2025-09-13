/**https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/ */
//You are given a string num representing the digits of a very large integer and an integer k. You are allowed to swap any two adjacent digits of the integer at most k times.
//Return the minimum integer you can obtain also as a string.
// 
//Example 1:
//Input: num = "4321", k = 4
//Output: "1342"
//Explanation: The steps to obtain the minimum integer from 4321 with 4 adjacent swaps are shown.
//Example 2:
//Input: num = "100", k = 1
//Output: "010"
//Explanation: It's ok for the output to have leading zeros, but the input is guaranteed not to have any leading zeros.
//Example 3:
//Input: num = "36789", k = 1000
//Output: "36789"
//Explanation: We can keep the number without any swaps.
// 
//Constraints:
//	1 <= num.length <= 3 * 104
//	num consists of only digits and does not contain leading zeros.
//	1 <= k <= 109
/**
 * @param {string} num
 * @param {number} k
 * @return {string}
 */
var minInteger = function(num, k) {
    let arr = num.split('').map(Number);
    let n = arr.length;
    
    // Find the largest index i such that arr[i] < arr[i+1]
    let i = n - 2;
    while (i >= 0 && arr[i] >= arr[i+1]) {
        i--;
    }
    
    // If no such index exists, return the original number
    if (i < 0) return num;
    
    // Find the largest index j such that j > i and arr[j] > arr[i]
    let j = n - 1;
    while (j > i && arr[j] <= arr[i]) {
        j--;
    }
    
    // Swap arr[i] and arr[j]
    [arr[i], arr[j]] = [arr[j], arr[i]];
    
    // Reverse the suffix starting from arr[i+1]
    let left = i + 1;
    let right = n - 1;
    while (left < right) {
        [arr[left], arr[right]] = [arr[right], arr[left]];
        left++;
        right--;
    }
    
    // Construct the minimum integer from the sorted array
    return arr.join('');
    
};