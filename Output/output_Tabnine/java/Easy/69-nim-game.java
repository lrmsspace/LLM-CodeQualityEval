/**https://leetcode.com/problems/nim-game/ */
//You are playing the following Nim Game with your friend:
//	Initially, there is a heap of stones on the table.
//	You and your friend will alternate taking turns, and you go first.
//	On each turn, the person whose turn it is will remove 1 to 3 stones from the heap.
//	The one who removes the last stone is the winner.
//Given n, the number of stones in the heap, return true if you can win the game assuming both you and your friend play optimally, otherwise return false.
// 
//Example 1:
//Input: n = 4
//Output: false
//Explanation: These are the possible outcomes:
//1. You remove 1 stone. Your friend removes 3 stones, including the last stone. Your friend wins.
//2. You remove 2 stones. Your friend removes 2 stones, including the last stone. Your friend wins.
//3. You remove 3 stones. Your friend removes the last stone. Your friend wins.
//In all outcomes, your friend wins.
//Example 2:
//Input: n = 1
//Output: true
//Example 3:
//Input: n = 2
//Output: true
// 
//Constraints:
//	1 <= n <= 231 - 1
class Solution {
    public boolean canWinNim(int n) {
        return n % 4!= 0; //If n is not divisible by 4, the first player can always win. 4 is the smallest number that can be removed in a turn to guarantee a win. 5, 6, 7, 8, 9, 10,... will always lose. 11, 12, 13, 14, 15,... will always win. 16, 17, 18, 19, 20,... will always lose. 21, 22, 23, 24,... will always win. 25,... will always lose. 26,... will always win. 27,... will always lose. 28,... will always win. 29,... will always lose. 30,... will always win. 31,... will always lose. 32,... will always win
        
    }
}