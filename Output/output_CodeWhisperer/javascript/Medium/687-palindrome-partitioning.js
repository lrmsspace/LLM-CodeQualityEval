/**https://leetcode.com/problems/palindrome-partitioning/ */
//Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
// 
//Example 1:
//Input: s = "aab"
//Output: [["a","a","b"],["aa","b"]]
//Example 2:
//Input: s = "a"
//Output: [["a"]]
// 
//Constraints:
//	1 <= s.length <= 16
//	s contains only lowercase English letters.
/**
 * @param {string} s
 * @return {string[][]}
 */
var partition = function(s) {
    let result = [];
    let partition = [];
    function dfs(i){
        if(i >= s.length){
            result.push(partition.slice());
            return;
        }
        for(let j = i; j < s.length; j++){
            if(isPalindrome(s, i, j)){
                partition.push(s.slice(i, j+1));
                dfs(j+1);
                partition.pop();
            }
        }
    }
    function isPalindrome(s, start, end){
        while(start < end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    dfs(0);
    return result; 
};