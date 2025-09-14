/*
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
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<int> dp(n, 0), prev(n, -1);
        dp[0] = intervals[0][2];
        for (int i = 1; i < n; ++i) {
            dp[i] = intervals[i][2];
            for (int j = i - 1; j >= 0; --j) {
                if (intervals[j][1] < intervals[i][0]) {
                    if (dp[i] < dp[j] + intervals[i][2]) {
                        dp[i] = dp[j] + intervals[i][2];
                        prev[i] = j;
                    }
                }
            }
        }

        int maxScore = 0, idx = -1;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > maxScore) {
                maxScore = dp[i];
                idx = i;
            }
        }

        vector<int> result;
        int count = 0;
        while (idx != -1 && count < 4) {
            result.push_back(idx);
            idx = prev[idx];
            ++count;
        }
        sort(result.begin(), result.end());
        return result;

    }
};