/*
 There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:
 colors[i] == 0 means that tile i is red.
 colors[i] == 1 means that tile i is blue.
 An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).
 Return the number of alternating groups.
 Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.
 Example 1:
 Input: colors = [0,1,0,1,0], k = 3
 Output: 3
 Explanation:
 Alternating groups:
 Example 2:
 Input: colors = [0,1,0,0,1,0,1], k = 6
 Output: 2
 Explanation:
 Alternating groups:
 Example 3:
 Input: colors = [1,1,0,1], k = 4
 Output: 0
 Explanation:
 Constraints:
 3 <= colors.length <= 105
 0 <= colors[i] <= 1
 3 <= k <= colors.length
*/

class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < colors.length; i++) {
            sum += colors[i];
        }
        
        if(sum % 3 != 0) {
            return -1;
        }
        
        int target = sum / 3;
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < colors.length; i++) {
            sum1 += colors[i];
            if(sum1 == target) {
                sum2 = 0;
                for(int j = i + 1; j < colors.length; j++) {
                    sum2 += colors[j];
                    if(sum2 == target) {
                        return i + 1;
                    }
                }
            }
        }
        return -1;
        
    }
}