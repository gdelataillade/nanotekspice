/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4071
*/

#ifndef C4071_HPP_
#define C4071_HPP_

#include "Component.hpp"

class C4071 : public Component {
   public:
    C4071(std::string const &name);
    ~C4071();
    nts::Tristate compute(std::size_t pin = 1) final;

   private:
};

#endif /* !C4071_HPP_ */
