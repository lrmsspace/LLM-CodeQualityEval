/*
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
 You are given a 2D integer array intervals, where intervals[i] = [li, ri, weighti]. Interval i starts at position li and ends at ri, and has a weight of weighti. You can choose up to 4 non-overlapping intervals. The score of the chosen intervals is defined as the total sum of their weights.
 Return the lexicographically smallest array of at most 4 indices from intervals with maximum score, representing your choice of non-overlapping intervals.
 Two intervals are said to be non-overlapping if they do not share any points. In particular, intervals sharing a left or right boundary are considered overlapping.
 Example 1:
 Input: intervals = [[1,3,2],[4,5,2],[1,5,5],[6,9,3],[6,7,1],[8,9,1]]
 Output: [2,3]
 Explanation:
 You can choose the intervals with indices 2, and 3 with respective weights of 5, and 3.
 Example 2:
 Input: intervals = [[5,8,1],[6,7,7],[4,7,3],[9,10,6],[7,8,2],[11,14,3],[3,5,5]]
 Output: [1,3,5,6]
 Explanation:
 You can choose the intervals with indices 1, 3, 5, and 6 with respective weights of 7, 6, 3, and 5.
 Constraints:
 1 <= intevals.length <= 5 * 104
 intervals[i].length == 3
 intervals[i] = [li, ri, weighti]
 1 <= li <= ri <= 109
 1 <= weighti <= 109
*/

class Solution {
    public int[] maximumWeight(List<List<Integer>> intervals) {
        int n = intervals.size();
        int[][] arr = new int[n][3];
        for (int i = 0; i < n; i++) {
            arr[i][0] = intervals.get(i).get(0);
            arr[i][1] = intervals.get(i).get(1);
            arr[i][2] = intervals.get(i).get(2);
        }
        Arrays.sort(arr, (a, b) -> a[1] - b[1]);
        int[] dp = new int[n];
        int[] prev = new int[n];
        for (int i = 0; i < n; i++) {
            dp[i] = arr[i][2];
            prev[i] = -1;
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j][1] < arr[i][0]) {
                    if (dp[j] + arr[i][2] > dp[i]) {
                        dp[i] = dp[j] + arr[i][2];
                        prev[i] = j;
                    }
                }
            }
        }
        int max = 0;
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] > max) {
                max = dp[i];
                index = i;
            }
        }
        List<Integer> res = new ArrayList<>();
        while (index != -1) {
            res.add(index);
            index = prev[index];
        }
        Collections.sort(res);
        int[] result = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            result[i] = res.get(i) + 1;
        }
        return result;
            
    }
}