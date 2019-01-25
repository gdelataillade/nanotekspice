/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Circuit
*/

#include "Circuit.hpp"

Circuit::Circuit() : nts::IComponent() {}

void Circuit::addComponent(std::string name, std::string type)
{
    // create new component and add it to the vector container
    std::cout << "Type: [" << type << "], name: [" << name << "]" << std::endl;
    const Component c(name, type);
    this->_circuit.push_back(c);
}

void Circuit::addLink(std::string cmpt1, std::size_t pin_1, std::string cmpt2,
                      std::size_t pin_2) {
    // find matching components with names and assign pins
    std::cout << "Link " << cmpt1 << ":" << pin_1 << " to " << cmpt2 << ":" << pin_2 << std::endl;
    auto buf1 = std::find_if(this->_circuit.begin(), this->_circuit.end(),
            [&cmpt1](const Component& obj) {
                return obj.getName() == cmpt1;
            });
    int pos1 = std::distance(this->_circuit.begin(), buf1);
    if (buf1 == this->_circuit.end()) {
        std::cerr << "Error: couldn't find the component to link in the container" << std::endl; // EXCEPTION
    }
    // std::cout << cmpt1 <<  " pos: " << pos1 << std::endl;
    auto buf2 = std::find_if(this->_circuit.begin(), this->_circuit.end(),
            [&cmpt2](const Component& obj) {
                return obj.getName() == cmpt2;
            });
    int pos2 = std::distance(this->_circuit.begin(), buf2);
    if (buf2 == this->_circuit.end()) {
        std::cerr << "Error: couldn't find the component to link in the container" << std::endl; // EXCEPTION
    }
    // std::cout << cmpt2 <<  " pos: " << pos2 << std::endl;
    this->_circuit[pos1].setLink(pin_1, this->_circuit[pos2], pin_2);
}

void Circuit::removeComponent() {
    // delete component in parameter
    // and remove it from vector container
}

void Circuit::runSimulation() {
    // go through the vector container
    // and run each component with simulate()
}