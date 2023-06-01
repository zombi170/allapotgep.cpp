/**
*    @file komment.hpp 
*    Be kell adni!
*    Ide kerül a Komment osztály deklarációja
*/

#ifndef KOMMENT_HPP
#define KOMMENT_HPP

#include <string>  //használandó az std::string
#include "memtrace.h"
#include "allapotgep.hpp"

enum class Kall { ir, perjel, csillag, nem_ir};
enum class Kin { per, cs, mas };

class Komment :public Allapotgep<Kall, Kin, char>{
    Allapotgep::AllTabla tab;
    std::string str;

    struct Ir : public Nop {
        Komment& allapotgep;
        Ir(Kall all, Komment& allapotgep) : Nop(all), allapotgep(allapotgep) {}
        void akcio(char ch) { allapotgep.str.push_back(ch); }
    };
    struct Megsem : public Nop {
        Komment& allapotgep;
        Megsem(Kall all, Komment& allapotgep) : Nop(all), allapotgep(allapotgep) {}
        void akcio(char ch) { allapotgep.str.pop_back(); }
    };
public:
    Komment();
    Kin input(char ch) const override{
        if (ch == '/') return Kin::per;
        if (ch == '*') return Kin::cs;
        return Kin::mas;
    }
    std::string get() const {
        return str;
    }
};

#endif