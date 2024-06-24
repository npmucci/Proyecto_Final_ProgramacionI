#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include "menu.h"
#include "jugar.h"
#include "dibujos.h"



int main()
{
     rlutil::setBackgroundColor(rlutil::YELLOW);
      rlutil::setColor(rlutil::BLACK);
    srand(time(0)); // SEMILLA PARA EL RANDOM
    desplegarMenu();


    return 0;
}
