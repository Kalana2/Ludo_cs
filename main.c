#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#include "types.c"
#include "logic.c"



int main(){
    srand(time(NULL));

    logic();

    return 0;
}

