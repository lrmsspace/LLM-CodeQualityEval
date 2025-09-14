/**https://leetcode.com/problems/minimum-time-difference/ */
//Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
// 
//Example 1:
//Input: timePoints = ["23:59","00:00"]
//Output: 1
//Example 2:
//Input: timePoints = ["00:00","23:59","00:00"]
//Output: 0
// 
//Constraints:
//	2 <= timePoints.length <= 2 * 104
//	timePoints[i] is in the format "HH:MM".
class Solution {
    public int findMinDifference(List<String> timePoints) {
        int n = timePoints.size();
        int[] minutes = new int[n];
        for (int i = 0; i < n; i++) {
            String[] parts = timePoints.get(i).split(":");
            minutes[i] = Integer.parseInt(parts[0]) * 60 + Integer.parseInt(parts[1]);
        }
        Arrays.sort(minutes);
        int minDiff = Integer.MAX_VALUE;
        for (int i = 1; i < n; i++) {
            minDiff = Math.min(minDiff, minutes[i] - minutes[i - 1]);
        }
        minDiff = Math.min(minDiff, 1440 - (minutes[n - 1] - minutes[0]));
        return minDiff;        
    }
}