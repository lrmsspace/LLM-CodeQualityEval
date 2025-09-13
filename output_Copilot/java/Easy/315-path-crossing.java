/**https://leetcode.com/problems/path-crossing/ */
//Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.
//Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.
// 
//Example 1:
//Input: path = "NES"
//Output: false 
//Explanation: Notice that the path doesn't cross any point more than once.
//Example 2:
//Input: path = "NESWW"
//Output: true
//Explanation: Notice that the path visits the origin twice.
// 
//Constraints:
//	1 <= path.length <= 104
//	path[i] is either 'N', 'S', 'E', or 'W'.
class Solution {
    public boolean isPathCrossing(String path) {
        // HashSet to store visited coordinates
        Set<String> visited = new HashSet<>();
        // Starting point (0, 0)
        int x = 0, y = 0;
        // Mark the starting point as visited
        visited.add(x + "," + y);

        // Iterate through each character in the path
        for (char direction : path.toCharArray()) {
            // Move in the corresponding direction
            switch (direction) {
                case 'N': y++; break; // Move North
                case 'S': y--; break; // Move South
                case 'E': x++; break; // Move East
                case 'W': x--; break; // Move West
            }
            // Check if the new position has been visited before
            if (!visited.add(x + "," + y)) {
                return true; // Path crosses itself
            }
        }
        return false; // No crossing found        
    }
}