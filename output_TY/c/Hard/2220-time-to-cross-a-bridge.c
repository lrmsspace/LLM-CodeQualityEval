/**https://leetcode.com/problems/time-to-cross-a-bridge/ */
//There are k workers who want to move n boxes from an old warehouse to a new one. You are given the two integers n and k, and a 2D integer array time of size k x 4 where time[i] = [leftToRighti, pickOldi, rightToLefti, putNewi].
//The warehouses are separated by a river and connected by a bridge. The old warehouse is on the right bank of the river, and the new warehouse is on the left bank of the river. Initially, all k workers are waiting on the left side of the bridge. To move the boxes, the ith worker (0-indexed) can :
//	Cross the bridge from the left bank (new warehouse) to the right bank (old warehouse) in leftToRighti minutes.
//	Pick a box from the old warehouse and return to the bridge in pickOldi minutes. Different workers can pick up their boxes simultaneously.
//	Cross the bridge from the right bank (old warehouse) to the left bank (new warehouse) in rightToLefti minutes.
//	Put the box in the new warehouse and return to the bridge in putNewi minutes. Different workers can put their boxes simultaneously.
//A worker i is less efficient than a worker j if either condition is met:
//	leftToRighti + rightToLefti > leftToRightj + rightToLeftj
//	leftToRighti + rightToLefti == leftToRightj + rightToLeftj and i > j
//The following rules regulate the movement of the workers through the bridge :
//	If a worker x reaches the bridge while another worker y is crossing the bridge, x waits at their side of the bridge.
//	If the bridge is free, the worker waiting on the right side of the bridge gets to cross the bridge. If more than one worker is waiting on the right side, the one with the lowest efficiency crosses first.
//	If the bridge is free and no worker is waiting on the right side, and at least one box remains at the old warehouse, the worker on the left side of the river gets to cross the bridge. If more than one worker is waiting on the left side, the one with the lowest efficiency crosses first.
//Return the instance of time at which the last worker reaches the left bank of the river after all n boxes have been put in the new warehouse.
// 
//Example 1:
//Input: n = 1, k = 3, time = [[1,1,2,1],[1,1,3,1],[1,1,4,1]]
//Output: 6
//Explanation: 
//From 0 to 1: worker 2 crosses the bridge from the left bank to the right bank.
//From 1 to 2: worker 2 picks up a box from the old warehouse.
//From 2 to 6: worker 2 crosses the bridge from the right bank to the left bank.
//From 6 to 7: worker 2 puts a box at the new warehouse.
//The whole process ends after 7 minutes. We return 6 because the problem asks for the instance of time at which the last worker reaches the left bank.
//Example 2:
//Input: n = 3, k = 2, time = [[1,9,1,8],[10,10,10,10]]
//Output: 50
//Explanation: 
//From 0  to 10: worker 1 crosses the bridge from the left bank to the right bank.
//From 10 to 20: worker 1 picks up a box from the old warehouse.
//From 10 to 11: worker 0 crosses the bridge from the left bank to the right bank.
//From 11 to 20: worker 0 picks up a box from the old warehouse.
//From 20 to 30: worker 1 crosses the bridge from the right bank to the left bank.
//From 30 to 40: worker 1 puts a box at the new warehouse.
//From 30 to 31: worker 0 crosses the bridge from the right bank to the left bank.
//From 31 to 39: worker 0 puts a box at the new warehouse.
//From 39 to 40: worker 0 crosses the bridge from the left bank to the right bank.
//From 40 to 49: worker 0 picks up a box from the old warehouse.
//From 49 to 50: worker 0 crosses the bridge from the right bank to the left bank.
//From 50 to 58: worker 0 puts a box at the new warehouse.
//The whole process ends after 58 minutes. We return 50 because the problem asks for the instance of time at which the last worker reaches the left bank.
// 
//Constraints:
//	1 <= n, k <= 104
//	time.length == k
//	time[i].length == 4
//	1 <= leftToRighti, pickOldi, rightToLefti, putNewi <= 1000
int findCrossingTime(int n, int k, int** time, int timeSize, int* timeColSize){
    int i, j, t, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16, n17, n18, n19, n20, n21, n22, n23, n24, n25, n26, n27, n28, n29, n30, n31, n32, n33, n34, n35, n36, n37, n38    , n39, n40, n41, n42, n43, n44, n45, n46, n47, n48, n49, n50, n51, n52, n53, n54, n55, n56, n57, n58, n59, n60, n61, n62, n63, n64, n65, n66, n67, n68, n69, n70, n71, n72, n73, n74, n75, n76, n77, n78    , n79, n80, n81, n82, n83, n84, n85, n86, n87, n88, n89, n90, n91, n92, n93, n94, n95, n96, n97, n98, n99, n100;
    n1 = n;
    n2 = k;
    n3 = timeSize;
    n4 = timeColSize[0];    
    
}