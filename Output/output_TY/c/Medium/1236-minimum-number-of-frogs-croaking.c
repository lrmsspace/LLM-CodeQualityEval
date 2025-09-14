/**https://leetcode.com/problems/minimum-number-of-frogs-croaking/ */
//You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple "croak" are mixed.
//Return the minimum number of different frogs to finish all the croaks in the given string.
//A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of a valid "croak" return -1.
// 
//Example 1:
//Input: croakOfFrogs = "croakcroak"
//Output: 1 
//Explanation: One frog yelling "croak" twice.
//Example 2:
//Input: croakOfFrogs = "crcoakroak"
//Output: 2 
//Explanation: The minimum number of frogs is two. 
//The first frog could yell "crcoakroak".
//The second frog could yell later "crcoakroak".
//Example 3:
//Input: croakOfFrogs = "croakcrook"
//Output: -1
//Explanation: The given string is an invalid combination of "croak" from different frogs.
// 
//Constraints:
//	1 <= croakOfFrogs.length <= 105
//	croakOfFrogs is either 'c', 'r', 'o', 'a', or 'k'.
int minNumberOfFrogs(char * croakOfFrogs){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int a[5]={0};
    int b=0;
    for(i=0;i<strlen(croakOfFrogs);i++){
        if(croakOfFrogs[i]=='c'){
            a[0]++;
        }
    }   
    for(i=0;i<strlen(croakOfFrogs);i++){
        if(croakOfFrogs[i]=='r'){
            a[1]++;
        }
    }
    for(i=0;i<strlen(croakOfFrogs);i++){
        if(croakOfFrogs[i]=='o'){
            a[2]++;
        }
    }
    for(i=0;i<strlen(croakOfFrogs);i++){
        if(croakOfFrogs[i]=='a'){
            a[3]++;
        }
    }
    for(i=0;i<strlen(croakOfFrogs);i++){
        if(croakOfFrogs[i]=='k'){
            a[4]++;
        }
    }
    for(i=0;i<5;i++){
        if(a[i]%2!=0){
            return -1;
        }
    }
    for(i=0;i<strlen(croakOfFrogs);i++){
        if(croakOfFrogs[i]=='c'){
            b++;
        }
        else if(croakOfFrogs[i]=='k'){
            b--;
        }
        if(b<0){
            return -1;
        }
    }
    return b/5;
}