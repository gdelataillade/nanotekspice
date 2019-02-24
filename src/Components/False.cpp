/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** False
*/

#include "False.hpp"

False::False(std::string const &name) : Component(name, "input") {}

False::~False() {}

nts::Tristate False::compute(std::size_t pin) {
    // std::cout << "Compute at " << this->getName() << std::endl;
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
    return nts::FALSE;
}
