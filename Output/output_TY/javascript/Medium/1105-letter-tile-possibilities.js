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
    let map = new Map();
    for(let i = 0; i < tiles.length; i++){
        if(map.has(tiles[i])){
            map.set(tiles[i], map.get(tiles[i]) + 1);
        }else{
            map.set(tiles[i], 1);
        }
    }
    let count = 0;
    let total = 0;
    let visited = new Set();
    let arr = [];
    for(let [key, value] of map){
        arr.push(key);
    }
    let dfs = (index, count) => {
        if(index === arr.length){
            total += count;
            return;
        }
    }
    for(let i = 0; i < arr.length; i++){
        if(visited.has(i)){
            continue;
        }
        visited.add(i);
        dfs(i + 1, count + map.get(arr[i]));
        visited.delete(i);
    }
    return total;

};