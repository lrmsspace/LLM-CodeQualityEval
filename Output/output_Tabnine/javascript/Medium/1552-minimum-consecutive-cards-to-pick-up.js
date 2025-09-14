/**https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/ */
//You are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.
//Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. If it is impossible to have matching cards, return -1.
// 
//Example 1:
//Input: cards = [3,4,2,3,4,7]
//Output: 4
//Explanation: We can pick up the cards [3,4,2,3] which contain a matching pair of cards with value 3. Note that picking up the cards [4,2,3,4] is also optimal.
//Example 2:
//Input: cards = [1,0,5,3]
//Output: -1
//Explanation: There is no way to pick up a set of consecutive cards that contain a pair of matching cards.
// 
//Constraints:
//	1 <= cards.length <= 105
//	0 <= cards[i] <= 106
/**
 * @param {number[]} cards
 * @return {number}
 */
var minimumCardPickup = function(cards) {
    let freq = new Map();
    let left = new Map();
    
    for (let i = 0; i < cards.length; i++) {
        let card = cards[i];
        if (freq.has(card)) {
            freq.set(card, freq.get(card) + 1);
        } else {
            freq.set(card, 1);
        }
        
        if (left.has(card - 1)) {
            left.set(card, left.get(card - 1) + freq.get(card));
        } else {
            left.set(card, freq.get(card));
        }
    }
    
    let minCount = Infinity;
    
    for (let card of freq.keys()) {
        if (left.has(card)) {
            minCount = Math.min(minCount, left.get(card));
        }
    }
    
    return minCount === Infinity? -1 : minCount;
    
};