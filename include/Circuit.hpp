/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "IComponent.hpp"

class Circuit : public nts::IComponent
{
	public:
		Circuit();
                void addComponent();
                void removeComponent();
                void runSimulation();
	private:
                std::vector<nts::IComponent> _circuit;
};

#endif /* !CIRCUIT_HPP_ */
