/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include "IComponent.hpp"

class Component : public nts::IComponent {
   public:
    Component(std::string name, std::string type);
    nts::Tristate compute(std::size_t pin = 1) override;
    void setLink(std::size_t pin, Component &other, std::size_t otherPin);
    void dump();

   protected:
    std::string _name;
    std::string _type;
    std::map<std::size_t, std::size_t> _links;
    std::map<std::size_t, nts::Tristate> _outputs;
    nts::Tristate gateAnd(nts::Tristate &int1, nts::Tristate &int2);
    nts::Tristate gateOr(nts::Tristate &int1, nts::Tristate &int2);
    nts::Tristate gateNor(nts::Tristate &int1, nts::Tristate &int2);
    nts::Tristate gateNand(nts::Tristate &int1, nts::Tristate &int2);
    nts::Tristate gateXor(nts::Tristate &int1, nts::Tristate &int2);
    nts::Tristate gateXnor(nts::Tristate &int1, nts::Tristate &int2);

   private:
};

#endif /* !COMPONENT_HPP_ */
