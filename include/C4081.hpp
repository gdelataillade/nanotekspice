/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4081
*/

#ifndef C4081_HPP_
#define C4081_HPP_

#include "Component.hpp"

class C4081 : public Component {
   public:
    C4081(std::string const &name);
    ~C4081();
    nts::Tristate compute(std::size_t pin = 1) final;

   private:
};

#endif /* !C4081_HPP_ */
