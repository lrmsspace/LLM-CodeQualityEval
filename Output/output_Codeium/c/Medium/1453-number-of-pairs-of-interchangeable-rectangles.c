/**https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/ */
//You are given n rectangles represented by a 0-indexed 2D integer array rectangles, where rectangles[i] = [widthi, heighti] denotes the width and height of the ith rectangle.
//Two rectangles i and j (i < j) are considered interchangeable if they have the same width-to-height ratio. More formally, two rectangles are interchangeable if widthi/heighti == widthj/heightj (using decimal division, not integer division).
//Return the number of pairs of interchangeable rectangles in rectangles.
// 
//Example 1:
//Input: rectangles = [[4,8],[3,6],[10,20],[15,30]]
//Output: 6
//Explanation: The following are the interchangeable pairs of rectangles by index (0-indexed):
//- Rectangle 0 with rectangle 1: 4/8 == 3/6.
//- Rectangle 0 with rectangle 2: 4/8 == 10/20.
//- Rectangle 0 with rectangle 3: 4/8 == 15/30.
//- Rectangle 1 with rectangle 2: 3/6 == 10/20.
//- Rectangle 1 with rectangle 3: 3/6 == 15/30.
//- Rectangle 2 with rectangle 3: 10/20 == 15/30.
//Example 2:
//Input: rectangles = [[4,5],[7,8]]
//Output: 0
//Explanation: There are no interchangeable pairs of rectangles.
// 
//Constraints:
//	n == rectangles.length
//	1 <= n <= 105
//	rectangles[i].length == 2
//	1 <= widthi, heighti <= 105
// Helper function to compute the greatest common divisor
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long interchangeableRectangles(int** rectangles, int rectanglesSize, int* rectanglesColSize) {
    long long count = 0;
    for (int i = 0; i < rectanglesSize; i++) {
        for (int j = i + 1; j < rectanglesSize; j++) {
            int width1 = rectangles[i][0], height1 = rectangles[i][1];
            int width2 = rectangles[j][0], height2 = rectangles[j][1];

            // Reduce the ratios by their gcd to compare
            int gcd1 = gcd(width1, height1);
            int gcd2 = gcd(width2, height2);

            if (width1 / gcd1 == width2 / gcd2 && height1 / gcd1 == height2 / gcd2) {
                count++;
            }
        }
    }
    return count;
}
    