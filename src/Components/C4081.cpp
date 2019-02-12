/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4081: 4 and gates
*/

#include "C4081.hpp"

C4081::C4081(std::string const &name) : Component(name, "4081") {

}

C4081::~C4081() {}

nts::Tristate C4081::compute(std::size_t pin)
{
    // std::cout << "Compute at " << this->getName() << std::endl;
    std::size_t otherPin;
    std::size_t it;
    nts::Tristate int1;
    nts::Tristate int2;

    if (pin == 3) {
        otherPin = this->_links[1];
        it = std::distance(this->_links.begin(), this->_links.find(1));
        int1 = this->_cmpt[it]->compute(otherPin);
        otherPin = this->_links[2];
        it = std::distance(this->_links.begin(), this->_links.find(2));
        int2 = this->_cmpt[it]->compute(otherPin);
    }
    if (pin == 4) {
        otherPin = this->_links[5];
        it = std::distance(this->_links.begin(), this->_links.find(5));
        int1 = this->_cmpt[it]->compute(otherPin);
        otherPin = this->_links[6];
        it = std::distance(this->_links.begin(), this->_links.find(6));
        int2 = this->_cmpt[it]->compute(otherPin);
    }
    if (pin == 10) {
        otherPin = this->_links[8];
        it = std::distance(this->_links.begin(), this->_links.find(8));
        int1 = this->_cmpt[it]->compute(otherPin);
        otherPin = this->_links[9];
        it = std::distance(this->_links.begin(), this->_links.find(9));
        int2 = this->_cmpt[it]->compute(otherPin);
    }
    if (pin == 11) {
        otherPin = this->_links[12];
        it = std::distance(this->_links.begin(), this->_links.find(12));
        int1 = this->_cmpt[it]->compute(otherPin);
        otherPin = this->_links[13];
        it = std::distance(this->_links.begin(), this->_links.find(13));
        int2 = this->_cmpt[it]->compute(otherPin);
    }
    nts::Tristate res = this->gateAnd(int1, int2);

    this->_outputs.insert(std::pair<std::size_t, nts::Tristate>(pin, res));
    // // std::cout << "C4081: " << res << std::endl;
    return res;
}