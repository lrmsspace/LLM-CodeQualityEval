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
    const count = new Map();
    for (let tile of tiles) {
        count.set(tile, (count.get(tile) || 0) + 1);
    }
    
    let result = 0;
    const dfs = (remain, path) => {
        if (remain.length === 0) {
            result++;
            return;
        }
        
        for (let i = 0; i < remain.length; i++) {
            const tile = remain[i];
            const count = count.get(tile);
            if (count === 1) {
                count.delete(tile);
            } else {
                count.set(tile, count - 1);
            }
            
            dfs(remain.slice(0, i).concat(remain.slice(i + 1)), path + tile);
            
            count.set(tile, count + 1);
        }
    };
    
    dfs(Array.from(count.keys()), '');
    return result;
    
};