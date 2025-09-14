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
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        backtrack(res, vector<string>(), s, 0);
        return res;
    }
    
    void backtrack(vector<vector<string>>& res, vector<string>& path, string s, int start) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i=start; i<s.size(); i++) {
            string sub = s.substr(start, i-start+1);
            if (isPalindrome(sub)) {
                path.push_back(sub);
                backtrack(res, path, s, i+1);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        while (i<j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
        
};