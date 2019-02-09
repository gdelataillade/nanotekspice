/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Input
*/

#include "Input.hpp"

Input::Input(std::string const &name) : Component(name, "input")
{
}

Input::~Input()
{
}

nts::Tristate Input::compute(std::size_t pin)
{
    // std::cout << "Compute at " << this->getName() << std::endl;
    return this->getOutput(1);
}
