/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "Component.hpp"
#include "IComponent.hpp"
#include <functional>

#include "C4069.hpp"
#include "C4071.hpp"
#include "C4081.hpp"
#include "Input.hpp"
#include "Output.hpp"

class Circuit : public nts::IComponent {
   public:
    Circuit(std::map<std::string, nts::Tristate> inputs);
    virtual ~Circuit() {};
    void addComponent(std::string name, std::string type);
    void addLink(std::string cmpt1, std::size_t pin_1, std::string cmpt2,
                 std::size_t pin_2);
    void removeComponent();
    void runSimulation();
    nts::Tristate compute(std::size_t pin = 1) override { return nts::UNDEFINED; };
    void setLink(std::size_t pin, nts::IComponent &other,
                 std::size_t otherPin) override{};
    void dump() const override { return; };

   private:
    std::vector<Component*> _circuit;
    std::size_t _nbCmpts = 0;
    std::map<std::string, nts::Tristate> _inputs; // inputs values defined in prompt

    std::map<std::string, std::function<Component *(const std::string &)>> chipsetConstructor;

    Component *createInput(std::string const &name);
    Component *createOutput(std::string const &name);
    Component *create4071(std::string const &name);
    Component *create4081(std::string const &name);
    Component *create4069(std::string const &name);
};

#endif /* !CIRCUIT_HPP_ */