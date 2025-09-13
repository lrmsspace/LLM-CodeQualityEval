/**https://leetcode.com/problems/maximize-distance-to-closest-person/ */
//You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).
//There is at least one empty seat, and at least one person sitting.
//Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 
//Return that maximum distance to the closest person.
// 
//Example 1:
//Input: seats = [1,0,0,0,1,0,1]
//Output: 2
//Explanation: 
//If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
//If Alex sits in any other open seat, the closest person has distance 1.
//Thus, the maximum distance to the closest person is 2.
//Example 2:
//Input: seats = [1,0,0,0]
//Output: 3
//Explanation: 
//If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
//This is the maximum distance possible, so the answer is 3.
//Example 3:
//Input: seats = [0,1]
//Output: 1
// 
//Constraints:
//	2 <= seats.length <= 2 * 104
//	seats[i] is 0 or 1.
//	At least one seat is empty.
//	At least one seat is occupied.
int maxDistToClosest(int* seats, int seatsSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z;
    a=0;
    for(i=0;i<seatsSize;i++){
        if(seats[i]==1){
            a++;
        }
    }
    if(a==1){
        return 1;
    }
    b=0;
    for(i=0;i<seatsSize;i++){
        if(seats[i]==1){
            b++;
        }
    }   
    if(b==2){
        return 1;
    }
    for(i=0;i<seatsSize;i++){
        if(seats[i]==1){
            if(i==0){
                return (seatsSize-1)/2;
            }
        }
    }
    for(i=seatsSize-1;i>=0;i--){
        if(seats[i]==1){
            if(i==seatsSize-1){
                return (seatsSize-1)/2;
            }
        }
    }
    return max(a,b);
}