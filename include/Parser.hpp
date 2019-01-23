/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include "Circuit.hpp"

class Parser
{
	public:
		Parser(std::string path, Circuit circuit);
		virtual ~Parser() = default;
                void fillCircuit();
	private:
                std::string _path;
                Circuit *_circuit;
};

#endif /* !PARSER_HPP_ */
