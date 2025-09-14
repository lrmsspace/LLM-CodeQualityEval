/**https://leetcode.com/problems/letter-tile-possibilities/ */
//You have n  tiles, where each tile has one letter tiles[i] printed on it.
//Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.
// 
//Example 1:
//Input: tiles = "AAB"
//Output: 8
//Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
//Example 2:
//Input: tiles = "AAABBC"
//Output: 188
//Example 3:
//Input: tiles = "V"
//Output: 1
// 
//Constraints:
//	1 <= tiles.length <= 7
//	tiles consists of uppercase English letters.
class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        int ans = 0;
        vector<bool> visited(n, false);
        set<string> s;
        function<void(string)> dfs = [&](string cur) {
            if (cur.size() > 0) {
                s.insert(cur);
            }
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    dfs(cur + tiles[i]);
                    visited[i] = false;
                }
            }
        };
        dfs("");
        return s.size();      
    }
};