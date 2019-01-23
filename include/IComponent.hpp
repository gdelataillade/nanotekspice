/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <map>

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    class IComponent
    {
        public:
            virtual ~IComponent() = default;

        public:
            virtual nts::Tristate compute(std::size_t pin = 1) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other,
                                std::size_t otherPin) = 0;
            virtual void dump() const = 0;
    };
}  // namespace nts

#endif /* !ICOMPONENT_HPP_ */
