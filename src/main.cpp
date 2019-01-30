/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** main
*/

#include "Parser.hpp"

std::vector<std::pair<std::string, std::size_t>> setInputs(std::vector<std::pair<std::string, std::size_t>> *inputs, int argc, char const *argv[])
{
    if (argc < 3) {
        return *inputs;
    }
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        std::cerr << "Don't forget the filepath!" << std::endl;
        return 0;  // TROW EXCEPTION !
    }
    std::vector<std::pair<std::string, std::size_t>> inputs = setInputs(&inputs, argc, argv);
    Circuit *c = new Circuit();
    std::string path(argv[1]);
    Parser p(path, c);
    p.fillCircuit();
    c->runSimulation();
    std::string input;
    while (1) {
        std::cout << "> ";
        std::cin >> input;
    }
    return 0;
}