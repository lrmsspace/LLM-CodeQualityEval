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
        unordered_set<string> res;
        vector<int> count(26, 0);
        for (char c : tiles) count[c - 'A']++;
        function<void(int)> dfs = [&](int i) {
            if (i == tiles.size()) {
                string s;
                for (int j = 0; j < 26; ++j) {
                    if (count[j]) s += 'A' + j;
                }
                if (s.size()) res.insert(s);
                return;
            }
            dfs(i + 1);
            if (count[tiles[i] - 'A']) {
                --count[tiles[i] - 'A'];
                dfs(i + 1);
                ++count[tiles[i] - 'A'];
            }
        };
        dfs(0);
        return res.size();
    }
};