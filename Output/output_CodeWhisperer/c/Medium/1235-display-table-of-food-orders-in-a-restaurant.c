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
    
// Comparison function for string sorting (for food items)
int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

// Comparison function for table numbers (as strings)
int compareTableNumbers(const void* a, const void* b) {
    return atoi(*(const char**)a) - atoi(*(const char**)b);
}

char*** displayTable(char*** orders, int ordersSize, int* ordersColSize, int* returnSize, int** returnColumnSizes) {
    // Step 1: Collect unique table numbers and food items
    char* tableNumbers[500]; // Max 500 tables per constraints
    char* foodItems[500];    // Assuming reasonable max number of food items
    int tableCount = 0;
    int foodCount = 0;
    
    // Hash tables to track unique tables and foods
    int tableExists[501] = {0}; // 1-indexed tables
    char* foodExists[10000] = {NULL}; // Using a simple hash table for foods
    int foodExistsCount = 0;
    
    // First pass: collect unique table numbers and food items
    for (int i = 0; i < ordersSize; i++) {
        char* tableNumber = orders[i][1];
        char* foodItem = orders[i][2];
        
        // Add table if not seen before
        int tableNum = atoi(tableNumber);
        if (!tableExists[tableNum]) {
            tableExists[tableNum] = 1;
            tableNumbers[tableCount++] = strdup(tableNumber);
        }
        
        // Add food item if not seen before
        int foodFound = 0;
        for (int j = 0; j < foodExistsCount; j++) {
            if (strcmp(foodExists[j], foodItem) == 0) {
                foodFound = 1;
                break;
            }
        }
        
        if (!foodFound) {
            foodExists[foodExistsCount++] = foodItem;
            foodItems[foodCount++] = strdup(foodItem);
        }
    }
    
    // Sort table numbers numerically
    qsort(tableNumbers, tableCount, sizeof(char*), compareTableNumbers);
    
    // Sort food items alphabetically
    qsort(foodItems, foodCount, sizeof(char*), compareStrings);
    
    // Step 2: Create the display table
    // +1 for the header row, +1 for the "Table" column
    *returnSize = tableCount + 1;
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = foodCount + 1;
    }
    
    char*** result = (char***)malloc(*returnSize * sizeof(char**));
    
    // Create the header row
    result[0] = (char**)malloc((foodCount + 1) * sizeof(char*));
    result[0][0] = strdup("Table");
    for (int i = 0; i < foodCount; i++) {
        result[0][i + 1] = strdup(foodItems[i]);
    }
    
    // Initialize the table with zeros
    for (int i = 0; i < tableCount; i++) {
        result[i + 1] = (char**)malloc((foodCount + 1) * sizeof(char*));
        result[i + 1][0] = strdup(tableNumbers[i]);
        
        for (int j = 0; j < foodCount; j++) {
            result[i + 1][j + 1] = strdup("0");
        }
    }
    
    // Fill in the counts
    for (int i = 0; i < ordersSize; i++) {
        char* tableNumber = orders[i][1];
        char* foodItem = orders[i][2];
        
        // Find the row (table) index
        int rowIndex = -1;
        for (int j = 0; j < tableCount; j++) {
            if (strcmp(tableNumbers[j], tableNumber) == 0) {
                rowIndex = j + 1; // +1 because header is at index 0
                break;
            }
        }
        
        // Find the column (food) index
        int colIndex = -1;
        for (int j = 0; j < foodCount; j++) {
            if (strcmp(foodItems[j], foodItem) == 0) {
                colIndex = j + 1; // +1 because "Table" is at index 0
                break;
            }
        }
        
        // Increment the count
        if (rowIndex != -1 && colIndex != -1) {
            int currentCount = atoi(result[rowIndex][colIndex]);
            free(result[rowIndex][colIndex]);
            
            // Convert new count to string
            char countStr[10];
            sprintf(countStr, "%d", currentCount + 1);
            result[rowIndex][colIndex] = strdup(countStr);
        }
    }
    
    // Free temporary arrays
    for (int i = 0; i < tableCount; i++) {
        free(tableNumbers[i]);
    }
    for (int i = 0; i < foodCount; i++) {
        free(foodItems[i]);
    }
    
    return result;
}
