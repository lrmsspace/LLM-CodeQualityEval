/**https://leetcode.com/problems/odd-string-difference/ */
//You are given an array of equal-length strings words. Assume that the length of each string is n.
//Each string words[i] can be converted into a difference integer array difference[i] of length n - 1 where difference[i][j] = words[i][j+1] - words[i][j] where 0 <= j <= n - 2. Note that the difference between two letters is the difference between their positions in the alphabet i.e. the position of 'a' is 0, 'b' is 1, and 'z' is 25.
//	For example, for the string "acb", the difference integer array is [2 - 0, 1 - 2] = [2, -1].
//All the strings in words have the same difference integer array, except one. You should find that string.
//Return the string in words that has different difference integer array.
// 
//Example 1:
//Input: words = ["adc","wzy","abc"]
//Output: "abc"
//Explanation: 
//- The difference integer array of "adc" is [3 - 0, 2 - 3] = [3, -1].
//- The difference integer array of "wzy" is [25 - 22, 24 - 25]= [3, -1].
//- The difference integer array of "abc" is [1 - 0, 2 - 1] = [1, 1]. 
//The odd array out is [1, 1], so we return the corresponding string, "abc".
//Example 2:
//Input: words = ["aaa","bob","ccc","ddd"]
//Output: "bob"
//Explanation: All the integer arrays are [0, 0] except for "bob", which corresponds to [13, -13].
// 
//Constraints:
//	3 <= words.length <= 100
//	n == words[i].length
//	2 <= n <= 20
//	words[i] consists of lowercase English letters.
/**
 * @param {string[]} words
 * @return {string}
 */
var oddString = function(words) {
    let diffArr = new Array(words.length).fill(null).map(() => new Array(words[0].length - 1).fill(null));
    
    for(let i = 0; i < words.length; i++) {
        for(let j = 0; j < words[i].length - 1; j++) {
            diffArr[i][j] = words[i].charCodeAt(j + 1) - words[i].charCodeAt(j);
        }
    }
    
    for(let i = 0; i < words.length; i++) {
        let isOdd = true;
        for(let j = 0; j < diffArr[i].length; j++) {
            if(diffArr[i][j] % 2 === 0) {
                isOdd = false;
                break;
            }
        }
        
        if(isOdd) {
            return words[i];
        }
    }
    
    return ""; // If no odd array is found, return an empty string
    
};