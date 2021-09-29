//
// Created by liyue on 2020-11-22.
//

#ifndef NESEMULATOR_BUS_H
#define NESEMULATOR_BUS_H

#include <cstdint>
#include <array>
#include "MOS6502.h"

using namespace std;

class BUS {
public:
    BUS();
    ~BUS();
    //Devices
    MOS6502 cpu; //6502 CPU
    array<uint8_t, 64 * 1024> ram; //64kb RAM in the stack
    //Read & Write
    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t data);
};


#endif //NESEMULATOR_BUS_H
