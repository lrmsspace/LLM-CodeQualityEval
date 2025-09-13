/**https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/ */
//A string is considered beautiful if it satisfies the following conditions:
//	Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at least once in it.
//	The letters must be sorted in alphabetical order (i.e. all 'a's before 'e's, all 'e's before 'i's, etc.).
//For example, strings "aeiou" and "aaaaaaeiiiioou" are considered beautiful, but "uaeio", "aeoiu", and "aaaeeeooo" are not beautiful.
//Given a string word consisting of English vowels, return the length of the longest beautiful substring of word. If no such substring exists, return 0.
//A substring is a contiguous sequence of characters in a string.
// 
//Example 1:
//Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
//Output: 13
//Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.
//Example 2:
//Input: word = "aeeeiiiioooauuuaeiou"
//Output: 5
//Explanation: The longest beautiful substring in word is "aeiou" of length 5.
//Example 3:
//Input: word = "a"
//Output: 0
//Explanation: There is no beautiful substring, so return 0.
// 
//Constraints:
//	1 <= word.length <= 5 * 105
//	word consists of characters 'a', 'e', 'i', 'o', and 'u'.
/**
 * @param {string} word
 * @return {number}
 */
var longestBeautifulSubstring = function(word) {
    let vowels = ['a', 'e', 'i', 'o', 'u']
    let vowelCount = 0
    let longest = 0
    let start = 0
    for(let i = 0; i < word.length; i++){
        if(vowels.indexOf(word[i]) === vowelCount){
            vowelCount++
            if(vowelCount === 5){
                longest = Math.max(longest, i - start + 1)
            }
        }else if(vowels.indexOf(word[i]) > vowelCount){
            vowelCount = 0
            start = i
        }
    }
    return longest
};