/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4030: 4 nor gates
*/

#include "C4030.hpp"

C4030::C4030(std::string const &name) : Component(name, "4030") {}

C4030::~C4030() {}

nts::Tristate C4030::compute(std::size_t pin) {
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
    nts::Tristate res = this->gateXor(int1, int2);

    this->_outputs.insert(std::pair<std::size_t, nts::Tristate>(pin, res));
    try {
        this->nbCompute++;
        if (this->nbCompute > 15) {
            throw Error("Infinite loop detected. Abort.");
        }
    }
    catch (Error &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    // // std::cout << "C4030: " << res << std::endl;
    return res;
}
