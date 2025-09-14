/**https://leetcode.com/problems/orderly-queue/ */
//You are given a string s and an integer k. You can choose one of the first k letters of s and append it at the end of the string.
//Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.
// 
//Example 1:
//Input: s = "cba", k = 1
//Output: "acb"
//Explanation: 
//In the first move, we move the 1st character 'c' to the end, obtaining the string "bac".
//In the second move, we move the 1st character 'b' to the end, obtaining the final result "acb".
//Example 2:
//Input: s = "baaca", k = 3
//Output: "aaabc"
//Explanation: 
//In the first move, we move the 1st character 'b' to the end, obtaining the string "aacab".
//In the second move, we move the 3rd character 'c' to the end, obtaining the final result "aaabc".
// 
//Constraints:
//	1 <= k <= s.length <= 1000
//	s consist of lowercase English letters.
/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var orderlyQueue = function(s, k) {
    //if k is larger than the length of the string, rotate the string once
    if (k > s.length) {
        return s.slice(1) + s[0];
    }
    
    //sort the string by frequency of characters and then lexicographically
    let sortedS = [...s].sort((a, b) => {
        let countA = s.split(a).length - 1;
        let countB = s.split(b).length - 1;
        return countA - countB || a.localeCompare(b);
    }).join('');
    
    //if the sorted string is different from the original string, rotate it by k steps
    if (sortedS!== s) {
        return sortedS.slice(k) + sortedS.slice(0, k);
    }
    
    return sortedS;
    
};