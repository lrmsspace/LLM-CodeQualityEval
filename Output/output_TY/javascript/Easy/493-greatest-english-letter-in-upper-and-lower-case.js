/**https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/ */
//Given a string of English letters s, return the greatest English letter which occurs as both a lowercase and uppercase letter in s. The returned letter should be in uppercase. If no such letter exists, return an empty string.
//An English letter b is greater than another letter a if b appears after a in the English alphabet.
// 
//Example 1:
//Input: s = "lEeTcOdE"
//Output: "E"
//Explanation:
//The letter 'E' is the only letter to appear in both lower and upper case.
//Example 2:
//Input: s = "arRAzFif"
//Output: "R"
//Explanation:
//The letter 'R' is the greatest letter to appear in both lower and upper case.
//Note that 'A' and 'F' also appear in both lower and upper case, but 'R' is greater than 'F' or 'A'.
//Example 3:
//Input: s = "AbCdEfGhIjK"
//Output: ""
//Explanation:
//There is no letter that appears in both lower and upper case.
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of lowercase and uppercase English letters.
/**
 * @param {string} s
 * @return {string}
 */
var greatestLetter = function(s) {
    let arr = s.split("");
    let arr2 = [];
    let arr3 = [];
    for(let i = 0; i < arr.length; i++){
        if(arr[i] === arr[i].toUpperCase()){
            arr2.push(arr[i]);
        }
        if(arr[i] === arr[i].toLowerCase()){
            arr3.push(arr[i]);
        }
    }
    let arr4 = [];
    for(let i = 0; i < arr2.length; i++){
        for(let j = 0; j < arr3.length; j++){
            if(arr2[i] === arr3[j]){
                arr4.push(arr2[i]);
            }
        }
    }
    let arr5 = [];
    for(let i = 0; i < arr4.length; i++){
        if(arr4[i] !== arr4[i].toLowerCase()){
            arr5.push(arr4[i]);
        }
    }
    let arr6 = arr5.sort();
    if(arr6.length === 0){
        return "";
    }else{
        return arr6[arr6.length - 1];
    }
    return arr6;
};