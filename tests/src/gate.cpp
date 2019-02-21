/*
** EPITECH PROJECT, 2019
** test component
** File description:
** ex00
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Circuit.hpp"
#include "Parser.hpp"

void setInputs(std::map<std::string, nts::Tristate> *inputs, int argc,
               char const *argv[]) {
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

void redirect_all_stdout(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(C4071, test_component_4071_S1, .init = redirect_all_stdout) {
    char const *command[] = {"./nano", "./exemples/or.nts", "a=1", "b=1"};
    std::map<std::string, nts::Tristate> inputs;
    setInputs(&inputs, 4, command);
    Circuit *c = new Circuit(inputs, 1);
    std::string path = std::string(command[1]);
    Parser *p = new Parser(path, c);
    p->fillCircuit();
    c->runSimulation();
    c->displayOutputs();
    cr_assert_stdout_eq_str("s=1\n");
}

Test(C4071, test_component_4071_S0, .init = redirect_all_stdout) {
    char const *command[] = {"./nano", "./exemples/or.nts", "a=0", "b=0"};
    std::map<std::string, nts::Tristate> inputs;
    setInputs(&inputs, 4, command);
    Circuit *c = new Circuit(inputs, 1);
    std::string path = std::string(command[1]);
    Parser *p = new Parser(path, c);
    p->fillCircuit();
    c->runSimulation();
    c->displayOutputs();
    cr_assert_stdout_eq_str("s=0\n");
}

Test(C4001, test_component_4001_S0, .init = redirect_all_stdout) {
    char const *command[] = {"./nano", "./exemples/nor.nts", "a=0", "b=0"};
    std::map<std::string, nts::Tristate> inputs;
    setInputs(&inputs, 4, command);
    Circuit *c = new Circuit(inputs, 1);
    std::string path = std::string(command[1]);
    Parser *p = new Parser(path, c);
    p->fillCircuit();
    c->runSimulation();
    c->displayOutputs();
    cr_assert_stdout_eq_str("s=1\n");
}

Test(C4001, test_component_4001_S1, .init = redirect_all_stdout) {
    char const *command[] = {"./nano", "../exemples/nor.nts", "a=1", "b=1"};
    std::map<std::string, nts::Tristate> inputs;
    setInputs(&inputs, 4, command);
    Circuit *c = new Circuit(inputs, 1);
    std::string path = std::string(command[1]);
    Parser *p = new Parser(path, c);
    p->fillCircuit();
    c->runSimulation();
    c->displayOutputs();
    cr_assert_stdout_eq_str("s=0\n");
}