/**https://leetcode.com/problems/find-the-shortest-superstring/ */
//Given an array of strings words, return the smallest string that contains each string in words as a substring. If there are multiple valid strings of the smallest length, return any of them.
//You may assume that no string in words is a substring of another string in words.
// 
//Example 1:
//Input: words = ["alex","loves","leetcode"]
//Output: "alexlovesleetcode"
//Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
//Example 2:
//Input: words = ["catg","ctaagt","gcta","ttca","atgcatc"]
//Output: "gctaagttcatgcatc"
// 
//Constraints:
//	1 <= words.length <= 12
//	1 <= words[i].length <= 20
//	words[i] consists of lowercase English letters.
//	All the strings of words are unique.    
class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        
        // Calculate the overlap between each pair of strings
        vector<vector<int>> overlap(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    // Calculate the maximum overlap of suffix of words[i] with prefix of words[j]
                    overlap[i][j] = calculateOverlap(words[i], words[j]);
                }
            }
        }
        
        // dp[mask][last] = minimum length of superstring covering strings represented by mask,
        // with words[last] being the last string
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
        
        // parent[mask][last] = the previous string in the optimal path
        vector<vector<int>> parent(1 << n, vector<int>(n, -1));
        
        // Base case: single strings
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = words[i].length();
        }
        
        // Fill dp table
        for (int mask = 1; mask < (1 << n); mask++) {
            for (int j = 0; j < n; j++) {
                if (!(mask & (1 << j))) continue; // Skip if j is not in the mask
                
                int prevMask = mask ^ (1 << j); // Remove j from the mask
                if (prevMask == 0) continue; // Skip if j is the only bit set
                
                for (int i = 0; i < n; i++) {
                    if (!(prevMask & (1 << i))) continue; // Skip if i is not in prevMask
                    
                    int newLength = dp[prevMask][i] + words[j].length() - overlap[i][j];
                    if (newLength < dp[mask][j]) {
                        dp[mask][j] = newLength;
                        parent[mask][j] = i;
                    }
                }
            }
        }
        
        // Find the ending string that gives the shortest superstring
        int mask = (1 << n) - 1; // All strings
        int last = 0;
        for (int i = 1; i < n; i++) {
            if (dp[mask][i] < dp[mask][last]) {
                last = i;
            }
        }
        
        // Reconstruct the path
        vector<int> path;
        while (last != -1) {
            path.push_back(last);
            int temp = mask;
            mask ^= (1 << last); // Remove last from mask
            last = parent[temp][last];
        }
        reverse(path.begin(), path.end());
        
        // Build the shortest superstring
        string result = words[path[0]];
        for (int i = 1; i < path.size(); i++) {
            int overlapLength = overlap[path[i-1]][path[i]];
            result += words[path[i]].substr(overlapLength);
        }
        
        return result;
    }
    
private:
    // Calculate the maximum overlap of suffix of s1 with prefix of s2
    int calculateOverlap(const string& s1, const string& s2) {
        int maxOverlap = 0;
        int len1 = s1.length();
        int len2 = s2.length();
        
        // Try all possible overlaps
        for (int i = 1; i <= min(len1, len2); i++) {
            if (s1.substr(len1 - i) == s2.substr(0, i)) {
                maxOverlap = i;
            }
        }
        
        return maxOverlap;
    }
};
