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
        int[] minutes = new int[timePoints.size()];
        for (int i = 0; i < timePoints.size(); i++) {
            String[] time = timePoints.get(i).split(":");
            minutes[i] = Integer.parseInt(time[0]) * 60 + Integer.parseInt(time[1]);
        }
        Arrays.sort(minutes);
        int minDiff = Integer.MAX_VALUE;
        for (int i = 1; i < minutes.length; i++) {
            minDiff = Math.min(minDiff, minutes[i] - minutes[i - 1]);
        }
        minDiff = Math.min(minDiff, 24 * 60 - (minutes[minutes.length - 1] - minutes[0]));
        return minDiff;       
    }
}