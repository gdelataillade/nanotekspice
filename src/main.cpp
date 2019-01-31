/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** main
*/

#include "Parser.hpp"

void
setInputs(std::vector<std::pair<std::string, std::size_t>> *inputs, int argc, char const *argv[])
{
    int it = 2;
    std::string name;
    int value;
    int pos;
    std::pair<std::string, int> pair;

    while (it < argc) {
        std::cout << argv[it] << ": ";
        pos = std::string(argv[it]).find("=");
        name = std::string(argv[it]).substr(0, pos);
        value = atoi(std::string(argv[it]).substr(pos + 1).c_str());
        std::cout << name << " ~ " << value << std::endl;
        pair = std::make_pair(name, value);
        inputs->push_back(pair);
        it++;
    }
}

bool executeCommand(std::string cmd, Circuit **c)
{
    if (cmd == "exit") {
        return false;
    }
    if (cmd == "simulate") {
        std::cout << "simulating..." << std::endl;
        (*c)->runSimulation();
    }
    if (cmd == "display") {
        std::cout << "displaying..." << std::endl;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        std::cerr << "Don't forget the filepath!" << std::endl;
        return 0;  // TROW EXCEPTION !
    }
    std::vector<std::pair<std::string, std::size_t>> inputs;
    setInputs(&inputs, argc, argv);
    Circuit *c = new Circuit(inputs);
    std::string path(argv[1]);
    Parser p(path, c);
    p.fillCircuit();
    c->runSimulation();
    std::string input;
    while (1) {
        std::cout << "> ";
        std::cin >> input; // read ?
        if (!executeCommand(input, &c)) {
            break;
        }
    }
    return 0;
}