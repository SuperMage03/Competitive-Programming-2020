//
// Created by liyue on 2020-11-22.
//

#include "BUS.h"

BUS::BUS() {
    //Clears the ram
    for (uint8_t &data : ram) {data = 0x00;}
    //Connects the CPU to the BUS
    cpu.ConnectBus(this);
}

BUS::~BUS() {}

uint8_t BUS::read(uint16_t address) {
    //Make sure the address is in range
    if (address >= 0x0000 && address <= 0xFFFF) {
        return ram[address];
    }
    return 0x00; //If not in range return 0
}

void BUS::write(uint16_t address, uint8_t data) {
    //Make sure the address is in range
    if (address >= 0x0000 && address <= 0xFFFF) {
        ram[address] = data;
    }
}