#include <stdio.h>

extern void sv_display();

int c_display() {
    printf("C:  in c_display\n");
    sv_display();
}