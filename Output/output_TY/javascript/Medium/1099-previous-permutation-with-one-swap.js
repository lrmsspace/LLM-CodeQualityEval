/**https://leetcode.com/problems/previous-permutation-with-one-swap/ */
//Given an array of positive integers arr (not necessarily distinct), return the lexicographically largest permutation that is smaller than arr, that can be made with exactly one swap. If it cannot be done, then return the same array.
//Note that a swap exchanges the positions of two numbers arr[i] and arr[j]
// 
//Example 1:
//Input: arr = [3,2,1]
//Output: [3,1,2]
//Explanation: Swapping 2 and 1.
//Example 2:
//Input: arr = [1,1,5]
//Output: [1,1,5]
//Explanation: This is already the smallest permutation.
//Example 3:
//Input: arr = [1,9,4,6,7]
//Output: [1,7,4,6,9]
//Explanation: Swapping 9 and 7.
// 
//Constraints:
//	1 <= arr.length <= 104
//	1 <= arr[i] <= 104
/**
 * @param {number[]} arr
 * @return {number[]}
 */
var prevPermOpt1 = function(arr) {
    let n = arr.length;
    for(let i = n - 2; i >= 0; i--){
        let j = n - 1;
        while(j > i && arr[j] >= arr[i]) j--;
        if(j > i){
            let temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            return arr;
        }
    }
    return arr;
};