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
    void setOutputs(nts::Tristate state);
    nts::Tristate getOutput(std::size_t pin);

   protected:
    std::string _name;
    std::string _type;
    std::map<std::size_t, nts::Tristate> _outputs;
    std::map<std::size_t, std::size_t> _links;
    std::vector<Component*> _cmpt; // donne la liste des linked components

    nts::Tristate gateAnd(nts::Tristate &int1, nts::Tristate &int2);
    nts::Tristate gateOr(nts::Tristate &int1, nts::Tristate &int2);
    nts::Tristate gateNor(nts::Tristate &int1, nts::Tristate &int2);
    nts::Tristate gateNand(nts::Tristate &int1, nts::Tristate &int2);
    nts::Tristate gateXor(nts::Tristate &int1, nts::Tristate &int2);
    nts::Tristate gateXnor(nts::Tristate &int1, nts::Tristate &int2);
};

#endif /* !COMPONENT_HPP_ */
