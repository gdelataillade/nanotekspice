/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4011
*/

#ifndef C4011_HPP_
#define C4011_HPP_

#include "Component.hpp"

class C4011 : public Component {
   public:
    C4011(std::string const &name);
    ~C4011();
    nts::Tristate compute(std::size_t pin = 1) final;

   private:
};

#endif /* !C4011_HPP_ */
