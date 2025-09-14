/**https://leetcode.com/problems/bulb-switcher/ */
//There are n bulbs that are initially off. You first turn on all the bulbs, then you turn off every second bulb.
//On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb.
//Return the number of bulbs that are on after n rounds.
// 
//Example 1:
//Input: n = 3
//Output: 1
//Explanation: At first, the three bulbs are [off, off, off].
//After the first round, the three bulbs are [on, on, on].
//After the second round, the three bulbs are [on, off, on].
//After the third round, the three bulbs are [on, off, off]. 
//So you should return 1 because there is only one bulb is on.
//Example 2:
//Input: n = 0
//Output: 0
//Example 3:
//Input: n = 1
//Output: 1
// 
//Constraints:
//	0 <= n <= 109
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n); //O(sqrt(n)) solution based on the problem statement.
        //For each bulb, it will be toggled once by the bulb number that is a perfect square.
        //So, we count the number of perfect squares from 1 to n.
        //The number of perfect squares less than or equal to n is floor(sqrt(n)).
        //Thus, the number of bulbs that are on after n rounds is floor(sqrt(n)).
        
    }
};