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

class Circuit : public nts::IComponent {
   public:
    Circuit(pairList inputs);
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
    std::vector<Component> _circuit;
    pairList _inputs; // inputs values defined in prompt
};

#endif /* !CIRCUIT_HPP_ */