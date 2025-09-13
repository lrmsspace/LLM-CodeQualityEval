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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maximumWeight(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize) {
    *returnSize = 0;
    int* ret = (int*)malloc(sizeof(int) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        int* interval = intervals[i];
        int li = interval[0];
        int ri = interval[1];
        int weight = interval[2];
        int j = i - 1;
        while (j >= 0) {
            int* prev = intervals[j];
            int prev_li = prev[0];
            int prev_ri = prev[1];
            int prev_weight = prev[2];
            if (prev_ri < li) {
                break;
            }
            if (prev_li <= li && ri <= prev_ri) {
                weight = max(weight, prev_weight);
                break;
            }
        }
    }
    return weight;
    
}