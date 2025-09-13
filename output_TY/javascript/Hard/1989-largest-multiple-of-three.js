/**https://leetcode.com/problems/largest-multiple-of-three/ */
//Given an array of digits digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order. If there is no answer return an empty string.
//Since the answer may not fit in an integer data type, return the answer as a string. Note that the returning answer must not contain unnecessary leading zeros.
// 
//Example 1:
//Input: digits = [8,1,9]
//Output: "981"
//Example 2:
//Input: digits = [8,6,7,1,0]
//Output: "8760"
//Example 3:
//Input: digits = [1]
//Output: ""
// 
//Constraints:
//	1 <= digits.length <= 104
//	0 <= digits[i] <= 9
/**
 * @param {number[]} digits
 * @return {string}
 */
var largestMultipleOfThree = function(digits) {
    let sum = 0;
    let map = new Map();
    for(let i = 0; i < digits.length; i++){
        sum += digits[i];
        map.set(digits[i], (map.get(digits[i]) || 0) + 1);
    }
    let target = sum % 3;
    let result = "";
    if(target === 0){
        for(let i = 9; i >= 0; i--){
            if(map.has(i)){
                for(let j = 0; j < map.get(i); j++){
                    result += i;
                }
            }
        }
    }
    else{
        for(let i = 9; i >= 0; i--){
            if(map.has(i) && (i % 3) === target){
                for(let j = 0; j < map.get(i); j++){
                    result += i;
                }
            }
        }
    }
    return result;
};