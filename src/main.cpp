/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** main
*/

#include "Parser.hpp"

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        std::cerr << "Don't forget the filepath!" << std::endl;
        return 0;  // TROW EXCEPTION !
    }
    Circuit *c = new Circuit();
    std::string path(argv[1]);
    Parser p(path, c);
    p.fillCircuit();
    return 0;
}