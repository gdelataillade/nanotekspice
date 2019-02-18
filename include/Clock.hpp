/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "Component.hpp"

class Clock : public Component {
   public:
    Clock(std::string const &name, int count);
    ~Clock();
    nts::Tristate compute(std::size_t pin = 1) final;

   protected:
   private:
      int _count;
};

#endif /* !CLOCK_HPP_ */
