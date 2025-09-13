/**https://leetcode.com/problems/k-similar-strings/ */
//Strings s1 and s2 are k-similar (for some non-negative integer k) if we can swap the positions of two letters in s1 exactly k times so that the resulting string equals s2.
//Given two anagrams s1 and s2, return the smallest k for which s1 and s2 are k-similar.
// 
//Example 1:
//Input: s1 = "ab", s2 = "ba"
//Output: 1
//Explanation: The two string are 1-similar because we can use one swap to change s1 to s2: "ab" --> "ba".
//Example 2:
//Input: s1 = "abc", s2 = "bca"
//Output: 2
//Explanation: The two strings are 2-similar because we can use two swaps to change s1 to s2: "abc" --> "bac" --> "bca".
// 
//Constraints:
//	1 <= s1.length <= 20
//	s2.length == s1.length
//	s1 and s2 contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}.
//	s2 is an anagram of s1.
class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int n = s1.length();
        vector<int> next(n);
        vector<int> dist(1 << n, n);
        queue<int> q;
        
        for (int i = 0; i < n; ++i) {
            if (s1[i]!= s2[i]) {
                next[i] = i;
                dist[1 << i] = i;
                q.push(1 << i);
            }
        }
        
        while (!q.empty()) {
            int state = q.front();
            q.pop();
            
            if (dist[state] < dist[s2[state]]) {
                continue;
            }
            
            for (int i = 0; i < n; ++i) {
                if (!(state & (1 << i))) {
                    int j = next[i];
                    int newState = state | (1 << i);
                    int newDist = dist[state] + (s1[i]!= s2[j]? 1 : 0);
                    
                    if (newDist < dist[newState]) {
                        dist[newState] = newDist;
                        next[j] = i;
                        q.push(newState);
                    }
                }
            }
        }
        
        return dist[~0u]; // ~0u represents the maximum unsigned integer
        
    }
};