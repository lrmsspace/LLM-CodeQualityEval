/**https://leetcode.com/problems/fruit-into-baskets/ */
//You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.
//You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
//	You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
//	Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
//	Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
//Given the integer array fruits, return the maximum number of fruits you can pick.
// 
//Example 1:
//Input: fruits = [1,2,1]
//Output: 3
//Explanation: We can pick from all 3 trees.
//Example 2:
//Input: fruits = [0,1,2,2]
//Output: 3
//Explanation: We can pick from trees [1,2,2].
//If we had started at the first tree, we would only pick from trees [0,1].
//Example 3:
//Input: fruits = [1,2,3,2,2]
//Output: 4
//Explanation: We can pick from trees [2,3,2,2].
//If we had started at the first tree, we would only pick from trees [1,2].
// 
//Constraints:
//	1 <= fruits.length <= 105
//	0 <= fruits[i] < fruits.length
int totalFruit(int* fruits, int fruitsSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    i=0;
    j=0;
    k=0;
    l=0;
    m=0;
    n=0;
    o=0;
    p=0;
    q=0;
    r=0;
    s=0;
   t=0;
    u=0;
    v=0;
    w=0;
    x=0;
    y=0;
    z=0;
    while(i<fruitsSize){
        if(fruits[i]==fruits[i-1]){
            i++;
        }else{
            break;
        }
    }
    while(i<fruitsSize){
        if(fruits[i]==fruits[i-1]){
            i++;
        }else{
            break;
        }
    }
    while(i<fruitsSize){
        if(fruits[i]==fruits[i-1]){
            i++;
        }else{
            break;
        }
    }
    return i-z;
}