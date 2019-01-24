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
    int pos;

    file.open(this->_path);
    if (!file) {
        // THROW EXCPETION HERE:
        std::cerr << "Error: Couldn't open the file" << std::endl;
        return;
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
                    std::cout << arr[0] << "->" << arr[1] << std::endl;
                    // this->_circuit->addComponent();
                }
                else if (level == 2) { // links
                    pos = arr[0].find(":");
                    std::cout << arr[0].substr(0, pos) << "->";
                    std::cout << arr[0].substr(pos + 1) << " ";
                    pos = arr[1].find(":");
                    std::cout << arr[1].substr(0, pos) << "->";
                    std::cout << arr[1].substr(pos + 1) << std::endl;
                    // this->_circuit->setLink();
                }
            }
        }
    }
    file.close();
}