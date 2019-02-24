/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4069: 6 not gates
*/

#include "C4069.hpp"

C4069::C4069(std::string const &name) : Component(name, "4069") {}

C4069::~C4069() {}

nts::Tristate C4069::compute(std::size_t pin) {
    // std::cout << "Compute at " << this->getName() << std::endl;
    std::size_t otherPin;
    std::size_t it;
    nts::Tristate int1;
    nts::Tristate res;

    if (pin == 2) {
        it = this->findIndex(1);
        otherPin = this->_otherPin[it];
        int1 = this->_cmpt[it]->compute(otherPin);
    }
    if (pin == 4) {
        it = this->findIndex(3);
        otherPin = this->_otherPin[it];
        int1 = this->_cmpt[it]->compute(otherPin);
    }
    if (pin == 6) {
        it = this->findIndex(5);
        otherPin = this->_otherPin[it];
        int1 = this->_cmpt[it]->compute(otherPin);
    }
    if (pin == 8) {
        it = this->findIndex(9);
        otherPin = this->_otherPin[it];
        int1 = this->_cmpt[it]->compute(otherPin);
    }
    if (pin == 10) {
        it = this->findIndex(11);
        otherPin = this->_otherPin[it];
        int1 = this->_cmpt[it]->compute(otherPin);
    }
    if (pin == 12) {
        it = this->findIndex(13);
        otherPin = this->_otherPin[it];
        int1 = this->_cmpt[it]->compute(otherPin);
    }
    res = this->gateNot(int1);

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
    // // std::cout << "C4069: " << res << std::endl;
    return res;
}
