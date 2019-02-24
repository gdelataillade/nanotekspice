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
        this->nbCompute++;
        if (this->nbCompute > 5) {
            throw Error("Infinite loop detected. Abort.");
        }
    }
    catch (Error &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    return this->getOutput(1);
}