/**https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/ */
//You are given an array of strings words and a string chars.
//A string is good if it can be formed by characters from chars (each character can only be used once).
//Return the sum of lengths of all good strings in words.
// 
//Example 1:
//Input: words = ["cat","bt","hat","tree"], chars = "atach"
//Output: 6
//Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
//Example 2:
//Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
//Output: 10
//Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
// 
//Constraints:
//	1 <= words.length <= 1000
//	1 <= words[i].length, chars.length <= 100
//	words[i] and chars consist of lowercase English letters.
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    let charMap = new Map();
    for(let i=0;i<chars.length;i++){
        if(charMap.has(chars[i])){
            charMap.set(chars[i],charMap.get(chars[i])+1);
        }else{
            charMap.set(chars[i],1);
        }
    }
    let result = 0;
    for(let i=0;i<words.length;i++){
        let tempMap = new Map(charMap);
        let flag = true;
        for(let j=0;j<words[i].length;j++){
            if(tempMap.has(words[i][j])){
                tempMap.set(words[i][j],tempMap.get(words[i][j])-1);
            }else{
                flag = false;
                break;
            }
        }
    }
    return result;
};