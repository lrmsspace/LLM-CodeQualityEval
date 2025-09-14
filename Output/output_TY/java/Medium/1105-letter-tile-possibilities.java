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
    public int numTilePossibilities(String tiles) {
        int[] freq = new int[26];
        for (char c : tiles.toCharArray()) freq[c - 'A']++;
        return backtrack(freq);
    }

    private int backtrack(int[] freq) {
        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            freq[i]--;
            res += 1 + backtrack(freq);
            freq[i]++;
        }
        return res;
    }
}