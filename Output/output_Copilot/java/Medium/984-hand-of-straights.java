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
class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if (hand.length % groupSize != 0) return false; // Check if the total number of cards is divisible by groupSize

        Map<Integer, Integer> countMap = new HashMap<>(); // Map to store the frequency of each card value
        for (int card : hand) {
            countMap.put(card, countMap.getOrDefault(card, 0) + 1); // Increment the count for each card value
        }

        Arrays.sort(hand); // Sort the hand array to process cards in ascending order

        for (int i = 0; i < hand.length; i++) {
            int card = hand[i];
            if (countMap.get(card) == 0) continue; // If this card has already been used, skip it

            for (int j = 0; j < groupSize; j++) { // Try to form a group of size groupSize
                int nextCard = card + j;
                if (countMap.getOrDefault(nextCard, 0) == 0) return false; // If the next card is not available, return false
                countMap.put(nextCard, countMap.get(nextCard) - 1); // Decrease the count of the next card
            }
        }
        return true; // All groups were successfully formed        
    }
}