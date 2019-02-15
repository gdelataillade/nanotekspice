/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** False
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "Component.hpp"

class False : public Component {
   public:
    False(std::string const &name);
    ~False();
    nts::Tristate compute(std::size_t pin = 1) final;

   protected:
   private:
};

#endif /* !FALSE_HPP_ */
