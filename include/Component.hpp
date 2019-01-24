/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include "IComponent.hpp"

class Component : public nts::IComponent
{
	public:
		Component(std::string name, std::string type);
        nts::Tristate compute(std::size_t pin = 1) final;
        void setLink(std::size_t pin, nts::IComponent &other,
                    std::size_t otherPin) final;
        void dump();
	protected:
        std::string _name;
        std::string _type;
        std::map<std::size_t, std::size_t> _links;
        std::vector<std::size_t> _outputs;
	private:
};

#endif /* !COMPONENT_HPP_ */
