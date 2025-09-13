/*
 You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.
 Find the minimum y-coordinate value of a horizontal line such that the total area covered by squares above the line equals the total area covered by squares below the line.
 Answers within 10-5 of the actual answer will be accepted.
 Note: Squares may overlap. Overlapping areas should be counted only once in this version.
 Example 1:
 Input: squares = [[0,0,1],[2,2,1]]
 Output: 1.00000
 Explanation:
 Any horizontal line between y = 1 and y = 2 results in an equal split, with 1 square unit above and 1 square unit below. The minimum y-value is 1.
 Example 2:
 Input: squares = [[0,0,2],[1,1,1]]
 Output: 1.00000
 Explanation:
 Since the blue square overlaps with the red square, it will not be counted again. Thus, the line y = 1 splits the squares into two equal parts.
 Constraints:
 1 <= squares.length <= 5 * 104
 squares[i] = [xi, yi, li]
 squares[i].length == 3
 0 <= xi, yi <= 109
 1 <= li <= 109
 The total area of all the squares will not exceed 1015.
*/

class Solution {
    public double separateSquares(int[][] squares) {
        double totalArea = 0;
        List<int[]> events = new ArrayList<>();

        // Collect events for the start and end of each square
        for (int[] square : squares) {
            int x = square[0], y = square[1], l = square[2];
            totalArea += l * l;
            events.add(new int[] { y, x, x + l, 1 });
            events.add(new int[] { y + l, x, x + l, -1 });
        }

        // Sort events by y-coordinate, then by type (end before start)
        events.sort((a, b) -> a[0] != b[0] ? Integer.compare(a[0], b[0]) : Integer.compare(a[3], b[3]));

        TreeMap<Integer, Integer> xCount = new TreeMap<>();
        double currentY = 0, currentArea = 0, halfArea = totalArea / 2.0;

        // Sweep line algorithm to find the minimum y-coordinate
        for (int[] event : events) {
            double nextY = event[0];

            if (currentArea == halfArea) {
                return currentY;
            }

            // Calculate area between currentY and nextY
            if (nextY != currentY && currentArea < halfArea) {
                double deltaY = nextY - currentY;
                currentArea += deltaY * xCount.keySet().stream().mapToDouble(x -> xCount.get(x)).sum();
                currentY = nextY;
            }

            // Update the x-intervals count
            for (int x = event[1]; x < event[2]; x++) {
                xCount.put(x, xCount.getOrDefault(x, 0) + event[3]);
                if (xCount.get(x) == 0) xCount.remove(x);
            }
        }

        return currentY;

    }
}