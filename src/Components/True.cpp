/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** True
*/

#include "True.hpp"

True::True(std::string const &name) : Component(name, "true") {}

True::~True() {}

nts::Tristate True::compute(std::size_t pin) {
    // std::cout << "Compute at " << this->getName() << std::endl;
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
    return nts::TRUE;
}
