#include <stdio.h>
#include <stdlib.h>

long long next_bigger_number(long long n) {
    if (n < 0) {
        return -1; // Return -1 for negative numbers
    }

    // Count the number of digits
    long long o = n;
    long long length = 0;
    while (o != 0) {
        o = o / 10;
        length++;
    }

    // Extract digits into an array
    long long *num = (long long*) malloc(length * sizeof(long long));
    if (num == NULL) {
        return -1; // Memory allocation failed
    }

    o = n;
    for (long long i = length - 1; i >= 0; i--) {
        num[i] = o % 10;
        o = o / 10;
    }

    // Find the pivot
    long long s;
    for (s = length - 2; s >= 0; s--) {
        if (num[s] < num[s + 1]) {
            break;
        }
    }

    if (s < 0) {
        free(num);
        return -1; // No bigger number possible
    }

    // Find the smallest digit on right side of pivot which is larger than num[s]
    long long t = s + 1;
    for (long long k = s + 1; k < length; k++) {
        if (num[k] > num[s] && num[k] <= num[t]) {
            t = k;
        }
    }

    // Swap the pivot and the smallest larger digit found
    long long tmp = num[s];
    num[s] = num[t];
    num[t] = tmp;

    // Sort the digits after the pivot in ascending order
    for (long long k = s + 1; k < length - 1; k++) {
        for (long long l = k + 1; l < length; l++) {
            if (num[k] > num[l]) {
                tmp = num[k];
                num[k] = num[l];
                num[l] = tmp;
            }
        }
    }

    // Convert the array back to a number
    long long result = 0;
    for (long long i = 0; i < length; i++) {
        result = result * 10 + num[i];
    }

    // Free the allocated memory
    free(num);

    return result;
}