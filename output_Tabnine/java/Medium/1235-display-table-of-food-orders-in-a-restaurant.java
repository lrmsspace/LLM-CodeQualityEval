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
        Map<String, Map<String, Integer>> foodMap = new HashMap<>();
        Set<Integer> tables = new HashSet<>();
        for (List<String> order : orders) {
            String customer = order.get(0);
            int table = Integer.parseInt(order.get(1));
            String food = order.get(2);
            tables.add(table);
            Map<String, Integer> tableFood = foodMap.computeIfAbsent(table + "", k -> new HashMap<>());
            tableFood.put(food, tableFood.getOrDefault(food, 0) + 1);
            foodMap.put(table + "", tableFood);
            foodMap.put(customer, foodMap.computeIfAbsent(customer, k -> new HashMap<>()));
            foodMap.get(customer).put(food, foodMap.get(customer).getOrDefault(food, 0) + 1);
            foodMap.put(food, foodMap.computeIfAbsent(food, k -> new HashMap<>()));
            foodMap.get(food).put(customer, foodMap.get(food).getOrDefault(customer, 0) + 1);
            foodMap.get(food).put("Total", foodMap.get(food).getOrDefault("Total", 0) + 1);
            foodMap.get("Total").put(food, foodMap.get("Total").getOrDefault(food, 0) + 1);
            foodMap.get("Total").put("Total", foodMap.get("Total").getOrDefault("Total", 0) + 1);
            foodMap.get("Customer").put(customer, foodMap.get("Customer").getOrDefault(customer, 0) + 1);
            foodMap.get("Customer").put("Total", foodMap.get("Customer").getOrDefault("Total", 0) + 1);
            foodMap.get("Table").put(table + "", foodMap.get("Table").getOrDefault(table + "", 0) + 1);
            foodMap.get("Table").put("Total", foodMap.get("Table").getOrDefault("Total", 0) + 1);
            foodMap.get("Food").put(food, foodMap.get("Food").getOrDefault(food, 0) + 1);
            foodMap.get("Food").put("Total", foodMap.get("Food").getOrDefault("Total", 0) + 1);
            foodMap.get("Total").put("Food", foodMap.get("Total").getOrDefault("Food", 0) + 1);
            foodMap.get("Total").put("Total", foodMap.get("Total").getOrDefault("Total", 0) + 1);
            foodMap.get("Total").put("Customer", foodMap.get("Total").getOrDefault("Customer", 0) + 1);
            foodMap.get("Total").put("Table", foodMap.get("Total").getOrDefault("Table", 0) + 1);
            foodMap.get("Customer").put("Food", foodMap.get("Customer").getOrDefault("Food", 0) + 1);
            foodMap.get("Customer").put("Table", foodMap.get("Customer").getOrDefault("Table", 0) + 1);
            foodMap.get("Food").put("Customer", foodMap.get("Food").getOrDefault("Customer", 0) + 1);
            foodMap.get("Food").put("Table", foodMap.get("Food").getOrDefault("Table", 0) + 1);
            foodMap.get("Table").put("Food", foodMap.get("Table").getOrDefault("Food", 0) + 1);
            foodMap.get("Table").put("Customer", foodMap.get("Table").getOrDefault("Customer", 0) + 1);
            foodMap.get("Customer").put("Table", foodMap.get("Customer").getOrDefault("Table", 0) + 1);
            foodMap.get("Table").put("Total", foodMap.get("Table").getOrDefault("Total", 0) + 1);
            foodMap.get("Customer").put("Total", foodMap.get("Customer").getOrDefault("Total", 0) + 1);
            foodMap.get("Food").put("Total", foodMap.get("Food").getOrDefault("Total", 0) + 1);
            foodMap.get("Total").put("Total", foodMap.get("Total").getOrDefault("Total", 0) + 1);
            foodMap.get("Table").put("Food", foodMap.get("Table").getOrDefault("Food", 0) + 1);
            foodMap.get("Table").put("Customer", foodMap.get("Table").getOrDefault("Customer", 0) + 1);
            foodMap.get("Customer").put("Table", foodMap.get("Customer").getOrDefault("Table", 0) + 1);
            foodMap.get("Total").put("Food", foodMap.get("Total").getOrDefault("Food", 0) + 1);
            foodMap.get("Total").put("Customer", foodMap.get("Total").getOrDefault("Customer", 0) + 1);
            foodMap.get("Total").put("Table", foodMap.get("Total").getOrDefault("Table", 0) + 1);
            foodMap.get("Food").put("Total", foodMap.get("Food").getOrDefault("Total", 0) + 1);
            foodMap.get("Food").put("Customer", foodMap.get("Food").getOrDefault("Customer", 0) + 1);
            foodMap.get("Food").put("Table", foodMap.get("Food").getOrDefault("Table", 0) + 1);

            foodMap.get("Customer").put(customer, foodMap.get(customer).getOrDefault(customer, 0) + 1);
            foodMap.get("Customer").put("Total", foodMap.get("Customer").getOrDefault("Total", 0) + 1);
            foodMap.get("Total").put("Customer", foodMap.get("Total").getOrDefault("Customer", 0) + 1);
        }
        List<List<String>> result = new ArrayList<>();
        List<String> header = new ArrayList<>();
        header.add("");
        header.addAll(tables.stream().sorted().map(String::valueOf).collect(Collectors.toList()));
        header.add("Total");
        result.add(header);
        for (Map.Entry<String, Map<String, Integer>> entry : foodMap.entrySet()) {
            List<String> row = new ArrayList<>();
            row.add(entry.getKey());
            row.addAll(entry.getValue().entrySet().stream().filter(e ->!e.getKey().equals("Total")).sorted(Map.Entry.comparingByKey())
                   .map(Map.Entry::getKey).collect(Collectors.toList()));
            row.add(entry.getValue().getOrDefault("Total", 0) + "");
            result.add(row);
        }
        return result;
    }

}