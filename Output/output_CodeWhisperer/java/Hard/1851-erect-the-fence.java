/**https://leetcode.com/problems/erect-the-fence/ */
//You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.
//Fence the entire garden using the minimum length of rope, as it is expensive. The garden is well-fenced only if all the trees are enclosed.
//Return the coordinates of trees that are exactly located on the fence perimeter. You may return the answer in any order.
// 
//Example 1:
//Input: trees = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
//Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
//Explanation: All the trees will be on the perimeter of the fence except the tree at [2, 2], which will be inside the fence.
//Example 2:
//Input: trees = [[1,2],[2,2],[4,2]]
//Output: [[4,2],[2,2],[1,2]]
//Explanation: The fence forms a line that passes through all the trees.
// 
//Constraints:
//	1 <= trees.length <= 3000
//	trees[i].length == 2
//	0 <= xi, yi <= 100
//	All the given positions are unique.
import java.util.Set;
import java.util.HashSet;
class Solution {
    public int[][] outerTrees(int[][] trees) {
        Set<int[]> result = new HashSet<>();
        if (trees == null || trees.length == 0) {
            return new int[0][0];
        }
        int[] first = trees[0];
        int firstIdx = 0, n = trees.length;
        for (int i = 1; i < n; i++) {
            if (trees[i][0] < first[0]) {
                first = trees[i];
                firstIdx = i;
            }
        }
        int cur = firstIdx, prev = -1;
        do {
            result.add(trees[cur]);
            int next = (cur + 1) % n;
            for (int i = 0; i < n; i++) {
                if (cross(trees[cur], trees[i], trees[next]) < 0) {
                    next = i;
                }
            }
            for (int i = 0; i < n; i++) {
                if (i != cur && i != next && cross(trees[cur], trees[i], trees[next]) == 0) {
                    result.add(trees[i]);
                }
            }
            prev = cur;
            cur = next;
        } while (cur != firstIdx);
        return result.toArray(new int[result.size()][]);     
    }
}