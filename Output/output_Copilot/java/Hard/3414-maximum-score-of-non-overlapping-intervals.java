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
    public int[] maximumWeight(List<List<Integer>> intervals) {
        int n = intervals.size();
        int[] indices = new int[n];
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        
        // Sort intervals by their end time, then by start time, then by weight
        Collections.sort(indices, (a, b) -> {
            List<Integer> intervalA = intervals.get(a);
            List<Integer> intervalB = intervals.get(b);
            if (!intervalA.get(1).equals(intervalB.get(1))) {
                return intervalA.get(1) - intervalB.get(1);
            } else if (!intervalA.get(0).equals(intervalB.get(0))) {
                return intervalA.get(0) - intervalB.get(0);
            } else {
                return intervalB.get(2) - intervalA.get(2); // Sort by weight descending
            }
        });
        
        int[] dp = new int[4];
        int[] prevIndex = new int[4];
        Arrays.fill(prevIndex, -1);
        
        for (int idx : indices) {
            List<Integer> interval = intervals.get(idx);
            int l = interval.get(0), r = interval.get(1), weight = interval.get(2);
            
            for (int j = 3; j >= 0; j--) {
                if (dp[j] + weight > dp[j + 1]) {
                    dp[j + 1] = dp[j] + weight;
                    prevIndex[j + 1] = idx;
                }
            }
        }
        
        List<Integer> resultIndices = new ArrayList<>();
        for (int i = 3; i >= 0 && prevIndex[i] != -1; i--) {
            resultIndices.add(prevIndex[i]);
        }
        
        Collections.sort(resultIndices);
        
        return resultIndices.stream().mapToInt(i -> i).toArray();        
    }
}