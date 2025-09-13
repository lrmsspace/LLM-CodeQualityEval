/**https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/ */
//Given the array orders, which represents the orders that customers have done in a restaurant. More specifically orders[i]=[customerNamei,tableNumberi,foodItemi] where customerNamei is the name of the customer, tableNumberi is the table customer sit at, and foodItemi is the item customer orders._x000D_
//_x000D_
//Return the restaurant's “display table”. The “display table” is a table whose row entries denote how many of each food item each table ordered. The first column is the table number and the remaining columns correspond to each food item in alphabetical order. The first row should be a header whose first column is “Table”, followed by the names of the food items. Note that the customer names are not part of the table. Additionally, the rows should be sorted in numerically increasing order._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]_x000D_
//Output: [["Table","Beef Burrito","Ceviche","Fried Chicken","Water"],["3","0","2","1","0"],["5","0","1","0","1"],["10","1","0","0","0"]] _x000D_
//Explanation:_x000D_
//The displaying table looks like:_x000D_
//Table,Beef Burrito,Ceviche,Fried Chicken,Water_x000D_
//3    ,0           ,2      ,1            ,0_x000D_
//5    ,0           ,1      ,0            ,1_x000D_
//10   ,1           ,0      ,0            ,0_x000D_
//For the table 3: David orders "Ceviche" and "Fried Chicken", and Rous orders "Ceviche"._x000D_
//For the table 5: Carla orders "Water" and "Ceviche"._x000D_
//For the table 10: Corina orders "Beef Burrito". _x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: orders = [["James","12","Fried Chicken"],["Ratesh","12","Fried Chicken"],["Amadeus","12","Fried Chicken"],["Adam","1","Canadian Waffles"],["Brianna","1","Canadian Waffles"]]_x000D_
//Output: [["Table","Canadian Waffles","Fried Chicken"],["1","2","0"],["12","0","3"]] _x000D_
//Explanation: _x000D_
//For the table 1: Adam and Brianna order "Canadian Waffles"._x000D_
//For the table 12: James, Ratesh and Amadeus order "Fried Chicken"._x000D_
//_x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//Input: orders = [["Laura","2","Bean Burrito"],["Jhon","2","Beef Burrito"],["Melissa","2","Soda"]]_x000D_
//Output: [["Table","Bean Burrito","Beef Burrito","Soda"],["2","1","1","1"]]_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= orders.length <= 5 * 10^4_x000D_
//	orders[i].length == 3_x000D_
//	1 <= customerNamei.length, foodItemi.length <= 20_x000D_
//	customerNamei and foodItemi consist of lowercase and uppercase English letters and the space character._x000D_
//	tableNumberi is a valid integer between 1 and 500._x000D_
/**_x000D_
 * Return an array of arrays of size *returnSize._x000D_
 * The sizes of the arrays are returned as *returnColumnSizes array._x000D_
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free()._x000D_
 */_x000D_
char *** displayTable(char *** orders, int ordersSize, int* ordersColSize, int* returnSize, int** returnColumnSizes){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int table[500][20]={0};
    int food[20]={0};
    int food_num=0;
    int table_num=0;
    int table_num_max=0;
    int food_num_max=0;
    int table_num_min=500;
    for(i=0;i<ordersSize;i++){
        for(j=2;j<ordersColSize[i];j++){
            food[j-2]=1;
        }
    }
    for(i=0;i<20;i++){
        if(food[i]==1){
            food_num++;
        }
    }
    for(i=0;i<ordersSize;i++){
        table[atoi(orders[i][1])-1][0]=1;
    }
    for(i=0;i<500;i++){
        if(table[i][0]==1){
            table_num++;
        }
    }
    for(i=0;i<500;i++){
        for(j=1;j<20;j++){
            if(table[i][j]==1){
                food_num_max++;
            }
        }
    }
    for(i=0;i<500;i++){
        for(j=1;j<20;j++){
            if(table[i][j]==1){
                table_num_max++;
            }
        }
    }
    for(i=0;i<500;i++){
        for(j=1;j<20;j++){
            if(table[i][j]==1){
                table_num_min=i;
                break;
            }
        }
    }
    char *** ret=(char***)malloc(sizeof(char**)*table_num);
    for(i=0;i<table_num;i++){
        ret[i]=(char**)malloc(sizeof(char*)*food_num);
        for(j=0;j<food_num;j++){
            ret[i][j]=(char*)malloc(sizeof(char)*20);
        }
    }
    for(i=0;i<food_num;i++){
        sprintf(ret[0][i],"%s",orders[0][2]);
    }
    for(i=0;i<table_num;i++){
        sprintf(ret[i][0],"%d",i+table_num_min+1);
    }
    for(i=0;i<ordersSize;i++){
        for(j=0;j<food_num;j++){
            if(strcmp(ret[0][j],orders[i][2])==0){
                for(k=0;k<table_num;k++){
                    if(strcmp(ret[k][0],orders[i][1])==0){
                        sprintf(ret[k][j+1],"%d",atoi(ret[k][j+1])+1);
                    }
                }
            }
        }
    }
    *returnSize=table_num;
    *returnColumnSizes=(int*)malloc(sizeof(int)*table_num);
    for(i=0;i<table_num;i++){
        (*returnColumnSizes)[i]=food_num+1;
    }
    return ret;
}