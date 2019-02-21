/*
** EPITECH PROJECT, 2019
** Nano
** File description:
** Exceptions
*/

#include "Exception.hpp"

Error::Error(const char *msg) throw() : _message(msg) {}

Error::Error() throw() : _message("") {}

const char* Error::what() const throw()
{
    return this->_message;
}