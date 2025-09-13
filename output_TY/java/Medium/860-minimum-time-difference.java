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
        int[] time = new int[timePoints.size()];
        for(int i=0; i<timePoints.size(); i++){
            time[i] = Integer.parseInt(timePoints.get(i).substring(0,2))*60 + Integer.parseInt(timePoints.get(i).substring(3,5));
        }
        Arrays.sort(time);
        int min = Integer.MAX_VALUE;
        for(int i=0; i<time.length-1; i++){
            min = Math.min(min, time[i+1]-time[i]);
        }
        return Math.min(min, time[0]+1440-time[time.length-1]);
    }
}