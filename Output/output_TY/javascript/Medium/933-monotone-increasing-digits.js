/**https://leetcode.com/problems/monotone-increasing-digits/ */
//An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.
//Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.
// 
//Example 1:
//Input: n = 10
//Output: 9
//Example 2:
//Input: n = 1234
//Output: 1234
//Example 3:
//Input: n = 332
//Output: 299
// 
//Constraints:
//	0 <= n <= 109
/**
 * @param {number} n
 * @return {number}
 */
var monotoneIncreasingDigits = function(n) {
    let str = n.toString();
    let len = str.length;
    let i = 0;
    let flag = false;
    while(i < len - 1){
        if(str[i] > str[i+1]){
            flag = true;
            str = str.slice(0, i) + (str[i]-1) + '9'.repeat(len - i - 1);
            break;
        }
        i++;
    }
    return flag ? parseInt(str) : n;
};