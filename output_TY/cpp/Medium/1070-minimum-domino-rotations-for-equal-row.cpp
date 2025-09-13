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
        int top_1 = 0, top_2 = 0, top_3 = 0, top_4 = 0, top_5 = 0, top_6 = 0;
        int bottom_1 = 0, bottom_2 = 0, bottom_3 = 0, bottom_4 = 0, bottom_5 = 0, bottom_6 = 0;
        for(int i = 0; i < n; i++){
            if(tops[i] == 1){
                top_1++;
            }
            else if(tops[i] == 2){
                top_2++;
            }
            elseif(tops[i] == 3){
                top_3++;
            }
        }
        for(int i = 0; i < n; i++){
            if(bottoms[i] == 1){
                bottom_1++;
            }
            else if(bottoms[i] == 2){
                bottom_2++;
            }
            elseif(bottoms[i] == 3){
                bottom_3++;
            }
        }
        int min_rotations = min(min(top_1, bottom_1), min(top_2, bottom_2));
        min_rotations = min(min(min_rotations, min(top_3, bottom_3)), min(top_4, bottom_4));
        min_rotations = min(min(min_rotations, min(top_5, bottom_5)), min(top_6, bottom_6));
        return min_rotations;

    }
};