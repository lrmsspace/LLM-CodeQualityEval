/**https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/ */
//You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.
//You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.
//Return the maximum sum of values that you can receive by attending events.
// 
//Example 1:
//Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
//Output: 7
//Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
//Example 2:
//Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
//Output: 10
//Explanation: Choose event 2 for a total value of 10.
//Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.
//Example 3:
//Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
//Output: 9
//Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.
// 
//Constraints:
//	1 <= k <= events.length
//	1 <= k * events.length <= 106
//	1 <= startDayi <= endDayi <= 109
//	1 <= valuei <= 106
class Solution {
    public int maxValue(int[][] events, int k) {
        int n = events.length;
        int[] dp = new int[n+1];
        int[][] sorted = new int[n][3];
        for(int i=0;i<n;i++){
            sorted[i][0] = events[i][0];
            sorted[i][1] = events[i][1];
            sorted[i][2] = events[i][2];
        }
        Arrays.sort(sorted, (a,b)->a[0]-b[0]);
        int[][] dp2 = new int[n+1][k+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                dp2[i][j] = dp2[i-1][j];
                int end = sorted[i-1][1];
                int start = sorted[i-1][0];
                int max = sorted[i-1][2];
                int index = binarySearch(sorted, end, start);
                dp2[i][j] = Math.max(dp2[i][j], max+dp2[index][j-1]);
            }
        }  
        return dp2[n][k];
    }
}