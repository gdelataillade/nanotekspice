/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** main
*/

/*
TODO:
    Les exeptions
*/

#include "IComponent.hpp"
#include "Parser.hpp"

void setInputs(std::map<std::string, nts::Tristate> *inputs, int argc, char const *argv[])
{
    int it = 2;
    std::string name;
    int value;
    int pos;
    nts::Tristate state;

    while (it < argc) {
        // std::cout << argv[it] << ": ";
        pos = std::string(argv[it]).find("=");
        name = std::string(argv[it]).substr(0, pos);
        value = atoi(std::string(argv[it]).substr(pos + 1).c_str());
        // std::cout << name << " ~ " << value << std::endl;
        if (value == 0) {
            state = nts::FALSE;
        } else if (value == 1) {
            state = nts::TRUE;
        } else {
            state = nts::UNDEFINED;
        }
        inputs->insert(std::pair<std::string, nts::Tristate>(name, state));
        it++;
    }
}

bool executeCommand(std::string cmd, Circuit **c)
{
    if (cmd == "exit" || cmd == "quit") {
        return false;
    }
    if (cmd == "simulate") {
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
    std::map<std::string, nts::Tristate> inputs;
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