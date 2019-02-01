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

// use typedef for vector of pairs

class Circuit : public nts::IComponent {
   public:
    Circuit(std::vector<std::pair<std::string, nts::Tristate>> inputs);
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
    std::vector<std::pair<std::string, nts::Tristate>> _inputs; // inputs values defined in prompt
};

#endif /* !CIRCUIT_HPP_ */