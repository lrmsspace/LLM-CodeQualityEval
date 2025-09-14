/**https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/ */
//You are given an integer array deck where deck[i] represents the number written on the ith card.
//Partition the cards into one or more groups such that:
//	Each group has exactly x cards where x > 1, and
//	All the cards in one group have the same integer written on them.
//Return true if such partition is possible, or false otherwise.
// 
//Example 1:
//Input: deck = [1,2,3,4,4,3,2,1]
//Output: true
//Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
//Example 2:
//Input: deck = [1,1,1,2,2,2,3,3]
//Output: false
//Explanation: No possible partition.
// 
//Constraints:
//	1 <= deck.length <= 104
//	0 <= deck[i] < 104
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function(deck) {
    if (deck.length < 2) return false;
    
    const count = {};
    for (const card of deck) {
        count[card] = (count[card] || 0) + 1;
    }
    
    const gcd = (a, b) => b === 0 ? a : gcd(b, a % b);
    
    const counts = Object.values(count);
    let g = counts[0];
    for (const c of counts) {
        g = gcd(g, c);
    }
    
    return g > 1;

};