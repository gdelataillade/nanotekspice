/*
** EPITECH PROJECT, 2019
** Nano
** File description:
** Excpetions
*/

#ifndef EXCEPTION_HPP_
	#define EXCEPTION_HPP_

#include <string>
#include <iostream>
#include <exception>

class Error : public std::exception
{
    public:
        Error(const char* msg) throw();
        Error() throw();
        virtual ~Error() throw() {};
        virtual const char *what() const throw();
    protected:
    private:
        const char *_message;
};

#endif /* !EXCEPTION_HPP_ */
