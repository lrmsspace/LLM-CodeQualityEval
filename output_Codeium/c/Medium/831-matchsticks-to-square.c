/**https://leetcode.com/problems/matchsticks-to-square/ */
//You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
//Return true if you can make this square and false otherwise.
// 
//Example 1:
//Input: matchsticks = [1,1,2,2,2]
//Output: true
//Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
//Example 2:
//Input: matchsticks = [3,3,3,3,4]
//Output: false
//Explanation: You cannot find a way to form a square with all the matchsticks.
// 
//Constraints:
//	1 <= matchsticks.length <= 15
//	1 <= matchsticks[i] <= 108

bool search(int start, int* matchsticks, int matchsticksSize) {
        if (start == matchsticksSize) {
            return sides[0] == side && sides[1] == side && sides[2] == side && sides[3] == side;
        }
        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[start] <= side) {
                sides[i] += matchsticks[start];
                if (search(start + 1, matchsticks, matchsticksSize)) {
                    return true;
                }
                sides[i] -= matchsticks[start];
            }
        }
        return false;
    }   
bool makesquare(int* matchsticks, int matchsticksSize) {
    int total = 0;
    for (int i = 0; i < matchsticksSize; i++) {
        total += matchsticks[i];
    }
    if (total % 4 != 0) {
        return false;
    }
    int side = total / 4;
    int sides[4] = {0};
    
    sort(matchsticks, matchsticks + matchsticksSize, greater<int>());
    return search(0, matchsticks, matchsticksSize);
    
}