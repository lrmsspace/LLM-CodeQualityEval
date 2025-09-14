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
class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        List<String> path = new ArrayList<>();
        backtrack(s, 0, path, res);
        return res;
    }
    public void backtrack(String s, int start, List<String> path, List<List<String>> res){
        if(start == s.length()){
            res.add(new ArrayList<>(path));
            return;
        }
        for(int i = start; i < s.length(); i++){
            if(isPalindrome(s, start, i)){
                path.add(s.substring(start, i + 1));
                backtrack(s,i + 1, path, res);
            }
        }
        path.remove(path.size() - 1);
        return;
    }
}