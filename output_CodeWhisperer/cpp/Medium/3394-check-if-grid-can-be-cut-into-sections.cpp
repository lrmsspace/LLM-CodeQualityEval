/*
 You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:
 (startx, starty): The bottom-left corner of the rectangle.
 (endx, endy): The top-right corner of the rectangle.
 Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:
 Each of the three resulting sections formed by the cuts contains at least one rectangle.
 Every rectangle belongs to exactly one section.
 Return true if such cuts can be made; otherwise, return false.
 Example 1:
 Input: n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]
 Output: true
 Explanation:
 The grid is shown in the diagram. We can make horizontal cuts at y = 2 and y = 4. Hence, output is true.
 Example 2:
 Input: n = 4, rectangles = [[0,0,1,1],[2,0,3,4],[0,2,2,3],[3,0,4,3]]
 Output: true
 Explanation:
 We can make vertical cuts at x = 2 and x = 3. Hence, output is true.
 Example 3:
 Input: n = 4, rectangles = [[0,2,2,4],[1,0,3,2],[2,2,3,4],[3,0,4,2],[3,2,4,4]]
 Output: false
 Explanation:
 We cannot make two horizontal or two vertical cuts that satisfy the conditions. Hence, output is false.
 Constraints:
 3 <= n <= 109
 3 <= rectangles.length <= 105
 0 <= rectangles[i][0] < rectangles[i][2] <= n
 0 <= rectangles[i][1] < rectangles[i][3] <= n
 No two rectangles overlap.
*/

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    // Try horizontal cuts
    set<int> yCoords;
    for (auto& rect : rectangles) {
        yCoords.insert(rect[1]);
        yCoords.insert(rect[3]);
    }
    
    // Try each pair of y coordinates as cuts
    for (auto y1 : yCoords) {
        for (auto y2 : yCoords) {
            if (y1 >= y2) continue;
            
            vector<int> sections(3, 0);
            
            // Count rectangles in each section
            for (auto& rect : rectangles) {
                if (rect[3] <= y1) sections[0]++;
                else if (rect[1] >= y2) sections[2]++;
                else if (rect[1] >= y1 && rect[3] <= y2) sections[1]++;
            }
            
            // Check if valid cuts
            if (sections[0] > 0 && sections[1] > 0 && sections[2] > 0 && 
                sections[0] + sections[1] + sections[2] == rectangles.size()) {
                return true;
            }
        }
    }
    
    // Try vertical cuts
    set<int> xCoords;
    for (auto& rect : rectangles) {
        xCoords.insert(rect[0]);
        xCoords.insert(rect[2]);
    }
    
    // Try each pair of x coordinates as cuts
    for (auto x1 : xCoords) {
        for (auto x2 : xCoords) {
            if (x1 >= x2) continue;
            
            vector<int> sections(3, 0);
            
            // Count rectangles in each section
            for (auto& rect : rectangles) {
                if (rect[2] <= x1) sections[0]++;
                else if (rect[0] >= x2) sections[2]++;
                else if (rect[0] >= x1 && rect[2] <= x2) sections[1]++;
            }
            
            // Check if valid cuts
            if (sections[0] > 0 && sections[1] > 0 && sections[2] > 0 && 
                sections[0] + sections[1] + sections[2] == rectangles.size()) {
                return true;
            }
        }
    }
    
    return false;
}                    
    
};