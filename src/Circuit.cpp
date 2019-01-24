/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Circuit
*/

#include "Circuit.hpp"

Circuit::Circuit() : nts::IComponent()
{
}

void Circuit::addComponent(std::string name, std::string type)
{
        // create new component and add it to the vector container
        std::cout << "Type: [" << type << "], name: [" << name << "]" << std::endl;
        const Component c(name, type);
        this->_circuit.push_back(c);
}

void Circuit::addLink(std::string cmpt1, std::size_t pin_1, std::string cmpt2, std::size_t pin_2)
{
        // find matching components with names and assign pins
        std::cout << "Link " << cmpt1 << ":" << pin_1 << " to " << cmpt2 << ":" << pin_2 << std::endl;
}

void Circuit::removeComponent()
{
        // delete component in parameter
        // and remove it from vector container
}

void Circuit::runSimulation()
{
        // go through the vector container
        // and run each component with simulate()
}