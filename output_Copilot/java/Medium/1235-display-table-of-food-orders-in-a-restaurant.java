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

    public List<List<String>> displayTable(List<List<String>> orders) {

        Set<String> foodItems = new TreeSet<>(); // To store unique food items in sorted order
        Map<String, Map<String, Integer>> tableOrders = new HashMap<>(); // To store orders per table

        for (List<String> order : orders) {
            String customerName = order.get(0);
            String tableNumber = order.get(1);
            String foodItem = order.get(2);

            foodItems.add(foodItem); // Add food item to the set

            // Initialize the table's order map if not already present
            tableOrders.putIfAbsent(tableNumber, new HashMap<>());
            Map<String, Integer> foodCount = tableOrders.get(tableNumber);
            foodCount.put(foodItem, foodCount.getOrDefault(foodItem, 0) + 1); // Increment the count of the food item
        }

        List<List<String>> result = new ArrayList<>();
        List<String> header = new ArrayList<>();
        header.add("Table"); // First column header
        header.addAll(foodItems); // Add all food items to the header
        result.add(header);

        // Sort table numbers and prepare the result rows
        List<String> sortedTableNumbers = new ArrayList<>(tableOrders.keySet());
        Collections.sort(sortedTableNumbers, Comparator.comparingInt(Integer::parseInt)); // Sort numerically

        for (String tableNumber : sortedTableNumbers) {
            List<String> row = new ArrayList<>();
            row.add(tableNumber); // Add table number to the row

            Map<String, Integer> foodCount = tableOrders.get(tableNumber);
            for (String foodItem : foodItems) {
                row.add(String.valueOf(foodCount.getOrDefault(foodItem, 0))); // Add count of each food item
            }
            result.add(row); // Add the row to the result
        }

        return result; // Return the final display table
        
    }

}