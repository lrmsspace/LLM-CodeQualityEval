#https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/
#Given the array orders, which represents the orders that customers have done in a restaurant. More specifically orders[i]=[customerNamei,tableNumberi,foodItemi] where customerNamei is the name of the customer, tableNumberi is the table customer sit at, and foodItemi is the item customer orders.
#Return the restaurant's “display table”. The “display table” is a table whose row entries denote how many of each food item each table ordered. The first column is the table number and the remaining columns correspond to each food item in alphabetical order. The first row should be a header whose first column is “Table”, followed by the names of the food items. Note that the customer names are not part of the table. Additionally, the rows should be sorted in numerically increasing order.
# 
#Example 1:
#Input: orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]
#Output: [["Table","Beef Burrito","Ceviche","Fried Chicken","Water"],["3","0","2","1","0"],["5","0","1","0","1"],["10","1","0","0","0"]] 
#Explanation:
#The displaying table looks like:
#Table,Beef Burrito,Ceviche,Fried Chicken,Water
#3    ,0           ,2      ,1            ,0
#5    ,0           ,1      ,0            ,1
#10   ,1           ,0      ,0            ,0
#For the table 3: David orders "Ceviche" and "Fried Chicken", and Rous orders "Ceviche".
#For the table 5: Carla orders "Water" and "Ceviche".
#For the table 10: Corina orders "Beef Burrito". 
#Example 2:
#Input: orders = [["James","12","Fried Chicken"],["Ratesh","12","Fried Chicken"],["Amadeus","12","Fried Chicken"],["Adam","1","Canadian Waffles"],["Brianna","1","Canadian Waffles"]]
#Output: [["Table","Canadian Waffles","Fried Chicken"],["1","2","0"],["12","0","3"]] 
#Explanation: 
#For the table 1: Adam and Brianna order "Canadian Waffles".
#For the table 12: James, Ratesh and Amadeus order "Fried Chicken".
#Example 3:
#Input: orders = [["Laura","2","Bean Burrito"],["Jhon","2","Beef Burrito"],["Melissa","2","Soda"]]
#Output: [["Table","Bean Burrito","Beef Burrito","Soda"],["2","1","1","1"]]
# 
#Constraints:
#	1 <= orders.length <= 5 * 10^4
#	orders[i].length == 3
#	1 <= customerNamei.length, foodItemi.length <= 20
#	customerNamei and foodItemi consist of lowercase and uppercase English letters and the space character.
#	tableNumberi is a valid integer between 1 and 500.
class Solution(object):

    def displayTable(self, orders):

        """

        :type orders: List[List[str]]

        :rtype: List[List[str]]

        """
        # Create a dictionary to store the food items and their counts for each table
        table_dict = {}

        # Create a set to store unique food items
        food_set = set()

        # Iterate through the orders and populate the table_dict and food_set
        for order in orders:
            customer_name, table_number, food_item = order
            table_number = int(table_number)
            food_set.add(food_item)
            if table_number not in table_dict:
                table_dict[table_number] = {}
            if food_item not in table_dict[table_number]:
                table_dict[table_number][food_item] = 0
            table_dict[table_number][food_item] += 1

        # Sort the food items alphabetically
        food_list = sorted(food_set)
        # Sort the table numbers in ascending order
        table_list = sorted(table_dict.keys())
        # Create the header row
        header = ["Table"] + food_list
        # Initialize the result list with the header
        result = [header]
        # Iterate through the sorted table numbers and populate the result list
        for table_number in table_list:
            row = [str(table_number)]
            for food_item in food_list:
                if food_item in table_dict[table_number]:
                    row.append(str(table_dict[table_number][food_item]))
                else:
                    row.append("0")
            result.append(row)
        return result