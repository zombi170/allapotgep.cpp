/**
*    @file komment.cpp 
*    Be kell adni!
*    Ide kerül a Komment osztály megvalósított függvényei
*/

#include <string>
#include "memtrace.h"
#include "komment.hpp"

Komment::Komment() :Allapotgep(Kall::ir, tab) {
    tab[Kall::ir] =       {{Kin::per, new Ir(Kall::perjel, *this)},
                           {Kin::cs, new Ir(Kall::ir, *this)},
                           {Kin::mas, new Ir(Kall::ir, *this)}};
    tab[Kall::perjel] =   {{Kin::per, new Ir(Kall::perjel, *this)},
                           {Kin::cs, new Megsem(Kall::nem_ir, *this)},
                           {Kin::mas, new Ir(Kall::ir, *this)}};
    tab[Kall::nem_ir] =   {{Kin::per, new Nop(Kall::nem_ir)},
                           {Kin::cs, new Nop(Kall::csillag)},
                           {Kin::mas, new Nop(Kall::nem_ir)}};
    tab[Kall::csillag] =  {{Kin::per, new Nop(Kall::ir)},
                           {Kin::cs, new Nop(Kall::csillag)},
                           {Kin::mas, new Nop(Kall::nem_ir)}};
}