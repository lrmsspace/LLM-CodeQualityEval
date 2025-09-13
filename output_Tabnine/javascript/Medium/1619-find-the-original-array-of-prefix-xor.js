/**https://leetcode.com/problems/find-the-original-array-of-prefix-xor/ */
//You are given an integer array pref of size n. Find and return the array arr of size n that satisfies:
//	pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i].
//Note that ^ denotes the bitwise-xor operation.
//It can be proven that the answer is unique.
// 
//Example 1:
//Input: pref = [5,2,0,3,1]
//Output: [5,7,2,3,2]
//Explanation: From the array [5,7,2,3,2] we have the following:
//- pref[0] = 5.
//- pref[1] = 5 ^ 7 = 2.
//- pref[2] = 5 ^ 7 ^ 2 = 0.
//- pref[3] = 5 ^ 7 ^ 2 ^ 3 = 3.
//- pref[4] = 5 ^ 7 ^ 2 ^ 3 ^ 2 = 1.
//Example 2:
//Input: pref = [13]
//Output: [13]
//Explanation: We have pref[0] = arr[0] = 13.
// 
//Constraints:
//	1 <= pref.length <= 105
//	0 <= pref[i] <= 106
/**
 * @param {number[]} pref
 * @return {number[]}
 */
var findArray = function(pref) {
    let n = pref.length;
    let arr = Array(n).fill(0);
    
    arr[n - 1] = pref[n - 1];
    for (let i = n - 2; i >= 0; i--) {
        arr[i] = pref[i] ^ arr[i + 1];
    }
    
    return arr;
    
};