#include <stdio.h>
#include <stdlib.h>
/*here witdth is number smaller than 0*/
long long next_bigger_number(long long n) {
    if (n < 0) {
        return -1; 
    }
/*here i create an dinamic array on malloc function*/
    long long *num = (long long*) malloc(100 * sizeof(long long));
    long long i, j, s, t, k, l, tmp;
    long long o = n; 
/*here i create function to separate last digit traverse the given from rightmost digit keep traversing till you find a digit wich is smaller than previous traversed digits*/
    for (i = j = 100; o > 0;) {
        num[--i] = o % 10;
        o = o / 10;
    }
/*here i search the right side of above found digit 'd' for the smallest digit greater than 'd'*/
    for (s = j - 2; s >= i; s--) {
        if (num[s] < num[s + 1]) {
            break;
        }
    }
/* no greater number with the same digits */
    if (s < i) {
        return -1;
    }
/*here i use break to stop infinite function*/
    t = s + 1;
    for (k = t + 1; k < j; k++) {
        if (num[k] < num[t] && num[k] > num[s]) {
            t = k;
        }
    }
/* here i create function to swap the above found two digits digits yeah all text from 33-42 is only one function*/
    tmp = num[t];
    num[t] = num[s];
    num[s] = tmp;
    for (k = s + 1; k < j - 1; k++) {
        for (l = k + 1; l < j; l++) {
            if (num[k] > num[l]) {
                tmp = num[k];
                num[k] = num[l];
                num[l] = tmp;
            }
        }
    }
/*recording numbers in variable*/
    long long juris = 0;
    for (k = i; k < j; k++) {
        juris = juris * 10 + num[k];
    }
/*here we return number*/
    return juris;
}