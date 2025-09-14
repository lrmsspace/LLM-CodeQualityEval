/**https://leetcode.com/problems/best-poker-hand/ */
//You are given an integer array ranks and a character array suits. You have 5 cards where the ith card has a rank of ranks[i] and a suit of suits[i].
//The following are the types of poker hands you can make from best to worst:
//	"Flush": Five cards of the same suit.
//	"Three of a Kind": Three cards of the same rank.
//	"Pair": Two cards of the same rank.
//	"High Card": Any single card.
//Return a string representing the best type of poker hand you can make with the given cards.
//Note that the return values are case-sensitive.
// 
//Example 1:
//Input: ranks = [13,2,3,1,9], suits = ["a","a","a","a","a"]
//Output: "Flush"
//Explanation: The hand with all the cards consists of 5 cards with the same suit, so we have a "Flush".
//Example 2:
//Input: ranks = [4,4,2,4,4], suits = ["d","a","a","b","c"]
//Output: "Three of a Kind"
//Explanation: The hand with the first, second, and fourth card consists of 3 cards with the same rank, so we have a "Three of a Kind".
//Note that we could also make a "Pair" hand but "Three of a Kind" is a better hand.
//Also note that other cards could be used to make the "Three of a Kind" hand.
//Example 3:
//Input: ranks = [10,10,2,12,9], suits = ["a","b","c","a","d"]
//Output: "Pair"
//Explanation: The hand with the first and second card consists of 2 cards with the same rank, so we have a "Pair".
//Note that we cannot make a "Flush" or a "Three of a Kind".
// 
//Constraints:
//	ranks.length == suits.length == 5
//	1 <= ranks[i] <= 13
//	'a' <= suits[i] <= 'd'
//	No two cards have the same rank and suit.
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        sort(ranks.begin(), ranks.end());
        int maxCount = 0;
        int maxRank = -1;
        int flushCount = 0;
        for (int i = 0; i < 4; ++i) {
            if (suits[i] == suits[i + 1]) {
                ++flushCount;
            }
        }
        for (int i = 0; i < 5; ++i) {
            int count = 1;
            for (int j = i + 1; j < 5; ++j) {
                if (ranks[j] == ranks[i]) {
                    ++count;
                }
            }
            if (count > maxCount) {
                maxCount = count;
                maxRank = ranks[i];
            }
        }
        if (flushCount == 4) {
            return "Flush";
        }
        if (maxCount == 3) {
            return "Three of a Kind";
        }
        if (maxCount == 2) {
            return "Pair";
        }
        return "High Card";
        
    }
};