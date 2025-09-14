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
        int res = 0;
        Set<String> set = new HashSet<>();
        backtracking(tiles.toCharArray(), 0, "", set);
        return set.size();
        
    }
    
    private void backtracking(char[] tiles, int index, String curr, Set<String> set) {
        if (index == tiles.length || curr.length() > 0) {
            set.add(curr);
        }
        boolean[] visited = new boolean[26];
        for (int i = index; i < tiles.length; i++) {
            if (visited[tiles[i] - 'A']) continue;
            visited[tiles[i] - 'A'] = true;
            backtracking(tiles, i + 1, curr + tiles[i], set);
        }
    }
}