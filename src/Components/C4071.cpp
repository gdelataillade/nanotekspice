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
    nts::Tristate int1 = nts::TRUE;
    nts::Tristate int2 = nts::TRUE;
    nts::Tristate res = this->gateAnd(int1, int2);

    std::cout << "C4071: " << res << std::endl;
    return nts::UNDEFINED;
}
