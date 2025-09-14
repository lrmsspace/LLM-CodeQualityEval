/**https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/ */
//A string s is called good if there are no two different characters in s that have the same frequency.
//Given a string s, return the minimum number of characters you need to delete to make s good.
//The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.
// 
//Example 1:
//Input: s = "aab"
//Output: 0
//Explanation: s is already good.
//Example 2:
//Input: s = "aaabbbcc"
//Output: 2
//Explanation: You can delete two 'b's resulting in the good string "aaabcc".
//Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".
//Example 3:
//Input: s = "ceabaacb"
//Output: 2
//Explanation: You can delete both 'c's resulting in the good string "eabaab".
//Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).
// 
//Constraints:
//	1 <= s.length <= 105
//	s contains only lowercase English letters.
/**
 * @param {string} s
 * @return {number}
 */
var minDeletions = function(s) {
    let map = new Map();
    let count = 0;
    for(let i = 0; i < s.length; i++){
        if(map.has(s[i])){
            map.set(s[i], map.get(s[i]) + 1);
        }else{
            map.set(s[i], 1);
        }
    }
    let arr = [];
    for(let [key, value] of map){
        arr.push(value);
    }
    arr.sort((a, b) => b - a);
    for(let i = 0; i < arr.length; i++){
        if(arr[i] === arr[i + 1]){
            let j = i + 1;
            while(arr[j] === arr[i]){
                arr[j]--;
                count++;
            }
        }
    }
    return count;
};