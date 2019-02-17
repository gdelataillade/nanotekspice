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
    this->_outputs.insert(std::pair<std::size_t, nts::Tristate>(1, this->_cmpt[0]->compute(this->_otherPin[0])));
    return this->getOutput(1);
}
