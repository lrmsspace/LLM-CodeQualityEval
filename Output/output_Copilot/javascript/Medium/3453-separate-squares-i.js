/*
 You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.
 Find the minimum y-coordinate value of a horizontal line such that the total area of the squares above the line equals the total area of the squares below the line.
 Answers within 10-5 of the actual answer will be accepted.
 Note: Squares may overlap. Overlapping areas should be counted multiple times.
 Example 1:
 Input: squares = [[0,0,1],[2,2,1]]
 Output: 1.00000
 Explanation:
 Any horizontal line between y = 1 and y = 2 will have 1 square unit above it and 1 square unit below it. The lowest option is 1.
 Example 2:
 Input: squares = [[0,0,2],[1,1,1]]
 Output: 1.16667
 Explanation:
 The areas are:
 Below the line: 7/6 * 2 (Red) + 1/6 (Blue) = 15/6 = 2.5.
 Above the line: 5/6 * 2 (Red) + 5/6 (Blue) = 15/6 = 2.5.
 Since the areas above and below the line are equal, the output is 7/6 = 1.16667.
 Constraints:
 1 <= squares.length <= 5 * 104
 squares[i] = [xi, yi, li]
 squares[i].length == 3
 0 <= xi, yi <= 109
 1 <= li <= 109
 The total area of all the squares will not exceed 1012.
*/

/**
 * @param {number[][]} squares
 * @return {number}
 */
var separateSquares = function(squares) {
    const n = squares.length;
    let totalArea = 0;
    const events = [];

    // Collect all events for the sweep line algorithm
    for (let i = 0; i < n; i++) {
        const [x, y, l] = squares[i];
        totalArea += l * l;
        events.push([x, y, y + l, 1]); // Start of square
        events.push([x + l, y, y + l, -1]); // End of square
    }

    // Sort events by x-coordinate, then by type (start before end)
    events.sort((a, b) => a[0] - b[0] || a[3] - b[3]);

    let currentArea = 0;
    let lastX = -1;
    let activeIntervals = [];

    // Function to calculate the area covered by active intervals
    const calculateActiveArea = () => {
        if (activeIntervals.length === 0) return 0;
        activeIntervals.sort((a, b) => a[0] - b[0]);
        let area = 0;
        let currentStart = activeIntervals[0][0];
        let currentEnd = activeIntervals[0][1];

        for (let i = 1; i < activeIntervals.length; i++) {
            const [start, end] = activeIntervals[i];
            if (start > currentEnd) {
                area += currentEnd - currentStart;
                currentStart = start;
                currentEnd = end;
            } else {
                currentEnd = Math.max(currentEnd, end);
            }
        }
        area += currentEnd - currentStart; // Add last segment
        return area;
    };

    // Sweep line algorithm to find the horizontal line
    for (const [x, yStart, yEnd, type] of events) {
        if (lastX !== -1 && x !== lastX) {
            const width = x - lastX;
            const height = calculateActiveArea();
            currentArea += width * height;

            if (currentArea * 2 === totalArea) {
                return (yStart + yEnd) / 2; // Return the mid-point of the last processed interval
            }
        }

        if (type === 1) {
            activeIntervals.push([yStart, yEnd]);
        } else {
            activeIntervals = activeIntervals.filter(interval => !(interval[0] === yStart && interval[1] === yEnd));
        }
        lastX = x;
    }
    // If we reach here, it means we didn't find a perfect split
    return -1; // This should not happen given the problem constraints
        
};