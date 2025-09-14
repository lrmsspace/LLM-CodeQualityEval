/**https://leetcode.com/problems/largest-palindromic-number/ */
//You are given a string num consisting of digits only.
//Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. It should not contain leading zeroes.
//Notes:
//	You do not need to use all the digits of num, but you must use at least one digit.
//	The digits can be reordered.
// 
//Example 1:
//Input: num = "444947137"
//Output: "7449447"
//Explanation: 
//Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
//It can be shown that "7449447" is the largest palindromic integer that can be formed.
//Example 2:
//Input: num = "00009"
//Output: "9"
//Explanation: 
//It can be shown that "9" is the largest palindromic integer that can be formed.
//Note that the integer returned should not contain leading zeroes.
// 
//Constraints:
//	1 <= num.length <= 105
//	num consists of digits.
/**
 * @param {string} num
 * @return {string}
 */
var largestPalindromic = function(num) {
    let map = new Map();
    for(let i=0;i<num.length;i++){
        if(map.has(num[i])){
            map.set(num[i],map.get(num[i])+1);
        }else{
            map.set(num[i],1);
        }
    }
    let max = 0;
    let maxChar = "";
    for(let [key,value] of map){
        if(value>max){
            max = value;
            maxChar = key;
        }
    }
    let palindrome = "";
    for(let i=0;i<max;i++){
        palindrome+=maxChar;
    }
    return palindrome;
};