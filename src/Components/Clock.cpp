/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Clock
*/

#include "Clock.hpp"

Clock::Clock(std::string const &name, int count)
: Component(name, "clock"), _count(count) {}

Clock::~Clock() {}

nts::Tristate Clock::compute(std::size_t pin)
{
    // std::cout << "Compute at " << this->getName() << this->getOutput(1) << std::endl;
    // std::cout << "count=" << _count << std::endl;
    nts::Tristate tmp;

    tmp = this->getOutput(1);
    if (_count % 2 == 0) {
        this->_outputs.clear();
        this->setOutputs(this->gateNot(tmp));
    }
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
    return this->getOutput(1);
}
