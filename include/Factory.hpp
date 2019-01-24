/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "C4071.hpp"
#include "Component.hpp"

class Factory {
   public:
    Factory();
    ~Factory();

   protected:
   private:
    Component* create4071(const std ::string& value) const noexcept;
};

#endif /* !FACTORY_HPP_ */
