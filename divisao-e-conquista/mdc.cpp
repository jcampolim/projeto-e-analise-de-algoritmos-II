// Júlia Campolim de Oste - 10408802

#include <stdio.h>

int mdc(int x, int y) {
    if(x == y) {
        return x;
    } 

    if(x % 2 == 0) {
        if(y % 2 == 0) {
            return 2 * mdc(x/2, y/2);
        } else {
            return mdc(x/2, y);
        }
    } else {
        if(y % 2 == 0) {
            return mdc(x, y/2);
        } else if(x > y) {
            return mdc((x-y)/2, y);
        } else {
            return mdc(x, (y-x)/2);
        }
    }
}

int main() {
    printf("mdc(270,192) = %d\n", mdc(270, 192));
    printf("mdc(35,10) = %d\n", mdc(35, 10));
    printf("mdc(10,15) = %d\n", mdc(10, 15));
    printf("mdc(31,2) = %d\n", mdc(31, 2));

    return 0;
}