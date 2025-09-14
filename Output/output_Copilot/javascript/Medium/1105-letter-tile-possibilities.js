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
    let res = new Set(); // Use a set to avoid duplicates
    let arr = tiles.split('');
    let n = arr.length;
    
    function backtrack(path) {
        if (path.length > 0) {
            res.add(path.join('')); // Add the current path to the set
        }
        for (let i = 0; i < n; i++) {
            if (arr[i] === '') continue; // Skip used tiles
            let temp = arr[i];
            arr[i] = ''; // Mark as used
            path.push(temp);
            backtrack(path); // Recur with the current tile included
            path.pop(); // Backtrack
            arr[i] = temp; // Restore the tile
        }
    }
    
    backtrack([]);
    return res.size; // Return the size of the set as the result    
};