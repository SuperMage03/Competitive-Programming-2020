//
// Created by liyue on 2020-11-22.
//

#ifndef NESEMULATOR_MOS6502_H
#define NESEMULATOR_MOS6502_H

#include <string>
#include <cstdint>
#include <vector>

class BUS;
class MOS6502 {
public:
    MOS6502();
    ~MOS6502();
    void ConnectBus(BUS *n) {bus = n;}

    //Registers, Parts of the memory
    uint16_t PC = 0x0000, SP = 0x0000; //Program Counter, Stack Pointer
    uint8_t A = 0x00, X = 0x00, Y = 0x00; //Accumulator, Index Register X, Index Register Y
    //Processor Status
    uint8_t PS;
    enum PSFlags {
        CF = 1 << 0, //Carry Flag
        ZF = 1 << 1, //Zero Flag
        ID = 1 << 2, //Interrupt Disable
        DM = 1 << 3, //Decimal Mode
        BC = 1 << 4, //Break Command
        PH = 1 << 5, //Place Holder, not used
        OF = 1 << 6, //Overflow Flag
        NF = 1 << 7, //Negative Flag
    };

    //Startup register setting
    void clock(); //Run one clock cycle
    //Interrupt Signals
    void RST(); //Reset Signal
    void IRQ(); //Interrupt Request Signal, can be ignored depending on Interrupt Disable Flag
    void NMI(); //Non-maskable Interrupt Request Signal, can't be ignored

    uint8_t fetch();
    uint8_t fetched = 0x00;

    uint16_t address_ABS = 0x0000;
    uint16_t address_REL = 0x0000;
    uint8_t curOP = 0x00;
    uint8_t cycleLeft = 0x00;

private:
    BUS *bus = nullptr;
    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t data);
    uint8_t GetFlag(PSFlags f);
    void SetFlag(PSFlags f, bool v);

    //Addressing Modes
    uint8_t IMP(); //Implicit
    uint8_t IMM(); //Immediate
    uint8_t ZPG(); //Zero Page
    uint8_t ZPX(); //Zero Page, X
    uint8_t ZPY(); //Zero Page, Y
    uint8_t REL(); //Relative
    uint8_t ABS(); //Zero Page
    uint8_t ABX(); //Zero Page, X
    uint8_t ABY(); //Zero Page, Y
    uint8_t IND(); //Indirect
    uint8_t IZX();
    uint8_t IZY();

    //Opcodes
    uint8_t ADC();	uint8_t AND();	uint8_t ASL();	uint8_t BCC();
    uint8_t BCS();	uint8_t BEQ();	uint8_t BIT();	uint8_t BMI();
    uint8_t BNE();	uint8_t BPL();	uint8_t BRK();	uint8_t BVC();
    uint8_t BVS();	uint8_t CLC();	uint8_t CLD();	uint8_t CLI();
    uint8_t CLV();	uint8_t CMP();	uint8_t CPX();	uint8_t CPY();
    uint8_t DEC();	uint8_t DEX();	uint8_t DEY();	uint8_t EOR();
    uint8_t INC();	uint8_t INX();	uint8_t INY();	uint8_t JMP();
    uint8_t JSR();	uint8_t LDA();	uint8_t LDX();	uint8_t LDY();
    uint8_t LSR();	uint8_t NOP();	uint8_t ORA();	uint8_t PHA();
    uint8_t PHP();	uint8_t PLA();	uint8_t PLP();	uint8_t ROL();
    uint8_t ROR();	uint8_t RTI();	uint8_t RTS();	uint8_t SBC();
    uint8_t SEC();	uint8_t SED();	uint8_t SEI();	uint8_t STA();
    uint8_t STX();	uint8_t STY();	uint8_t TAX();	uint8_t TAY();
    uint8_t TSX();	uint8_t TXA();	uint8_t TXS();	uint8_t TYA();

    uint8_t XXX(); //Illegal Opcodes, just burn cycles

    struct DICTIONARY {
        std::string OPName;
        uint8_t(MOS6502::*OM)(void) = nullptr;
        uint8_t(MOS6502::*AM)(void) = nullptr;
        uint8_t cycles = 0x00;
    };
    std::vector<DICTIONARY> reference;
};


#endif //NESEMULATOR_MOS6502_H
