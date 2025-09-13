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
/**

 * Return an array of arrays of size *returnSize.

 * The sizes of the arrays are returned as *returnColumnSizes array.

 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().

 */
    // Define a comparator for sorting strings
    int compareStrings(const void *a, const void *b) {
        return strcmp(*(const char **)a, *(const char **)b);
    }

    // Define a comparator for sorting integers
    int compareInts(const void *a, const void *b) {
        return (*(int *)a - *(int *)b);
    }

    char *** displayTable(char *** orders, int ordersSize, int* ordersColSize, int* returnSize, int** returnColumnSizes) {
        // Use hash tables to store food items and table orders
        char **foodItems = malloc(ordersSize * sizeof(char *));
        int foodCount = 0;

        int tableOrders[501][ordersSize];
        memset(tableOrders, 0, sizeof(tableOrders));

        int tableNumbers[501] = {0};
        int tableCount = 0;

        // Collect food items and table orders
        for (int i = 0; i < ordersSize; i++) {
            char *tableStr = orders[i][1];
            char *food = orders[i][2];

            int table = atoi(tableStr);

            // Add food item if not already present
            int foodIndex = -1;
            for (int j = 0; j < foodCount; j++) {
                if (strcmp(foodItems[j], food) == 0) {
                    foodIndex = j;
                    break;
                }
            }
            if (foodIndex == -1) {
                foodItems[foodCount++] = food;
            }

            // Mark table as present
            if (!tableNumbers[table]) {
                tableNumbers[table] = 1;
                tableCount++;
            }

            // Increment the count for the food item at the table
            tableOrders[table][foodIndex]++;
        }

        // Sort food items alphabetically
        qsort(foodItems, foodCount, sizeof(char *), compareStrings);

        // Sort table numbers numerically
        int sortedTables[tableCount];
        int idx = 0;
        for (int i = 1; i <= 500; i++) {
            if (tableNumbers[i]) {
                sortedTables[idx++] = i;
            }
        }
        qsort(sortedTables, tableCount, sizeof(int), compareInts);

        // Prepare the result table
        char ***result = malloc((tableCount + 1) * sizeof(char **));
        *returnColumnSizes = malloc((tableCount + 1) * sizeof(int));

        // Fill the header row
        result[0] = malloc((foodCount + 1) * sizeof(char *));
        (*returnColumnSizes)[0] = foodCount + 1;
        result[0][0] = strdup("Table");
        for (int i = 0; i < foodCount; i++) {
            result[0][i + 1] = strdup(foodItems[i]);
        }

        // Fill the table rows
        for (int i = 0; i < tableCount; i++) {
            int table = sortedTables[i];
            result[i + 1] = malloc((foodCount + 1) * sizeof(char *));
            (*returnColumnSizes)[i + 1] = foodCount + 1;

            // Add table number
            char tableStr[10];
            sprintf(tableStr, "%d", table);
            result[i + 1][0] = strdup(tableStr);

            // Add food counts
            for (int j = 0; j < foodCount; j++) {
                int count = tableOrders[table][j];
                char countStr[10];
                sprintf(countStr, "%d", count);
                result[i + 1][j + 1] = strdup(countStr);
            }
        }

        *returnSize = tableCount + 1;

        // Free temporary memory
        free(foodItems);

        return result;
    }
    
    