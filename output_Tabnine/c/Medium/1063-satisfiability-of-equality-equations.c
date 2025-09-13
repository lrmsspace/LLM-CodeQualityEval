/**https://leetcode.com/problems/satisfiability-of-equality-equations/ */
//You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.
//Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.
// 
//Example 1:
//Input: equations = ["a==b","b!=a"]
//Output: false
//Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
//There is no way to assign the variables to satisfy both equations.
//Example 2:
//Input: equations = ["b==a","a==b"]
//Output: true
//Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
// 
//Constraints:
//	1 <= equations.length <= 500
//	equations[i].length == 4
//	equations[i][0] is a lowercase letter.
//	equations[i][1] is either '=' or '!'.
//	equations[i][2] is '='.
//	equations[i][3] is a lowercase letter.
bool equationsPossible(char** equations, int equationsSize) {
    int n = equationsSize;
    int* parent = new int[26];
    for (int i = 0; i < 26; ++i) {
        parent[i] = i;
    }
    
    for (int i = 0; i < n; ++i) {
        char x = equations[i][0] - 'a';
        char y = equations[i][3] - 'a';
        char op = equations[i][1];
        
        if (op == '=') {
            int px = find(parent, x);
            int py = find(parent, y);
            if (px!= py) {
                parent[px] = py;
            }
        } else {
            int px = find(parent, x);
            int py = find(parent, y);
            if (px == py) {
                return false;
            }
        }
    }
    
    delete[] parent;
    return true;
    
}