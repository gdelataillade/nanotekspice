/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4069
*/

#ifndef C4069_HPP_
#define C4069_HPP_

#include "Component.hpp"

class C4069 : public Component {
   public:
    C4069(std::string const &name);
    ~C4069();
    nts::Tristate compute(std::size_t pin = 1) final;

   private:
};

#endif /* !C4069_HPP_ */
