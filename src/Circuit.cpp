/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Circuit
*/

#include "Circuit.hpp"

Circuit::Circuit(pairList inputs)
: nts::IComponent(), _inputs(inputs) {}

void Circuit::addComponent(std::string name, std::string type, Factory f)
{
    // create new component and add it to the vector container
    std::cout << "Type: [" << type << "], name: [" << name << "]" << std::endl;
    // Component c(name, type);

    Component *c = f.createComponent(type, name);

    for (int pos = 0; pos < (int)_inputs.size(); pos++) {
        if (name == _inputs[pos].first) {
            std::cout << "Set state for " << name << " to " << _inputs[pos].second << std::endl;
            c->setstate(_inputs[pos].second);
        }
    }
    this->_circuit.push_back(c);
}

void Circuit::addLink(std::string cmpt1, std::size_t pin_1, std::string cmpt2,
                      std::size_t pin_2) {
    // find matching components with names and assign pins
    std::cout << "Link " << cmpt1 << ":" << pin_1 << " to " << cmpt2 << ":" << pin_2 << std::endl;
    auto buf1 = std::find_if(this->_circuit.begin(), this->_circuit.end(),
            [cmpt1](Component* obj) {
                return obj->getName() == cmpt1;
            });
    int pos1 = std::distance(this->_circuit.begin(), buf1);
    if (buf1 == this->_circuit.end()) {
        std::cerr << "Error: couldn't find the component to link in the container" << std::endl; // EXCEPTION
        return;
    }
    // std::cout << cmpt1 <<  " pos: " << pos1 << std::endl;
    auto buf2 = std::find_if(this->_circuit.begin(), this->_circuit.end(),
            [cmpt2](const Component* obj) {
                return obj->getName() == cmpt2;
            });
    int pos2 = std::distance(this->_circuit.begin(), buf2);
    if (buf2 == this->_circuit.end()) {
        std::cerr << "Error: couldn't find the component to link in the container" << std::endl; // EXCEPTION
        return;
    }
    // std::cout << cmpt2 <<  " pos: " << pos2 << std::endl;
    this->_circuit[pos1]->setLink(pin_1, *this->_circuit[pos2], pin_2);
    this->_circuit[pos2]->setLink(pin_2, *this->_circuit[pos1], pin_1);
}

void Circuit::removeComponent() {
    // delete component in parameter
    // and remove it from vector container
}

void Circuit::runSimulation() {
    // go through the vector container
    // and run each component with simulate()
    std::cout << "====RUN SIMULATION====" << std::endl;
    for (int i = 0; i < (int)this->_circuit.size(); i++) {
        std::cout << "---" << this->_circuit[i]->getName() << "---" << std::endl;
        std::cout << this->_circuit[i]->compute(0) << std::endl;
    }
}