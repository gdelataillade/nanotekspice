/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** main
*/

/*
TODO:
    Les exeptions
    Changer valeurs input dans le terminal
    Free memory (dump)
    Gestions erreurs mauvais inputs/fichier de config
    Creer autres chipsets (clock, nand, nor, ...)
    TESTS UNITAIRES !!! (tester les portes logiques)
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

bool executeCommand(std::string cmd, Circuit **c, std::map<std::string, nts::Tristate> *inputs)
{
    std::string name;
    int value;
    int pos;
    nts::Tristate state;

    if (cmd == "exit" || cmd == "quit") {
        return false;
    }
    if (cmd == "simulate") {
        (*c)->runSimulation();
    }
    if (cmd == "display") {
        (*c)->displayOutputs();
    }
    if (cmd.find('=') != std::string::npos) {
        pos = std::string(cmd).find("=");
        name = std::string(cmd).substr(0, pos);
        value = atoi(std::string(cmd).substr(pos + 1).c_str());
        if (value == 0) {
            state = nts::FALSE;
        } else if (value == 1) {
            state = nts::TRUE;
        } else {
            state = nts::UNDEFINED;
        }
        inputs->clear();
        inputs->insert(std::pair<std::string, nts::Tristate>(name, state)); // remplace la valeur de l'input
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
    std::string path = std::string(argv[1]);
    Parser *p = new Parser(path, c);
    p->fillCircuit();
    c->runSimulation();
    c->displayOutputs();
    std::string cmd;
    while (1) { // gerer le ctrl-C / ctrl-D ?
        std::cout << "> ";
        std::cin >> cmd; // read ?
        if (!executeCommand(cmd, &c, &inputs)) {
            break;
        }
    }
    return 0;
}