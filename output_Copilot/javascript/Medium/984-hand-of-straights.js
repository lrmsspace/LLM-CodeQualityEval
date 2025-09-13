/**https://leetcode.com/problems/hand-of-straights/ */
//Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
//Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.
// 
//Example 1:
//Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
//Output: true
//Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
//Example 2:
//Input: hand = [1,2,3,4,5], groupSize = 4
//Output: false
//Explanation: Alice's hand can not be rearranged into groups of 4.
// 
//Constraints:
//	1 <= hand.length <= 104
//	0 <= hand[i] <= 109
//	1 <= groupSize <= hand.length
// 
//Note: This question is the same as 1296: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
/**
 * @param {number[]} hand
 * @param {number} groupSize
 * @return {boolean}
 */
var isNStraightHand = function(hand, groupSize) {
    if (hand.length % groupSize !== 0) return false; // check if the length of hand is divisible by groupSize
    const count = {}; // create a count object to store the frequency of each card
    for (let card of hand) {
        count[card] = (count[card] || 0) + 1; // increment the frequency of each card
    }
    const keys = Object.keys(count).sort((a, b) => a - b); // sort the keys of the count object
    for (let i = 0; i < keys.length; i++) {
        let card = keys[i]; // get the current card
        if (count[card] > 0) { // check if the current card has a frequency greater than 0
            for (let j = 0; j < groupSize; j++) { // loop through the groupSize
                if (!count[card + j]) return false; // check if the next card exists in the count object
                count[card + j] -= count[card]; // decrement the frequency of the next card by the frequency of the current card
            }
        }
    }
    return true; // return true if all cards can be rearranged into groups of groupSize    
};