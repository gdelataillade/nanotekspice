/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Input
*/

#ifndef INPUT_HPP_
	#define INPUT_HPP_

#include "Component.hpp"

class Input : public Component {
	public:
		Input(std::string const &name);
		~Input();
        nts::Tristate compute(std::size_t pin = 1) final;
};

#endif /* !INPUT_HPP_ */
