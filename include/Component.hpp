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
    virtual ~Component() {};
    nts::Tristate compute(std::size_t pin = 1) override;
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
    void dump() const override;
    std::string getName() const;

   protected:
    std::string _name;
    std::string _type;
    nts::Tristate _state;
    std::vector<std::pair<std::size_t, nts::Tristate>> _outputs;
    std::vector<std::pair<std::size_t, std::size_t>> _links;
    std::vector<Component*> _cmpt; // donne la liste des linked components

    nts::Tristate gateAnd(nts::Tristate &int1, nts::Tristate &int2);
    nts::Tristate gateOr(nts::Tristate &int1, nts::Tristate &int2);
    nts::Tristate gateNor(nts::Tristate &int1, nts::Tristate &int2);
    nts::Tristate gateNand(nts::Tristate &int1, nts::Tristate &int2);
    nts::Tristate gateXor(nts::Tristate &int1, nts::Tristate &int2);
    nts::Tristate gateXnor(nts::Tristate &int1, nts::Tristate &int2);
};

#endif /* !COMPONENT_HPP_ */