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
        vector<int> count(26, 0);
        for (auto c : tiles) count[c - 'A']++;

        int ans = 0;
        for (int i = 1; i < (1 << n); i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    sum += count[j];
                }
            }
            ans += sum * (sum - 1) / 2;
        }
        return ans;
    }
};