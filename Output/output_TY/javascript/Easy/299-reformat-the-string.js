/**https://leetcode.com/problems/reformat-the-string/ */
//You are given an alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).
//You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.
//Return the reformatted string or return an empty string if it is impossible to reformat the string.
// 
//Example 1:
//Input: s = "a0b1c2"
//Output: "0a1b2c"
//Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
//Example 2:
//Input: s = "leetcode"
//Output: ""
//Explanation: "leetcode" has only characters so we cannot separate them by digits.
//Example 3:
//Input: s = "1229857369"
//Output: ""
//Explanation: "1229857369" has only digits so we cannot separate them by characters.
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of only lowercase English letters and/or digits.
/**
 * @param {string} s
 * @return {string}
 */
var reformat = function(s) {
    let arr = s.split('');
    let arr1 = [];
    let arr2 = [];
    for(let i = 0; i < arr.length; i++){
        if(arr[i] >= '0' && arr[i] <= '9'){
            arr1.push(arr[i]);
        }else{
            arr2.push(arr[i]);
        }
    }
    if(Math.abs(arr1.length - arr2.length) > 1){
        return '';
    }
    let ans = [];
    let i = 0;
    let j = 0;
    while(i < arr1.length && j < arr2.length){
        ans.push(arr1[i]);
        ans.push(arr2[j]);
        i++;
        j++;
    }
    if(arr1.length > arr2.length){
        ans.push(arr1[i]);
    }else if(arr2.length > arr1.length){
        ans.push(arr2[j]);
    }
    return ans.join('');
};