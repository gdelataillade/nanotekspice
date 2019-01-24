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

class Circuit : public nts::IComponent
{
	public:
		Circuit();
                void addComponent(std::string name, std::string type);
                void addLink(std::string cmpt1, std::size_t pin_1, std::string cmpt2, std::size_t pin_2);
                void removeComponent();
                void runSimulation();
	private:
                std::vector<nts::IComponent> _circuit;
};

#endif /* !CIRCUIT_HPP_ */
