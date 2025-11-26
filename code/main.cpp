#include <iostream>
#include "include/screenFunctions.h"
using namespace std;


int main() {
    enableRawMode();   // enable raw input

    /*
        Add Our Code Here
    */

    disableRawMode();  // restore terminal mode
    clearScreen();

    return 0;
}