/**https://leetcode.com/problems/minimum-jumps-to-reach-home/ */
//A certain bug's home is on the x-axis at position x. Help them get there from position 0.
//The bug jumps according to the following rules:
//	It can jump exactly a positions forward (to the right).
//	It can jump exactly b positions backward (to the left).
//	It cannot jump backward twice in a row.
//	It cannot jump to any forbidden positions.
//The bug may jump forward beyond its home, but it cannot jump to positions numbered with negative integers.
//Given an array of integers forbidden, where forbidden[i] means that the bug cannot jump to the position forbidden[i], and integers a, b, and x, return the minimum number of jumps needed for the bug to reach its home. If there is no possible sequence of jumps that lands the bug on position x, return -1.
// 
//Example 1:
//Input: forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9
//Output: 3
//Explanation: 3 jumps forward (0 -> 3 -> 6 -> 9) will get the bug home.
//Example 2:
//Input: forbidden = [8,3,16,6,12,20], a = 15, b = 13, x = 11
//Output: -1
//Example 3:
//Input: forbidden = [1,6,2,14,5,17,4], a = 16, b = 9, x = 7
//Output: 2
//Explanation: One jump forward (0 -> 16) then one jump backward (16 -> 7) will get the bug home.
// 
//Constraints:
//	1 <= forbidden.length <= 1000
//	1 <= a, b, forbidden[i] <= 2000
//	0 <= x <= 2000
//	All the elements in forbidden are distinct.
//	Position x is not forbidden.
int minimumJumps(int* forbidden, int forbiddenSize, int a, int b, int x){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x1,y,z;
    int *arr,*arr1;
    int min=INT_MAX;
    int flag=0;
    int count=0;
    int count1=0;
    int count2=0;
    int count3=0;
    int count4=0;
   int count5=0;
    
    arr=(int *)malloc(sizeof(int)*(x+1));
    arr1=(int *)malloc(sizeof(int)*(x+1));
    for(i=0;i<=x;i++){
        arr[i]=0;
        arr1[i]=0;
    }
    for(i=0;i<forbiddenSize;i++){
        arr[forbidden[i]]=1;
    }
    for(i=0;i<=x;i++){
        if(i==x){
            flag=1;
            break;
        }
        if(i+a<=x&&arr[i+a]==0){
            arr[i+a]=1;
            count++;
        }
        if(i-b>=0&&arr[i-b]==0){
            arr[i-b]=1;
            count1++;
        }
    }
    for(i=0;i<=x;i++){
        if(i==x){
            flag=1;
            break;
        }
        if(i+a<=x&&arr1[i+a]==0){
            arr1[i+a]=1;
            count2++;
        }
        if(i-b>=0&&arr1[i-b]==0){
            arr1[i-b]=1;
        }
    }
    for(i=0;i<=x;i++){
        if(i==x){
            flag=1;
            break;
        }
        if(i+a<=x&&arr[i+a]==0){
            arr[i+a]=1;
            count3++;
        }
        if(i-b>=0&&arr[i-b]==0){
            arr[i-b]=1;
       }
    }

        for(i=0;i<=x;i++){
        if(i==x){
            flag=1;
            break;
        }
        if(i+a<=x&&arr1[i+a]==0){
            arr1[i+a]=1;
        }
        if(i-b>=0&&arr1[i-b]==0){
            arr1[i-b]=1;
            count5++;
        }
        }
    if(flag==1){
        min=count+1;
    }
    for(i=0;i<=x;i++){
        if(i==x){
            flag=1;
            break;
        }
        if(i+a<=x&&arr[i+a]==0){
            arr[i+a]=1;
            count4++;
        }
        if(i-b>=0&&arr[i-b]==0){
            arr[i-b]=1;
       }
    }
    if(flag==1){
        min=min<count4+1?min:count4+1;
    }
    for(i=0;i<=x;i++){
        if(i==x){
            flag=1;
            break;
        }
        if(i+a<=x&&arr1[i+a]==0){
            arr1[i+a]=1;
            count++;
        }
        if(i-b>=0&&arr1[i-b]==0){
            arr1[i-b]=1;

        }
    }
    if(flag==1){
        min=min<count2+1?min:count2+1;
    }
    for(i=0;i<=x;i++){
        if(i==x){
            flag=1;
            break;
        }
        if(i+a<=x&&arr[i+a]==0){
            arr[i+a]=1;
            count++;
        }
        if(i-b>=0&&arr[i-b]==0){
            arr[i-b]=1;
      }
    }
    if(flag==1){
        min=min<count3+1?min:count3+1;
    }
    for(i=0;i<=x;i++){
        if(i==x){
            flag=1;
            break;
        }
        if(i+a<=x&&arr1[i+a]==0){
            arr1[i+a]=1;
        }
        if(i-b>=0&&arr1[i-b]==0){
            arr1[i-b]=1;
            count5++;
        }
    }
    if(flag==1){
        min=min<count5+1?min:count5+1;
    }
    return min==INT_MAX?-1:min;
}