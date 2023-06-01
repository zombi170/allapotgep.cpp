/**
*    @file split.cpp 
*    Be kell adni!
*    Ide kerül a Split osztály megvalósítása
*/

#include "split.hpp"
#include "memtrace.h"

Split::Split(char ch) :Allapotgep(Sall::alap, tab), valaszt(ch) {
    tab[Sall::alap] =     {{Sin::v, new Nop(Sall::atmenet)},
                           {Sin::mas, new Ir(Sall::alap, *this)}};
    tab[Sall::atmenet] =  {{Sin::v, new Nop(Sall::atmenet)},
                           {Sin::mas, new Uj(Sall::alap, *this)}};
}