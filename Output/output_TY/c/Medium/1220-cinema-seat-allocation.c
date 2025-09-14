/**https://leetcode.com/problems/cinema-seat-allocation/ */
//A cinema has n rows of seats, numbered from 1 to n and there are ten seats in each row, labelled from 1 to 10 as shown in the figure above.
//Given the array reservedSeats containing the numbers of seats already reserved, for example, reservedSeats[i] = [3,8] means the seat located in row 3 and labelled with 8 is already reserved.
//Return the maximum number of four-person groups you can assign on the cinema seats. A four-person group occupies four adjacent seats in one single row. Seats across an aisle (such as [3,3] and [3,4]) are not considered to be adjacent, but there is an exceptional case on which an aisle split a four-person group, in that case, the aisle split a four-person group in the middle, which means to have two people on each side.
// 
//Example 1:
//Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
//Output: 4
//Explanation: The figure above shows the optimal allocation for four groups, where seats mark with blue are already reserved and contiguous seats mark with orange are for one group.
//Example 2:
//Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
//Output: 2
//Example 3:
//Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
//Output: 4
// 
//Constraints:
//	1 <= n <= 10^9
//	1 <= reservedSeats.length <= min(10*n, 10^4)
//	reservedSeats[i].length == 2
//	1 <= reservedSeats[i][0] <= n
//	1 <= reservedSeats[i][1] <= 10
//	All reservedSeats[i] are distinct.
int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize){
    int i, j, k, l, m, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16, n17, n18, n19, n20, n21, n22, n23, n24, n25, n26, n27, n28, n29, n30, n31,n32, n33, n34, n35, n36, n    = 0;
    for (i = 1; i <= n; i++) {
        n1 = n2 = n3 = n4 = 0;
        for (j = 0; j < reservedSeatsSize; j++) {
            if (reservedSeats[j][0] == i) {
                if (reservedSeats[j][1] >= 2 && reservedSeats[j][1] <= 5) {
                    n1 =1;
                    if (reservedSeats[j][1] >= 4 && reservedSeats[j][1] <= 7) {
                        n2 =1;
                    }
                }
            }
        }
    }
    for (i = 1; i <= n; i++) {
        n3 = n4 = n5 = n6 = 0;
        for (j = 0; j < reservedSeatsSize; j++) {
            if (reservedSeats[j][0] == i) {
                if (reservedSeats[j][1] >= 6 && reservedSeats[j][1] <= 9) {
                    n3 =1;
                    if (reservedSeats[j][1] >= 7 && reservedSeats[j][1] <= 10) {
                        n4 =1;
}
                }
            }
        }
    }
    for (i = 1; i <= n; i++) {
        n7 = n8 = n9 = n10 = 0;
        for (j = 0; j < reservedSeatsSize; j++) {
            if (reservedSeats[j][0] == i) {
                if (reservedSeats[j][1] >= 4 && reservedSeats[j][1] <= 7) {
                    n7 =1;
                }
            }
        }
    }
    for (i = 1; i <= n; i++) {
        n11 = n12 = n13 = n14 = 0;
        for (j = 0; j < reservedSeatsSize; j++) {
            if (reservedSeats[j][0] == i) {
                if (reservedSeats[j][1] >= 8 && reservedSeats[j][1] <= 11) {
                    n11 =1;
                }
            }
        }
    }
    for (i = 1; i <= n; i++) {
        n15 = n16 = n17 = n18 = 0;
        for (j = 0; j < reservedSeatsSize; j++) {
            if (reservedSeats[j][0] == i) {
                if (reservedSeats[j][1] >= 3 && reservedSeats[j][1] <= 6) {
                    n15 =1;
                }
            }
        }
    }
    for (i = 1; i <= n; i++) {
        n19 = n20 = n21 = n22 = 0;
        for (j = 0; j < reservedSeatsSize; j++) {
            if (reservedSeats[j][0] == i) {
                if (reservedSeats[j][1] >= 9 && reservedSeats[j][1] <= 12) {
                    n19 =1;
                    if (reservedSeats[j][1] >= 10 && reservedSeats[j][1] <= 13) {
                        n20 =1;
                    }
                }
            }
        }
    }   
    for (i = 1; i <= n; i++) {
        n23 = n24 = n25 = n26 = 0;
        for (j = 0; j < reservedSeatsSize; j++) {
            if (reservedSeats[j][0] == i) {
                if (reservedSeats[j][1] >= 2 && reservedSeats[j][1] <= 5) {
                    n23 =1;
                }
            }
        }
    }
    for (i = 1; i <= n; i++) {
        n27 = n28 = n29 = n30 = 0;
        for (j = 0; j < reservedSeatsSize; j++) {
            if (reservedSeats[j][0] == i) {
                if (reservedSeats[j][1] >= 7 && reservedSeats[j][1] <= 10) {
                    n27 =1;
                }
            }
        }
    }
    for (i = 1; i <= n; i++) {
        n31 = n32 = n33 = n34 = 0;
        for (j = 0; j < reservedSeatsSize; j++) {
            if (reservedSeats[j][0] == i) {
                if (reservedSeats[j][1] >= 4 && reservedSeats[j][1] <= 7) {
                    n31 =1;
                }
            }
        }
    }
    for (i = 1; i <= n; i++) {
        n35 = n36 = n37 = n38 = 0;
        for (j = 0; j < reservedSeatsSize; j++) {
            if (reservedSeats[j][0] == i) {
                if (reservedSeats[j][1] >= 8 && reservedSeats[j][1] <= 11) {
                    n35 =1;
                }
            }
        }
    }
    n = n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9 + n10 + n11 + n12 + n13 + n14 + n15 + n16 + n17 + n18 + n19 + n20 + n21 + n22 + n23 + n24 + n25 + n26 + n27 + n28 + n29 + n30 + n31 + n32 + n33 + n34 +n35 + n36;
    return n;
}