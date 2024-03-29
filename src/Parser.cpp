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
    int level = 0;
    int it = 0;
    std::string arr[3];
    std::string arr2[3];
    int pos;

    try {
        file.open(this->_path);
        if (!file) {
            throw Error("Error: Couldn't open the file");
        }
    }
    catch (Error &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    while (!file.eof()) {
        getline(file, buf);
        if (buf.compare(0, 1, "#") != 0 && buf.compare(0, 1, "") != 0) {
            if (buf.compare(0, 10, ".chipsets:") == 0)
                level = 1;
            else if (buf.compare(0, 7, ".links:") == 0)
                level = 2;
            else {
                std::stringstream ssin(buf);
                while (ssin.good() && it < 3) {
                        ssin >> arr[it];
                        ++it;
                }
                it = 0;
                if (level == 1) { // chipsets
                    this->_circuit->addComponent(arr[1], arr[0]);
                }
                else if (level == 2) { // links
                    pos = arr[0].find(":");
                    arr2[0] = arr[0].substr(0, pos);
                    arr2[1] = arr[0].substr(pos + 1);
                    pos = arr[1].find(":");
                    this->_circuit->addLink(arr2[0], (size_t)std::stoi(arr2[1]), arr[1].substr(0, pos), (size_t)std::stoi(arr[1].substr(pos + 1)));
                }
            }
        }
    }
    try {
        if (level != 2) {
            throw Error("Error with sections in the configuration file");
        }
    }
    catch(Error &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    file.close();
}