/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Circuit
*/

#include "Circuit.hpp"

Circuit::Circuit(pairList inputs)
: nts::IComponent(), _inputs(inputs) {
    this->chipsetConstructor["4001"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4008"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4011"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4013"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4017"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4030"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4040"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4069"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4071"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4081"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4094"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4514"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4801"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["2716"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["input"] = std::bind(&Circuit::createInput, this, std::placeholders::_1);
    this->chipsetConstructor["output"] = std::bind(&Circuit::createOutput, this, std::placeholders::_1);
    this->chipsetConstructor["true"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["false"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["clock"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["terminal"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
}

void Circuit::addComponent(std::string name, std::string type)
{
    // create new component and add it to the vector container
    std::cout << "Type: [" << type << "], name: [" << name << "]" << std::endl;
    // Component c(name, type);


    if (this->chipsetConstructor.find(type) == this->chipsetConstructor.end())
        return;

    Component *c = this->chipsetConstructor[type](name);

    if (c == nullptr)
        return; // EXCEPTION
    for (int pos = 0; pos < (int)_inputs.size(); pos++) {
        if (name == _inputs[pos].first) {
            std::cout << "Set state for " << name << " to " << _inputs[pos].second << std::endl;
            c->setOutputs(_inputs[pos].second);
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
    auto buf2 = std::find_if(this->_circuit.begin(), this->_circuit.end(),
            [cmpt2](const Component* obj) {
                return obj->getName() == cmpt2;
            });
    int pos2 = std::distance(this->_circuit.begin(), buf2);
    if (buf2 == this->_circuit.end()) {
        std::cerr << "Error: couldn't find the component to link in the container" << std::endl; // EXCEPTION
        return;
    }
    this->_circuit[pos1]->setLink(pin_1, *this->_circuit[pos2], pin_2);
    this->_circuit[pos2]->setLink(pin_2, *this->_circuit[pos1], pin_1);
}

void Circuit::removeComponent() {
    // delete component in parameter
    // and remove it from vector container
}

void Circuit::runSimulation() {
    std::cout << "====RUN SIMULATION====" << std::endl;
    // for (int i = 0; i < (int)this->_circuit.size(); i++) {
    //     std::cout << "---" << this->_circuit[i]->getName() << "---" << std::endl;
    //     std::cout << this->_circuit[i]->compute(3) << std::endl;
    // }
    std::cout << this->_circuit[2]->compute(1) << std::endl;
}


Component *Circuit::create4071(std::string const &name){
    return new C4071(name);
}

Component *Circuit::createInput(std::string const &name) {
    return new Input(name);
}

Component *Circuit::createOutput(std::string const &name) {
    return new Output(name);
}