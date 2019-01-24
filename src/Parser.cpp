/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser(std::string path, Circuit *circuit)
: _path(path), _circuit(circuit){}

void Parser::fillCircuit()
{
        std::ifstream file;
        std::string buf;

        file.open(this->_path);
        if (!file) {
                // THROW EXCPETION HERE:
                std::cerr << "Error: Couldn't open the file" << std::endl;
                return;
        }
        while (!file.eof()) {
                getline(file, buf);
                std::cout << buf << std::endl;
        }
        file.close();
}