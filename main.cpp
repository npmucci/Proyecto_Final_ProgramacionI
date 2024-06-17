#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include "menu.h"
#include "jugar.h"



int main()
{
    rlutil::hidecursor();
    srand(time(0)); // SEMILLA PARA EL RANDOM
    desplegarMenu();


    return 0;
}
