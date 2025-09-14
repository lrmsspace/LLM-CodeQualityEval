/**https://leetcode.com/problems/shortest-completing-word/ */
//Given a string licensePlate and an array of strings words, find the shortest completing word in words.
//A completing word is a word that contains all the letters in licensePlate. Ignore numbers and spaces in licensePlate, and treat letters as case insensitive. If a letter appears more than once in licensePlate, then it must appear in the word the same number of times or more.
//For example, if licensePlate = "aBc 12c", then it contains letters 'a', 'b' (ignoring case), and 'c' twice. Possible completing words are "abccdef", "caaacab", and "cbca".
//Return the shortest completing word in words. It is guaranteed an answer exists. If there are multiple shortest completing words, return the first one that occurs in words.
// 
//Example 1:
//Input: licensePlate = "1s3 PSt", words = ["step","steps","stripe","stepple"]
//Output: "steps"
//Explanation: licensePlate contains letters 's', 'p', 's' (ignoring case), and 't'.
//"step" contains 't' and 'p', but only contains 1 's'.
//"steps" contains 't', 'p', and both 's' characters.
//"stripe" is missing an 's'.
//"stepple" is missing an 's'.
//Since "steps" is the only word containing all the letters, that is the answer.
//Example 2:
//Input: licensePlate = "1s3 456", words = ["looks","pest","stew","show"]
//Output: "pest"
//Explanation: licensePlate only contains the letter 's'. All the words contain 's', but among these "pest", "stew", and "show" are shortest. The answer is "pest" because it is the word that appears earliest of the 3.
// 
//Constraints:
//	1 <= licensePlate.length <= 7
//	licensePlate contains digits, letters (uppercase or lowercase), or space ' '.
//	1 <= words.length <= 1000
//	1 <= words[i].length <= 15
//	words[i] consists of lower case English letters.
/**
 * @param {string} licensePlate
 * @param {string[]} words
 * @return {string}
 */
var shortestCompletingWord = function(licensePlate, words) {
    let licensePlateMap = new Map();
    for(let i = 0; i < licensePlate.length; i++){
        let char = licensePlate[i];
        if(char.toLowerCase() >= 'a' && char.toLowerCase() <= 'z'){
            if(licensePlateMap.has(char.toLowerCase())){
                licensePlateMap.set(char.toLowerCase(), licensePlateMap.get(char.toLowerCase()) + 1);
            }else{
                licensePlateMap.set(char.toLowerCase(), 1);
            }
        }
    }
    let minLength = Number.MAX_SAFE_INTEGER;
    for(let i = 0; i < words.length; i++){
        let word = words[i];
        let wordMap = new Map();
        for(let j = 0; j < word.length; j++){
            let char = word[j];
            if(char.toLowerCase() >= 'a' && char.toLowerCase() <= 'z'){
                if(wordMap.has(char.toLowerCase())){
                    wordMap.set(char.toLowerCase(), wordMap.get(char.toLowerCase()) + 1);
                }else{
                    wordMap.set(char.toLowerCase(), 1);
                }
            }
       }
    }
    for(let i = 0; i < words.length; i++){
        let word = words[i];
        let wordMap2 = new Map();
        for(let j = 0; j < word.length; j++){
            let char = word[j];
            if(char.toLowerCase() >= 'a' && char.toLowerCase() <= 'z'){
                if(wordMap2.has(char.toLowerCase())){
                    wordMap2.set(char.toLowerCase(), wordMap2.get(char.toLowerCase()) + 1);
                }else{
                    wordMap2.set(char.toLowerCase(), 1);
                }
            }
        }
    }
    for(let [key, value] of wordMap2){
        if(wordMap1.has(key)){
            if(wordMap1.get(key) < value){
                return "";
            }
        }else{
            return "";
        }
    }
    return word;

};