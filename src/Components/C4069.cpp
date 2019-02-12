/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4069: 6 not gates
*/

#include "C4069.hpp"

C4069::C4069(std::string const &name) : Component(name, "4071") {}

C4069::~C4069() {}

nts::Tristate C4069::compute(std::size_t pin)
{
    // std::cout << "Compute at " << this->getName() << std::endl;
    std::size_t otherPin;
    std::size_t it;
    nts::Tristate int1;
    nts::Tristate res;

    if (pin == 2) {
        otherPin = this->_links[1];
        it = std::distance(this->_links.begin(), this->_links.find(1));
        int1 = this->_cmpt[it]->compute(otherPin);
    }
    if (pin == 4) {
        otherPin = this->_links[3];
        it = std::distance(this->_links.begin(), this->_links.find(3));
        int1 = this->_cmpt[it]->compute(otherPin);
    }
    if (pin == 6) {
        otherPin = this->_links[5];
        it = std::distance(this->_links.begin(), this->_links.find(5));
        int1 = this->_cmpt[it]->compute(otherPin);
    }
    if (pin == 8) {
        otherPin = this->_links[9];
        it = std::distance(this->_links.begin(), this->_links.find(9));
        int1 = this->_cmpt[it]->compute(otherPin);
    }
    if (pin == 10) {
        otherPin = this->_links[11];
        it = std::distance(this->_links.begin(), this->_links.find(11));
        int1 = this->_cmpt[it]->compute(otherPin);
    }
    if (pin == 12) {
        otherPin = this->_links[13];
        it = std::distance(this->_links.begin(), this->_links.find(13));
        int1 = this->_cmpt[it]->compute(otherPin);
    }
    res = this->gateNot(int1);

    this->_outputs.insert(std::pair<std::size_t, nts::Tristate>(pin, res));
    // // std::cout << "C4069: " << res << std::endl;
    return res;
}
