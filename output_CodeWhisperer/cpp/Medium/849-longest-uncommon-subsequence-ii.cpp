/**https://leetcode.com/problems/longest-uncommon-subsequence-ii/ */
//Given an array of strings strs, return the length of the longest uncommon subsequence between them. If the longest uncommon subsequence does not exist, return -1.
//An uncommon subsequence between an array of strings is a string that is a subsequence of one string but not the others.
//A subsequence of a string s is a string that can be obtained after deleting any number of characters from s.
//	For example, "abc" is a subsequence of "aebdc" because you can delete the underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc" include "aebdc", "aeb", and "" (empty string).
// 
//Example 1:
//Input: strs = ["aba","cdc","eae"]
//Output: 3
//Example 2:
//Input: strs = ["aaa","aaa","aa"]
//Output: -1
// 
//Constraints:
//	2 <= strs.length <= 50
//	1 <= strs[i].length <= 10
//	strs[i] consists of lowercase English letters.  
class Solution {
    public:
        int findLUSlength(vector<string>& strs) {
            int n = strs.size();
            
            // Sort strings by length in descending order
            sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
                return a.length() > b.length();
            });
            
            for (int i = 0; i < n; i++) {
                bool isUncommon = true;
                
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    
                    // If strs[j] is shorter than strs[i], it can't contain strs[i] as a subsequence
                    if (strs[j].length() < strs[i].length()) continue;
                    
                    if (isSubsequence(strs[i], strs[j])) {
                        isUncommon = false;
                        break;
                    }
                }
                
                if (isUncommon) {
                    return strs[i].length();
                }
            }
            
            return -1;
        }
        
    private:
        bool isSubsequence(const string& a, const string& b) {
            int i = 0, j = 0;
            
            while (i < a.length() && j < b.length()) {
                if (a[i] == b[j]) {
                    i++;
                }
                j++;
            }
            
            return i == a.length();
        }
    };
    