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
    let path = [];
    let n = s.length;
    
    function backtrack(start){
        if(start >= n){
            result.push(path.slice());
            return;
        }
        
        for(let i = start; i < n; i++){
            if(isPalindrome(s, start, i)){
                path.push(s.slice(start, i+1));
                backtrack(i+1);
                path.pop();
            }
        }
    }
    
    backtrack(0);
    return result;

};