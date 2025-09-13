/**https://leetcode.com/problems/keyboard-row/ */
//Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
//Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.
//In the American keyboard:
//	the first row consists of the characters "qwertyuiop",
//	the second row consists of the characters "asdfghjkl", and
//	the third row consists of the characters "zxcvbnm".
// 
//Example 1:
//Input: words = ["Hello","Alaska","Dad","Peace"]
//Output: ["Alaska","Dad"]
//Explanation:
//Both "a" and "A" are in the 2nd row of the American keyboard due to case insensitivity.
//Example 2:
//Input: words = ["omk"]
//Output: []
//Example 3:
//Input: words = ["adsdf","sfd"]
//Output: ["adsdf","sfd"]
// 
//Constraints:
//	1 <= words.length <= 20
//	1 <= words[i].length <= 100
//	words[i] consists of English letters (both lowercase and uppercase). 
/**
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function(words) {
    let row1 = new Set(['q','w','e','r','t','y','u','i','o','p']);
    let row2 = new Set(['a','s','d','f','g','h','j','k','l']);
    let row3 = new Set(['z','x','c','v','b','n','m']);
    let result = [];
    for(let i = 0; i < words.length; i++){
        let word = words[i].toLowerCase();
        let row = null;
        for(let j = 0; j < word.length; j++){
            if(row1.has(word[j])){
                row = row1;
                break;
            }else if(row2.has(word[j])){
                row = row2;
                break;
            }else if(row3.has(word[j])){
                row = row3;
                break;
            }else{
                row = null;
                break;
            }
        }
        if(row !== null){
            result.push(words[i]);
        }
        for(let j = 0; j < word.length; j++){
            if(!row.has(word[j])){
                result.pop();
            }
        }}
        return result;
};