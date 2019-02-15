/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** True
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include "Component.hpp"

class True : public Component {
   public:
    True(std::string const &name);
    ~True();
    nts::Tristate compute(std::size_t pin = 1) final;

   protected:
   private:
};

#endif /* !TRUE_HPP_ */
