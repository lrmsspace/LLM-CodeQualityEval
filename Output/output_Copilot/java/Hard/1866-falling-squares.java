/**https://leetcode.com/problems/falling-squares/ */
//There are several squares being dropped onto the X-axis of a 2D plane.
//You are given a 2D integer array positions where positions[i] = [lefti, sideLengthi] represents the ith square with a side length of sideLengthi that is dropped with its left edge aligned with X-coordinate lefti.
//Each square is dropped one at a time from a height above any landed squares. It then falls downward (negative Y direction) until it either lands on the top side of another square or on the X-axis. A square brushing the left/right side of another square does not count as landing on it. Once it lands, it freezes in place and cannot be moved.
//After each square is dropped, you must record the height of the current tallest stack of squares.
//Return an integer array ans where ans[i] represents the height described above after dropping the ith square.
// 
//Example 1:
//Input: positions = [[1,2],[2,3],[6,1]]
//Output: [2,5,5]
//Explanation:
//After the first drop, the tallest stack is square 1 with a height of 2.
//After the second drop, the tallest stack is squares 1 and 2 with a height of 5.
//After the third drop, the tallest stack is still squares 1 and 2 with a height of 5.
//Thus, we return an answer of [2, 5, 5].
//Example 2:
//Input: positions = [[100,100],[200,100]]
//Output: [100,100]
//Explanation:
//After the first drop, the tallest stack is square 1 with a height of 100.
//After the second drop, the tallest stack is either square 1 or square 2, both with heights of 100.
//Thus, we return an answer of [100, 100].
//Note that square 2 only brushes the right side of square 1, which does not count as landing on it.
// 
//Constraints:
//	1 <= positions.length <= 1000
//	1 <= lefti <= 108
//	1 <= sideLengthi <= 106
class Solution {
    public List<Integer> fallingSquares(int[][] positions) {
        List<Integer> ans = new ArrayList<>();
        TreeMap<Integer, Integer> map = new TreeMap<>();
        int maxHeight = 0;
        for (int[] pos : positions) {
            int left = pos[0], right = pos[0] + pos[1];
            int height = 0;
            // Find the maximum height of the squares that are overlapping with the current square
            for (int h : map.subMap(left, right).values()) {
                height = Math.max(height, h);
            }
            height += pos[1];
            maxHeight = Math.max(maxHeight, height);
            ans.add(maxHeight);
            // Update the heights of the squares in the map
            map.put(left, height);
            map.put(right, 0); // Mark the end of the square
        }
        return ans;        
    }
}