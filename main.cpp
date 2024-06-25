#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include "menu.h"
#include "jugar.h"
#include "dibujos.h"



int main()
{

    rlutil::setColor(rlutil::WHITE);
    srand(time(0)); // SEMILLA PARA EL RANDOM
    desplegarMenu();


    return 0;
}
