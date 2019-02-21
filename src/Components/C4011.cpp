/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4011: 4 nand gates
*/

#include "C4011.hpp"

C4011::C4011(std::string const &name) : Component(name, "4011") {}

C4011::~C4011() {}

nts::Tristate C4011::compute(std::size_t pin) {
    // std::cout << "Compute at " << this->getName() << std::endl;
    std::size_t otherPin;
    std::size_t it;
    nts::Tristate int1;
    nts::Tristate int2;

    if (pin == 3) {
        it = this->findIndex(1);
        otherPin = this->_otherPin[it];
        int1 = this->_cmpt[it]->compute(otherPin);
        it = this->findIndex(2);
        otherPin = this->_otherPin[it];
        int2 = this->_cmpt[it]->compute(otherPin);
    }
    if (pin == 4) {
        it = this->findIndex(5);
        otherPin = this->_otherPin[it];
        int1 = this->_cmpt[it]->compute(otherPin);
        it = this->findIndex(6);
        otherPin = this->_otherPin[it];
        int2 = this->_cmpt[it]->compute(otherPin);
    }
    if (pin == 10) {
        it = this->findIndex(8);
        otherPin = this->_otherPin[it];
        int1 = this->_cmpt[it]->compute(otherPin);
        it = this->findIndex(9);
        otherPin = this->_otherPin[it];
        int2 = this->_cmpt[it]->compute(otherPin);
    }
    if (pin == 11) {
        it = this->findIndex(12);
        otherPin = this->_otherPin[it];
        int1 = this->_cmpt[it]->compute(otherPin);
        it = this->findIndex(13);
        otherPin = this->_otherPin[it];
        int2 = this->_cmpt[it]->compute(otherPin);
    }
    nts::Tristate res = this->gateAnd(int1, int2);
    res = this->gateNot(res);

    this->_outputs.insert(std::pair<std::size_t, nts::Tristate>(pin, res));
    // std::cout << "C4011: " << res << std::endl;
    return res;
}
