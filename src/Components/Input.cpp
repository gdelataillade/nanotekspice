/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Input
*/

#include "Input.hpp"

Input::Input(std::string const &name) : Component(name, "input") {}

Input::~Input() {}

nts::Tristate Input::compute(std::size_t pin)
{
    try {
        if (this->_outputs.empty()) {
            throw Error("Input do not have init value");
        }
    }
    catch(Error &e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
    return this->getOutput(1);
}
