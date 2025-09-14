/**https://leetcode.com/problems/minimum-number-of-refueling-stops/ */
//A car travels from a starting position to a destination which is target miles east of the starting position.
//There are gas stations along the way. The gas stations are represented as an array stations where stations[i] = [positioni, fueli] indicates that the ith gas station is positioni miles east of the starting position and has fueli liters of gas.
//The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it. It uses one liter of gas per one mile that it drives. When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.
//Return the minimum number of refueling stops the car must make in order to reach its destination. If it cannot reach the destination, return -1.
//Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there. If the car reaches the destination with 0 fuel left, it is still considered to have arrived.
// 
//Example 1:
//Input: target = 1, startFuel = 1, stations = []
//Output: 0
//Explanation: We can reach the target without refueling.
//Example 2:
//Input: target = 100, startFuel = 1, stations = [[10,100]]
//Output: -1
//Explanation: We can not reach the target (or even the first gas station).
//Example 3:
//Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
//Output: 2
//Explanation: We start with 10 liters of fuel.
//We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.
//Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
//and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.
//We made 2 refueling stops along the way, so we return 2.
// 
//Constraints:
//	1 <= target, startFuel <= 109
//	0 <= stations.length <= 500
//	1 <= positioni < positioni+1 < target
//	1 <= fueli < 109
int minRefuelStops(int target, int startFuel, int** stations, int stationsSize, int* stationsColSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[10001], b[10001], c[10001], d[10001], e[10001], f[10001], g[10001], h[10001], i1, j1, k1, l1, m1, n1, o1, p1, q1, r1, s1, t1, u1, v1, w1, x1, y1, z1;
    for (i = 0; i < 10001; i++) {
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
        d[i] = 0;
        e[i] = 0;
        f[i] = 0;
        g[i] = 0;
        h[i] = 0;
    }
    a[0] = startFuel;
    for (i = 0; i < stationsSize; i++) {
        for (j = 0; j <= i; j++) {
            if (a[j] >= stations[i][0]) {
                a[j + 1] = a[j] + stations[i][1];
            }
        }
    }
    for (i = 0; i < 10001; i++) {
        if (a[i] >= target) {
            return i;
        }
    }
    return -1;
}