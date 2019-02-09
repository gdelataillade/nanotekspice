/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Output
*/

#include "Output.hpp"

Output::Output(std::string const &name) : Component(name, "output")
{
}

Output::~Output()
{
}

nts::Tristate Output::compute(std::size_t pin)
{
    // std::cout << "Compute at " << this->getName() << std::endl;
    return this->_cmpt[0]->compute(this->_links[1]);
}
