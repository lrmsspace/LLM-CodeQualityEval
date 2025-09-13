/*
 You are given two strings, coordinate1 and coordinate2, representing the coordinates of a square on an 8 x 8 chessboard.
 Below is the chessboard for reference.
 Return true if these two squares have the same color and false otherwise.
 The coordinate will always represent a valid chessboard square. The coordinate will always have the letter first (indicating its column), and the number second (indicating its row).
 Example 1:
 Input: coordinate1 = "a1", coordinate2 = "c3"
 Output: true
 Explanation:
 Both squares are black.
 Example 2:
 Input: coordinate1 = "a1", coordinate2 = "h3"
 Output: false
 Explanation:
 Square "a1" is black and "h3" is white.
 Constraints:
 coordinate1.length == coordinate2.length == 2
 'a' <= coordinate1[0], coordinate2[0] <= 'h'
 '1' <= coordinate1[1], coordinate2[1] <= '8'
*/

class Solution {
    public boolean checkTwoChessboards(String coordinate1, String coordinate2) {
        int row1 = coordinate1.charAt(1) - '1';
        int row2 = coordinate2.charAt(1) - '1';
        int col1 = coordinate1.charAt(0) - 'a';
        int col2 = coordinate2.charAt(0) - 'a';
        
        // Check if the rows or columns are the same
        if (row1 == row2 || col1 == col2) {
            return false;
        }
        
        // Create two arrays to store the colors of each row and column
        boolean[] rowColors1 = new boolean[8];
        boolean[] rowColors2 = new boolean[8];
        boolean[] colColors1 = new boolean[8];

        // Fill the arrays with the colors of the squares
        for (int i = 0; i < 8; i++) {
            rowColors1[i] = (i + col1) % 2 == 0;
            rowColors2[i] = (i + col2) % 2 == 0;
            colColors1[i] = (i + row1) % 2 == 0;
        }
        
        // Check if the colors of the rows and columns are the same
        for (int i = 0; i < 8; i++) {
            if (rowColors1[i]!= rowColors2[i] || colColors1[i]!= colColors2[i]) {
                return false;
            }
        }
        
        return true;
        
    }
}