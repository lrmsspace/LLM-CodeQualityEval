/**https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/ */
//Given the array orders, which represents the orders that customers have done in a restaurant. More specifically orders[i]=[customerNamei,tableNumberi,foodItemi] where customerNamei is the name of the customer, tableNumberi is the table customer sit at, and foodItemi is the item customer orders.
//Return the restaurant's “display table”. The “display table” is a table whose row entries denote how many of each food item each table ordered. The first column is the table number and the remaining columns correspond to each food item in alphabetical order. The first row should be a header whose first column is “Table”, followed by the names of the food items. Note that the customer names are not part of the table. Additionally, the rows should be sorted in numerically increasing order.
// 
//Example 1:
//Input: orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]
//Output: [["Table","Beef Burrito","Ceviche","Fried Chicken","Water"],["3","0","2","1","0"],["5","0","1","0","1"],["10","1","0","0","0"]] 
//Explanation:
//The displaying table looks like:
//Table,Beef Burrito,Ceviche,Fried Chicken,Water
//3    ,0           ,2      ,1            ,0
//5    ,0           ,1      ,0            ,1
//10   ,1           ,0      ,0            ,0
//For the table 3: David orders "Ceviche" and "Fried Chicken", and Rous orders "Ceviche".
//For the table 5: Carla orders "Water" and "Ceviche".
//For the table 10: Corina orders "Beef Burrito". 
//Example 2:
//Input: orders = [["James","12","Fried Chicken"],["Ratesh","12","Fried Chicken"],["Amadeus","12","Fried Chicken"],["Adam","1","Canadian Waffles"],["Brianna","1","Canadian Waffles"]]
//Output: [["Table","Canadian Waffles","Fried Chicken"],["1","2","0"],["12","0","3"]] 
//Explanation: 
//For the table 1: Adam and Brianna order "Canadian Waffles".
//For the table 12: James, Ratesh and Amadeus order "Fried Chicken".
//Example 3:
//Input: orders = [["Laura","2","Bean Burrito"],["Jhon","2","Beef Burrito"],["Melissa","2","Soda"]]
//Output: [["Table","Bean Burrito","Beef Burrito","Soda"],["2","1","1","1"]]
// 
//Constraints:
//	1 <= orders.length <= 5 * 10^4
//	orders[i].length == 3
//	1 <= customerNamei.length, foodItemi.length <= 20
//	customerNamei and foodItemi consist of lowercase and uppercase English letters and the space character.
//	tableNumberi is a valid integer between 1 and 500.
class Solution {

public:

    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        unordered_map<string, unordered_map<string, int>> food_table;
        set<int> table_numbers;
        unordered_set<string> food_items;
        
        for (const auto& order : orders) {
            int table_num = stoi(order[1]);
            table_numbers.insert(table_num);
            food_table[table_num][order[2]]++;
            food_items.insert(order[2]);
        }
        
        vector<vector<string>> result(table_numbers.size() + 1, vector<string>(food_items.size() + 1));
        result[0][0] = "Table";
        for (int i = 1; i <= table_numbers.size(); ++i) {
            result[i][0] = to_string(table_numbers.find(i)->first);
        }
        int food_index = 1;
        for (const auto& food : food_items) {
            result[0][food_index] = food;
            food_index++;
        }
        
        for (int i = 1; i <= table_numbers.size(); ++i) {
            for (int j = 1; j <= food_items.size(); ++j) {
                result[i][j] = to_string(food_table[table_numbers.find(i)->first][food_items.find(food_index - 1)->first]);
            }
        }
        
        sort(result.begin(), result.end(), [](const vector<string>& a, const vector<string>& b) {
            return stoi(a[0]) < stoi(b[0]);
        });
        
        return result;

    }

};