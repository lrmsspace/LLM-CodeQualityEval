/**https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/ */
//You are given an integer num. You will apply the following steps exactly two times:
//	Pick a digit x (0 <= x <= 9).
//	Pick another digit y (0 <= y <= 9). The digit y can be equal to x.
//	Replace all the occurrences of x in the decimal representation of num by y.
//	The new integer cannot have any leading zeros, also the new integer cannot be 0.
//Let a and b be the results of applying the operations to num the first and second times, respectively.
//Return the max difference between a and b.
// 
//Example 1:
//Input: num = 555
//Output: 888
//Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
//The second time pick x = 5 and y = 1 and store the new integer in b.
//We have now a = 999 and b = 111 and max difference = 888
//Example 2:
//Input: num = 9
//Output: 8
//Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
//The second time pick x = 9 and y = 1 and store the new integer in b.
//We have now a = 9 and b = 1 and max difference = 8
// 
//Constraints:
//	1 <= num <= 108
/**
 * @param {number} num
 * @return {number}
 */
var maxDiff = function(num) {
    let a = num.toString().split('');
    let b = num.toString().split('');
    let i = 0;
    while (i < a.length) {
        if (a[i] !== '9') {
            let temp = a[i];
            for (let j = 0; j < a.length; j++) {
                if (a[j] === temp) {
                    a[j] = '9';
                }
            }
            break;
        }
        i++;
    }
    let x = 0;
    if (b[0] !== '1') {
        x = b[0];
        for (let j = 0; j < b.length; j++) {
            if (b[j] === x) {
                if (j === 0) {
                    b[j] = '1';
                } else {
                    b[j] = '0';
                }
            }
        }
    } else {
        x = b[1];
        for (let j = 0; j < b.length; j++) {
            if (b[j] === x) {
                b[j] = '0';
            }
        }
    }
    return parseInt(a.join('')) - parseInt(b.join(''));
};