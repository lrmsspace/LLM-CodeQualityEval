/**https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/ */
//You are given an array of strings words. Each element of words consists of two lowercase English letters.
//Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
//Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
//A palindrome is a string that reads the same forward and backward.
// 
//Example 1:
//Input: words = ["lc","cl","gg"]
//Output: 6
//Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
//Note that "clgglc" is another longest palindrome that can be created.
//Example 2:
//Input: words = ["ab","ty","yt","lc","cl","ab"]
//Output: 8
//Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
//Note that "lcyttycl" is another longest palindrome that can be created.
//Example 3:
//Input: words = ["cc","ll","xx"]
//Output: 2
//Explanation: One longest palindrome is "cc", of length 2.
//Note that "ll" is another longest palindrome that can be created, and so is "xx".
// 
//Constraints:
//	1 <= words.length <= 105
//	words[i].length == 2
//	words[i] consists of lowercase English letters.
/**
 * @param {string[]} words
 * @return {number}
 */
var longestPalindrome = function(words) {
    let map = new Map();
    let count = 0;
    let odd = false;
    for(let i = 0; i < words.length; i++){
        let word = words[i];
        if(map.has(word)){
            map.set(word, map.get(word) + 1);
        }else{
            map.set(word, 1);
        }
    }
    for(let [key, value] of map){
        if(key[0] === key[1]){
            if(value % 2 === 0){
                count += value;
            }else{
                count += value - 1;
                odd =true;
            }
        }
    }
    return odd ? count + 1 : count;
};