/**https://leetcode.com/problems/prison-cells-after-n-days/ */
//There are 8 prison cells in a row and each cell is either occupied or vacant.
//Each day, whether the cell is occupied or vacant changes according to the following rules:
//	If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
//	Otherwise, it becomes vacant.
//Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.
//You are given an integer array cells where cells[i] == 1 if the ith cell is occupied and cells[i] == 0 if the ith cell is vacant, and you are given an integer n.
//Return the state of the prison after n days (i.e., n such changes described above).
// 
//Example 1:
//Input: cells = [0,1,0,1,1,0,0,1], n = 7
//Output: [0,0,1,1,0,0,0,0]
//Explanation: The following table summarizes the state of the prison on each day:
//Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
//Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
//Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
//Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
//Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
//Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
//Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
//Day 7: [0, 0, 1, 1, 0, 0, 0, 0]
//Example 2:
//Input: cells = [1,0,0,1,0,0,1,0], n = 1000000000
//Output: [0,0,1,1,1,1,1,0]
// 
//Constraints:
//	cells.length == 8
//	cells[i] is either 0 or 1.
//	1 <= n <= 109
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<string, int> mp;
        string key;
        for(int i = 0; i < cells.size(); i++){
            key += to_string(cells[i]);
        }
        mp[key] = 0;
        int i = 1;
        while(i <= n){
            vector<int> next(cells.size(), 0);
            for(int j = 1; j < cells.size() - 1; j++){
                next[j] = cells[j - 1] ^ cells[j + 1];
            }
            cells = next;
            key = "";
            for(int k = 0; k < cells.size(); k++){
                key += to_string(cells[k]);
            }
            if(mp.find(key) != mp.end()){
                int cycle = i - mp[key];
                int remain = (n - i) % cycle;
                for(int j = 0; j < remain; j++){
                    vector<int> next(cells.size(), 0);
                    for(int k = 1; k < cells.size() - 1; k++){
                        next[k] = cells[k - 1] ^ cells[k + 1];
                    }
                    cells = next;
                }
                break;
            }
            else{
                mp[key] = i;
            }
            i++;
        }
        return cells;
    }
};