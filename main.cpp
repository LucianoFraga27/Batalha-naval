#include<iostream>
#include<string>
#include<stdlib.h>
#include<new>
#include<time.h>
#include<locale.h>


using namespace std;

#include "functions.h"

int main (void) {

    srand ( (unsigned)time(NULL) );

    setlocale(LC_ALL,"");

    menuInicial();

    return 0;
}
