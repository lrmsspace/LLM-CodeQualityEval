/**https://leetcode.com/problems/valid-square/ */
//Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.
//The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.
//A valid square has four equal sides with positive length and four equal angles (90-degree angles).
// 
//Example 1:
//Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
//Output: true
//Example 2:
//Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
//Output: false
//Example 3:
//Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
//Output: true
// 
//Constraints:
//	p1.length == p2.length == p3.length == p4.length == 2
//	-104 <= xi, yi <= 104
bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size) {
    int distanceSquared(int* p1, int* p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + 
               (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }   
    // Store all points in an array for easier access
    int* points[4] = {p1, p2, p3, p4};
    
    // Calculate all pairwise distances (squared)
    int distances[6];
    int idx = 0;
    
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            distances[idx++] = distanceSquared(points[i], points[j]);
        }
    }
    
    // Sort distances to group sides and diagonals
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (distances[i] > distances[j]) {
                int temp = distances[i];
                distances[i] = distances[j];
                distances[j] = temp;
            }
        }
    }
    
    // Check if the points form a square:
    // 1. All sides should be equal and non-zero
    // 2. Both diagonals should be equal
    return distances[0] > 0 &&                // Sides must have positive length
           distances[0] == distances[1] &&    // First side equals second side
           distances[1] == distances[2] &&    // Second side equals third side
           distances[2] == distances[3] &&    // Third side equals fourth side
           distances[4] == distances[5];      // First diagonal equals second diagonal
}
