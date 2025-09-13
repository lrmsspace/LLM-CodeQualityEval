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
/**
 * @param {string} tiles
 * @return {number}
 */
var numTilePossibilities = function(tiles) {
    let count = 0;
    let set = new Set();
    const backtrack = (path) => {
        if (path.length > 0) {
            set.add(path);
        }
        for (let i = 0; i < tiles.length; i++) {
            backtrack(path + tiles[i]);
            backtrack(path + tiles[i] + tiles.slice(0, i) + tiles.slice(i + 1));
        }
    }
    backtrack("");
    return set.size;
};