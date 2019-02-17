/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4001
*/

#ifndef C4001_HPP_
#define C4001_HPP_

#include "Component.hpp"

class C4001 : public Component {
   public:
    C4001(std::string const &name);
    ~C4001();
    nts::Tristate compute(std::size_t pin = 1) final;

   private:
};

#endif /* !C4001_HPP_ */
