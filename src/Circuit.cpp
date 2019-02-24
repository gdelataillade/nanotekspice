/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Circuit
*/

#include "Circuit.hpp"

Circuit::Circuit(std::map<std::string, nts::Tristate> inputs, int count)
    : nts::IComponent(), _inputs(inputs), _count(count)
{
    this->chipsetConstructor["4001"] = std::bind(&Circuit::create4001, this, std::placeholders::_1);
    this->chipsetConstructor["4008"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4011"] = std::bind(&Circuit::create4011, this, std::placeholders::_1);
    this->chipsetConstructor["4013"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4017"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4030"] = std::bind(&Circuit::create4030, this, std::placeholders::_1);
    this->chipsetConstructor["4040"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4069"] = std::bind(&Circuit::create4069, this, std::placeholders::_1);
    this->chipsetConstructor["4071"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4081"] = std::bind(&Circuit::create4081, this, std::placeholders::_1);
    this->chipsetConstructor["4094"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4514"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4801"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["2716"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["input"] = std::bind(&Circuit::createInput, this, std::placeholders::_1);
    this->chipsetConstructor["output"] = std::bind(&Circuit::createOutput, this, std::placeholders::_1);
    this->chipsetConstructor["true"] = std::bind(&Circuit::createTrue, this, std::placeholders::_1);
    this->chipsetConstructor["false"] = std::bind(&Circuit::createFalse, this, std::placeholders::_1);
    this->chipsetConstructor["clock"] = std::bind(&Circuit::createClock, this, std::placeholders::_1);
    this->chipsetConstructor["terminal"] = std::bind(&Circuit::create4071, this, std::placeholders::_1);
}

void Circuit::addComponent(std::string name, std::string type)
{
    try {
        if (this->chipsetConstructor.find(type) == this->chipsetConstructor.end())
            throw Error("Config file: a component do not exists");
    }
    catch (Error &e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    Component *c = this->chipsetConstructor[type](name);
    std::map<std::string, nts::Tristate>::iterator it;

    for (it = _inputs.begin(); it != _inputs.end(); it++) {
        if (name == it->first) {
            c->setOutputs(it->second);
        }
    }
    this->_circuit.push_back(c);
    this->_nbCmpts++;
}

void Circuit::addLink(std::string cmpt1, std::size_t pin_1, std::string cmpt2,
                      std::size_t pin_2)
{
    auto buf1 = std::find_if(
        this->_circuit.begin(), this->_circuit.end(),
        [cmpt1](Component *obj) { return obj->getName() == cmpt1; });
    int pos1 = std::distance(this->_circuit.begin(), buf1);
    try {
        if (buf1 == this->_circuit.end()) {
            throw Error("Error: couldn't find the component to link in the container");
        }
    }
    catch (Error &e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
    auto buf2 = std::find_if(
        this->_circuit.begin(), this->_circuit.end(),
        [cmpt2](const Component *obj) { return obj->getName() == cmpt2; });
    int pos2 = std::distance(this->_circuit.begin(), buf2);
    try {
        if (buf2 == this->_circuit.end()) {
            throw("Error: couldn't find the component to link in the container");
        }  
    }
    catch(Error &e) {
        std::cerr << e.what() << std::endl;
    }
    this->_circuit[pos1]->setLink(pin_1, *this->_circuit[pos2], pin_2);
    this->_circuit[pos2]->setLink(pin_2, *this->_circuit[pos1], pin_1);
}

void Circuit::removeComponent() {}

void Circuit::runSimulation()
{
    std::size_t it;

    for (it = 0; it < this->_nbCmpts; ++it) {
        if (this->_circuit[it]->getType() == "output") {
            this->_circuit[it]->compute(1);
        }
    }
}

void Circuit::displayOutputs() const
{
    std::size_t it;

    for (it = 0; it < this->_nbCmpts; ++it) {
        if (this->_circuit[it]->getType() == "output") {
            std::cout << this->_circuit[it]->getName() << "=";
            if (this->_circuit[it]->getOutput(1) == nts::UNDEFINED) {
                std::cout << "U" << std::endl;
            }
            else {
                std::cout << this->_circuit[it]->getOutput(1) << std::endl;
            }
        }
    }
}

void Circuit::dump() const
{
    std::size_t it;

    for (it = 0; it < this->_nbCmpts; ++it) {
        this->_circuit[it]->dump();
    }
}

Component *Circuit::create4069(std::string const &name)
{
    return new C4069(name);
}

Component *Circuit::create4081(std::string const &name)
{
    return new C4081(name);
}

Component *Circuit::create4071(std::string const &name)
{
    return new C4071(name);
}

Component *Circuit::create4011(std::string const &name)
{
    return new C4011(name);
}

Component *Circuit::create4001(std::string const &name)
{
    return new C4001(name);
}

Component *Circuit::create4030(std::string const &name)
{
    return new C4030(name);
}

Component *Circuit::createInput(std::string const &name)
{
    return new Input(name);
}

Component *Circuit::createOutput(std::string const &name)
{
    return new Output(name);
}

Component *Circuit::createTrue(std::string const &name)
{
    return new True(name);
}

Component *Circuit::createFalse(std::string const &name)
{
    return new False(name);
}

Component *Circuit::createClock(std::string const &name)
{
    return new Clock(name, _count);
}