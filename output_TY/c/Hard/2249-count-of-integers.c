/**https://leetcode.com/problems/count-of-integers/ */
//You are given two numeric strings num1 and num2 and two integers max_sum and min_sum. We denote an integer x to be good if:
//	num1 <= x <= num2
//	min_sum <= digit_sum(x) <= max_sum.
//Return the number of good integers. Since the answer may be large, return it modulo 109 + 7.
//Note that digit_sum(x) denotes the sum of the digits of x.
// 
//Example 1:
//Input: num1 = "1", num2 = "12", min_sum = 1, max_sum = 8
//Output: 11
//Explanation: There are 11 integers whose sum of digits lies between 1 and 8 are 1,2,3,4,5,6,7,8,10,11, and 12. Thus, we return 11.
//Example 2:
//Input: num1 = "1", num2 = "5", min_sum = 1, max_sum = 5
//Output: 5
//Explanation: The 5 integers whose sum of digits lies between 1 and 5 are 1,2,3,4, and 5. Thus, we return 5.
// 
//Constraints:
//	1 <= num1 <= num2 <= 1022
//	1 <= min_sum <= max_sum <= 400
int count(char * num1, char * num2, int min_sum, int max_sum){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a, b, c, d, e, f, g, h, ii, jj, kk, ll, mm, nn, oo, pp, qq, rr, ss, tt, uu, vv, ww, xx, yy, zz, aa, bb, cc, dd, ee, ff, gg, hh    ;
    int sum, count;
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            for (k = 0; k < 10; k++){
                for (l = 0; l < 10; l++){
                    for (m = 0; m < 10; m++){
                        for (n = 0; n < 10; n++){
                           for (o = 0; o < 10; o++){
                            for (p = 0; p < 10; p++){
                                for (q = 0; q < 10; q++){
                                    for (r = 0; r < 10; r++){
                                        for (s = 0; s < 10; s++){
                                            for (t = 0; t < 10; t++){
                                                for (u = 0; u < 10; u++){
                                                    for (v =0; v < 10; v++){
                                                        for (w = 0; w < 10; w++){
                                                            for (x = 0; x < 10; x++){
                                                                for (y = 0; y < 10; y++){
                                                                    for (z = 0; z < 10; z++){
                                                                        for (a = 0; a < 10; a++){
                                                                            for (b = 0; b < 10; b++){
                                                                                for (c = 0; c < 10; c++){
                                                                                    for (d = 0; d < 10; d++){
                                                                                        for (e = 0; e < 10; e++){
                                                                                            for (f = 0; f < 10; f++){
                                                                                                for (g = 0; g < 10; g++){
                                                                                                    for (h = 0;h < 10; h++){
                                                                                                        for (ii = 0; ii < 10; ii++){
                                                                                                            for (jj = 0; jj < 10; jj++){
                                                                                                                for (kk = 0; kk < 10; kk++){
                                                                                                                    for (ll = 0; ll < 10; ll++){
                                                                                                                        for (mm = 0; mm < 10; mm++){
                                                                                                                            for (nn = 0; nn < 10; nn++){

                                                                                                                                    if (i + j + k + l + m + n + o + p + q + r + s + t + u + v + w + x + y + z + a + b + c + d + e + f + g + h + ii + jj + kk + ll + mm + nn + oo + pp + qq + rr + ss + tt + uu + vv + ww + xx + yy + zz + aa +bb + cc + dd + ee + ff + gg + h) <= max_sum && i + j + k + l + m + n + o + p + q + r + s + t + u + v + w + x + y + z + a + b + c + d + e + f + g + h + ii + jj + kk + ll + mm + nn + oo + pp + qq + rr + ss + tt + uu + vv + ww + xx + yy + zz + aa +bb + cc + dd + ee + ff +
                                                                                                                                    gg + hh <= min_sum){
                                                                                                                                        sum = i + j + k + l + m + n + o + p + q + r + s + t + u + v + w + x + y + z + a + b + c + d + e + f + g + h + ii + jj + kk + ll + mm + nn + oo + pp + qq + rr + ss + tt + uu + vv + ww + xx + yy + zz + aa +bb + cc + dd + ee + ff + gg + hh    ;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
}
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                           }
                        }
                    }
                }
            }
        }
    }
    return sum;
}