/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4071
*/

#include "C4071.hpp"

C4071::C4071(std::string const &name) : Component(name, "4071") {

}

C4071::~C4071() {}

nts::Tristate C4071::compute(std::size_t pin)
{
    // std::cout << "Compute at " << this->getName() << std::endl;
    nts::Tristate int1 = this->_cmpt[0]->compute(1);
    nts::Tristate int2 = this->_cmpt[1]->compute(1);
    nts::Tristate res = this->gateOr(int1, int2);

    this->_outputs.insert(std::pair<std::size_t, nts::Tristate>(pin, res));
    // std::cout << "C4071: " << res << std::endl;
    return res;
}
