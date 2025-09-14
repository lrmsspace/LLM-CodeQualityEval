/**https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/ */
//In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
//We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.
//Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.
//If it cannot be done, return -1.
// 
//Example 1:
//Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
//Output: 2
//Explanation: 
//The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
//If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
//Example 2:
//Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
//Output: -1
//Explanation: 
//In this case, it is not possible to rotate the dominoes to make one row of values equal.
// 
//Constraints:
//	2 <= tops.length <= 2 * 104
//	bottoms.length == tops.length
//	1 <= tops[i], bottoms[i] <= 6
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int> count(7, 0);
        for (int i = 0; i < n; ++i) {
            ++count[tops[i]];
            ++count[bottoms[i]];
        }
        int maxCount = 0;
        for (int i = 1; i <= 6; ++i) {
            maxCount = max(maxCount, count[i]);
        }
        if (maxCount < (n + 1) / 2) return -1;
        int res = INT_MAX;
        for (int i = 1; i <= 6; ++i) {
            int top = 0, bottom = 0;
            for (int j = 0; j < n; ++j) {
                if (tops[j] != i) top += 1;
                if (bottoms[j] != i) bottom += 1;
            }
            res = min(res, min(top, bottom));
        }
        return res;
        }
};