/*
 You are given an array maximumHeight, where maximumHeight[i] denotes the maximum height the ith tower can be assigned.
 Your task is to assign a height to each tower so that:
 The height of the ith tower is a positive integer and does not exceed maximumHeight[i].
 No two towers have the same height.
 Return the maximum possible total sum of the tower heights. If it's not possible to assign heights, return -1.
 Example 1:
 Input: maximumHeight = [2,3,4,3]
 Output: 10
 Explanation:
 We can assign heights in the following way: [1, 2, 4, 3].
 Example 2:
 Input: maximumHeight = [15,10]
 Output: 25
 Explanation:
 We can assign heights in the following way: [15, 10].
 Example 3:
 Input: maximumHeight = [2,2,1]
 Output: -1
 Explanation:
 It's impossible to assign positive heights to each index so that no two towers have the same height.
 Constraints:
 1 <= maximumHeight.length <= 105
 1 <= maximumHeight[i] <= 109
*/

class Solution {
    public long maximumTotalSum(int[] maximumHeight) {
        // Sort the maximumHeight array in descending order
        Arrays.sort(maximumHeight);
        
        // Initialize the total sum and the count of towers with heights
        long totalSum = 0;
        int count = 0;
        
        // Iterate through the maximumHeight array in descending order
        for (int height : maximumHeight) {
            // Check if it's possible to assign a height to the current tower
            if (count < height) {
                // Assign the height to the current tower
                totalSum += count;
                count++;
            }
        }
        
        // If it's not possible to assign heights, return -1
        if (count < maximumHeight.length) {
            return -1;
        }
        
        // Return the maximum possible total sum of the tower heights
        return totalSum;    
        
    }
}