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

double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    double totalArea = 0.0;
    double areaBelow = 0.0;
    int i;

    // Calculate total area of squares
    for (i = 0; i < squaresSize; i++) {
        int x = squares[i][0];
        int y = squares[i][1];
        int l = squares[i][2];
        totalArea += (double)(l * l);
    }

    // Sort squares by their bottom-left y-coordinate
    qsort(squares, squaresSize, sizeof(int*), [](const void* a, const void* b) {
        return (*(int**)a)[1] - (*(int**)b)[1];
    });

    // Find the minimum y-coordinate where areas above and below are equal
    for (i = 0; i < squaresSize; i++) {
        int x = squares[i][0];
        int y = squares[i][1];
        int l = squares[i][2];

        // Calculate area below the current square
        areaBelow += (double)(l * l);

        if (areaBelow >= totalArea / 2) {
            return (double)y + (totalArea / 2 - (areaBelow - (double)(l * l))) / (double)(l);
        }
    }

    return -1.0; // Should not reach here if input is valid    
}