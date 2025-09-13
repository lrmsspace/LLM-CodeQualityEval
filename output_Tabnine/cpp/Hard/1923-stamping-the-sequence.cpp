/**https://leetcode.com/problems/stamping-the-sequence/ */
//You are given two strings stamp and target. Initially, there is a string s of length target.length with all s[i] == '?'.
//In one turn, you can place stamp over s and replace every letter in the s with the corresponding letter from stamp.
//	For example, if stamp = "abc" and target = "abcba", then s is "?????" initially. In one turn you can:
//	
//		place stamp at index 0 of s to obtain "abc??",
//		place stamp at index 1 of s to obtain "?abc?", or
//		place stamp at index 2 of s to obtain "??abc".
//	
//	Note that stamp must be fully contained in the boundaries of s in order to stamp (i.e., you cannot place stamp at index 3 of s).
//We want to convert s to target using at most 10 * target.length turns.
//Return an array of the index of the left-most letter being stamped at each turn. If we cannot obtain target from s within 10 * target.length turns, return an empty array.
// 
//Example 1:
//Input: stamp = "abc", target = "ababc"
//Output: [0,2]
//Explanation: Initially s = "?????".
//- Place stamp at index 0 to get "abc??".
//- Place stamp at index 2 to get "ababc".
//[1,0,2] would also be accepted as an answer, as well as some other answers.
//Example 2:
//Input: stamp = "abca", target = "aabcaca"
//Output: [3,0,1]
//Explanation: Initially s = "???????".
//- Place stamp at index 3 to get "???abca".
//- Place stamp at index 0 to get "abcabca".
//- Place stamp at index 1 to get "aabcaca".
// 
//Constraints:
//	1 <= stamp.length <= target.length <= 1000
//	stamp and target consist of lowercase English letters.
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        
        int n = target.size();
        vector<int> dp(n, 0);
        vector<int> res;
        vector<int> visited(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (target[i] == '?') {
                dp[i] = -1;
            } else {
                dp[i] = stamp.find(target[i]);
            }
        }
        
        while (true) {
            int min_index = -1;
            int min_val = INT_MAX;
            
            for (int i = 0; i < n; i++) {
                if (dp[i] == -1 &&!visited[i]) {
                    if (min_val > i) {
                        min_val = i;
                        min_index = i;
                    }
                }
            }
            
            if (min_index == -1) break;
            
            visited[min_index] = true;
            res.push_back(min_index);
            
            for (int i = 0; i < n; i++) {
                if (dp[i]!= -1 && i!= min_index && target[i] == target[min_index]) {
                    dp[i] = (dp[i] + stamp.size() - 1) % stamp.size();
                }
            }
        }
        
        return res;
    }
};