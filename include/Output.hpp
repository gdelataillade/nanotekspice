/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
	#define OUTPUT_HPP_

#include "Component.hpp"

class Output : public Component {
	public:
		Output(std::string const &name);
		~Output();
        nts::Tristate compute(std::size_t pin = 1) final;
};

#endif /* !OUTPUT_HPP_ */
