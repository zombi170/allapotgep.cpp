/**
*    @file split.hpp 
*    Be kell adni!
*    Ide kerül a Split osztály deklarációja
*/

#ifndef SPLIT_HPP
#define SPLIT_HPP

#include <string>
#include "memtrace.h"
#include "allapotgep.hpp"

enum class Sall { alap, atmenet};
enum class Sin { v, mas};

class Split :public Allapotgep<Sall, Sin, char>{
    Allapotgep::AllTabla tab;
    std::vector<std::string> tomb;
    int sz = 0;
    char valaszt;

    struct Ir : public Nop {
        Split& allapotgep;
        Ir(Sall all, Split& allapotgep) : Nop(all), allapotgep(allapotgep) {}
        void akcio(char ch) {
            if (allapotgep.tomb.empty()){
                std::string temp;
                temp.push_back(ch);
                allapotgep.tomb.push_back(temp);
            }
            else
                allapotgep.tomb[allapotgep.sz].push_back(ch); }
    };
    struct Uj : public Nop {
        Split& allapotgep;
        Uj(Sall all, Split& allapotgep) : Nop(all), allapotgep(allapotgep) {}
        void akcio(char ch) { std::string temp; allapotgep.sz++; temp.push_back(ch); allapotgep.tomb.push_back(temp);}
    };
public:
    Split(char ch);
    Sin input(char ch) const override{
        if (ch == valaszt) return Sin::v;
        return Sin::mas;
    }
    std::vector<std::string> get() const {
        return tomb;
    }
};

#endif