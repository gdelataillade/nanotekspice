/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** main
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
        pos = std::string(argv[it]).find("=");
        name = std::string(argv[it]).substr(0, pos);
        value = atoi(std::string(argv[it]).substr(pos + 1).c_str());
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

bool executeCommand(std::string cmd, Circuit **c, std::map<std::string, nts::Tristate> *inputs, Parser **p, std::string path)
{
    std::string name;
    int value;
    int pos;
    nts::Tristate state;
    static int count = 1;

    if (cmd == "exit") {
        return false;
    }
    if (cmd == "simulate") {
        count++;
        (*c) = new Circuit(*inputs, count);
        (*p) = new Parser(path, *c);
        (*p)->fillCircuit();
        (*c)->runSimulation();
    }
    if (cmd == "display") {
        (*c)->displayOutputs();
        std::cout << "> ";
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
        inputs->insert(std::pair<std::string, nts::Tristate>(name, state));
    }
    return true;
}

int main(int argc, char const *argv[])
{
    try {
        if (argc < 2)
            throw Error("Don't forget the filepath!");
    }
    catch (Error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    std::map<std::string, nts::Tristate> inputs;
    setInputs(&inputs, argc, argv);
    Circuit *c = new Circuit(inputs, 1);
    std::string path = std::string(argv[1]);
    Parser *p = new Parser(path, c);
    try {
        p->fillCircuit();
        c->runSimulation();
        c->displayOutputs();
    }
    catch(Error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    std::string cmd;
    std::cout << "> ";
    while (std::getline(std::cin, cmd)) {
        std::cout << "> ";
        if (!executeCommand(cmd, &c, &inputs, &p, path)) {
            break;
        }
    }
    c->dump();
    delete c;
    delete p;
    return 0;
}