#include <stdio.h>
#include <stdlib.h>

// Function to find the next bigger number
long long next_bigger_number(long long *n) {
    long long num[100], i, j, s, t, k, l, tmp;
    long long o = *n; // original number

    // Separate the number into digits
    for (i = j = 100; o > 0;) {
        num[--i] = o % 10;
        o = o / 10;
    }

    // Find the first digit smaller than the next one to the right
    for (s = j - 2; s >= i; s--) {
        if (num[s] < num[s + 1]) {
            break;
        }
    }

    if (s < i) {
        // No bigger number with the same digits
        return -1;
    }

    // Find the smallest digit to the right of 's' that is larger than 's'
    t = s + 1;
    for (k = t + 1; k < j; k++) {
        if (num[k] < num[t] && num[k] > num[s]) {
            t = k;
        }
    }

    // Swap the two found digits
    tmp = num[t];
    num[t] = num[s];
    num[s] = tmp;

    // Sort the digits from position (s + 1) onwards in ascending order
    for (k = s + 1; k < j - 1; k++) {
        for (l = k + 1; l < j; l++) {
            if (num[k] > num[l]) {
                tmp = num[k];
                num[k] = num[l];
                num[l] = tmp;
            }
        }
    }

    // Construct the resulting number from the sorted digits
    long long juris = 0;
    for (k = i; k < j; k++) {
        juris = juris * 10 + num[k];
    }

    return juris;
}

int main() {
    long long *n = (long long*) malloc(sizeof(long long));
    printf("type a number that you want to check for next biggest number: ");
    if (scanf("%lld", n) != 1 || *n < 0) {
        return 1;
    }

    // Find the next bigger number and print the result
    long long result = next_bigger_number(n);
    if (result == -1) {
        printf("-1\n");
    } else {
        printf("next biggest number: %lld\n", result);
    }

    return 0;
}