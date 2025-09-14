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

char *** displayTable(char *** orders, int ordersSize, int* ordersColSize, int* returnSize, int** returnColumnSizes){


    int tableSize = 501;
    int *table = (int *)malloc(tableSize * sizeof(int));
    memset(table, 0, tableSize * sizeof(int));

    char ***menu = (char ***)malloc(501 * sizeof(char **));
    for (int i = 0; i < 501; i++) {
        menu[i] = (char **)malloc(21 * sizeof(char *));
        for (int j = 0; j < 21; j++) {
            menu[i][j] = (char *)malloc(21 * sizeof(char));
        }
    }

    int menuSize = 0;
    for (int i = 0; i < ordersSize; i++) {
        int tableNumber = atoi(orders[i][1]);
        table[tableNumber]++;
        int hash = 0;
        for (int j = 0; j < strlen(orders[i][2]); j++) {
            hash += orders[i][2][j];
        }
        if (menu[tableNumber][hash][0] == '\0') {
            strcpy(menu[tableNumber][hash], orders[i][2]);
            menuSize++;
        }
    }

    char ***result = (char ***)malloc((menuSize + 1) * sizeof(char **));
    result[0] = (char **)malloc((menuSize + 1) * sizeof(char *));
    result[0][0] = (char *)malloc(10 * sizeof(char));
    strcpy(result[0][0], "Table");
    for (int i = 1; i <= menuSize; i++) {
        result[0][i] = (char *)malloc(21 * sizeof(char));
        strcpy(result[0][i], menu[tableNumber][i - 1]);
    }

    int resultSize = 1;
    for (int i = 1; i <= 500; i++) {
        if (table[i] > 0) {
            result[resultSize] = (char **)malloc((menuSize + 1) * sizeof(char *));
            result[resultSize][0] = (char *)malloc(10 * sizeof(char));
            sprintf(result[resultSize][0], "%d", i);
            for (int j = 1; j <= menuSize; j++) {
                result[resultSize][j] = (char *)malloc(21 * sizeof(char));
                if (strcmp(menu[i][j - 1], menu[tableNumber][j - 1]) == 0) {
                    sprintf(result[resultSize][j], "%d", table[i]);
                } else {
                    sprintf(result[resultSize][j], "%d", 0);
                }
            }
            resultSize++;
        }
    }

    *returnSize = resultSize;
    *returnColumnSizes = (int *)malloc(resultSize * sizeof(int));
    for (int i = 0; i < resultSize; i++) {
        (*returnColumnSizes)[i] = menuSize + 1;
    }

    return result;
}