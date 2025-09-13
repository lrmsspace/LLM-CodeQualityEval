/**https://leetcode.com/problems/maximum-building-height/ */
//You want to build n new buildings in a city. The new buildings will be built in a line and are labeled from 1 to n.
//However, there are city restrictions on the heights of the new buildings:
//	The height of each building must be a non-negative integer.
//	The height of the first building must be 0.
//	The height difference between any two adjacent buildings cannot exceed 1.
//Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array restrictions where restrictions[i] = [idi, maxHeighti] indicates that building idi must have a height less than or equal to maxHeighti.
//It is guaranteed that each building will appear at most once in restrictions, and building 1 will not be in restrictions.
//Return the maximum possible height of the tallest building.
// 
//Example 1:
//Input: n = 5, restrictions = [[2,1],[4,1]]
//Output: 2
//Explanation: The green area in the image indicates the maximum allowed height for each building.
//We can build the buildings with heights [0,1,2,1,2], and the tallest building has a height of 2.
//Example 2:
//Input: n = 6, restrictions = []
//Output: 5
//Explanation: The green area in the image indicates the maximum allowed height for each building.
//We can build the buildings with heights [0,1,2,3,4,5], and the tallest building has a height of 5.
//Example 3:
//Input: n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
//Output: 5
//Explanation: The green area in the image indicates the maximum allowed height for each building.
//We can build the buildings with heights [0,1,2,3,3,4,4,5,4,3], and the tallest building has a height of 5.
// 
//Constraints:
//	2 <= n <= 109
//	0 <= restrictions.length <= min(n - 1, 105)
//	2 <= idi <= n
//	idi is unique.
//	0 <= maxHeighti <= 109
class Solution {
    public int maxBuilding(int n, int[][] restrictions) {
           if (n == 1) return 0; // If there's only one building, its height is 0.
    
            // Add the first building (height 0) and the last building (height n - 1) to the restrictions.
            restrictions = Arrays.copyOf(restrictions, restrictions.length + 2);
            restrictions[restrictions.length - 2] = new int[]{1, 0};
            restrictions[restrictions.length - 1] = new int[]{n, n - 1};
    
            // Sort the restrictions based on the building index.
            Arrays.sort(restrictions, Comparator.comparingInt(a -> a[0]));
    
            int maxHeight = 0;
            for (int i = 1; i < restrictions.length; i++) {
                int leftBuilding = restrictions[i - 1][0];
                int leftHeight = restrictions[i - 1][1];
                int rightBuilding = restrictions[i][0];
                int rightHeight = restrictions[i][1];
    
                // Calculate the maximum height between the two buildings.
                maxHeight = Math.max(maxHeight, (leftHeight + rightHeight + rightBuilding - leftBuilding) / 2);
    
                // Calculate the maximum height at the right building position.
                rightHeight = Math.min(rightHeight, maxHeight + rightBuilding - leftBuilding);
                restrictions[i][1] = rightHeight;
            }
    
            return maxHeight;     
    }
}