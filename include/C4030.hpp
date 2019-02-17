/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4030
*/

#ifndef C4030_HPP_
#define C4030_HPP_

#include "Component.hpp"

class C4030 : public Component {
   public:
    C4030(std::string const &name);
    ~C4030();
    nts::Tristate compute(std::size_t pin = 1) final;

   private:
};

#endif /* !C4030_HPP_ */
