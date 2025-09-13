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
        int[] times = new int[timePoints.size()];
        int minDiff = Integer.MAX_VALUE;
        
        for (int i = 0; i < timePoints.size(); i++) {
            String[] split = timePoints.get(i).split(":");
            times[i] = Integer.parseInt(split[0]) * 60 + Integer.parseInt(split[1]);
        }
        
        Arrays.sort(times);
        
        for (int i = 1; i < times.length; i++) {
            minDiff = Math.min(minDiff, times[i] - times[i - 1]);
        }
        
        minDiff = Math.min(minDiff, times[0] + 24 * 60 - times[times.length - 1]);
        
        return minDiff;
        
    }
}