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

Test(C4081, test_component_4081_S1, .init = redirect_all_stdout) {
    char const *command[] = {"./nano", "./exemples/and.nts", "a=1", "b=1"};
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

Test(C4081, test_component_4081_S0, .init = redirect_all_stdout) {
    char const *command[] = {"./nano", "./exemples/and.nts", "a=0", "b=1"};
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

Test(C4030, test_component_4030_S1, .init = redirect_all_stdout) {
    char const *command[] = {"./nano", "./exemples/xor.nts", "a=1", "b=1"};
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

Test(C4030, test_component_4030_S0, .init = redirect_all_stdout) {
    char const *command[] = {"./nano", "./exemples/xor.nts", "a=1", "b=0"};
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

Test(C4069, test_component_4069_S0, .init = redirect_all_stdout) {
    char const *command[] = {"./nano", "./exemples/not.nts", "i0=1", "i1=1"};
    std::map<std::string, nts::Tristate> inputs;
    setInputs(&inputs, 4, command);
    Circuit *c = new Circuit(inputs, 1);
    std::string path = std::string(command[1]);
    Parser *p = new Parser(path, c);
    p->fillCircuit();
    c->runSimulation();
    c->displayOutputs();
    cr_assert_stdout_eq_str("o0=0\no1=0\no2=0\no3=0\no4=0\no5=0\n");
}

Test(C4069, test_component_4069_S1, .init = redirect_all_stdout) {
    char const *command[] = {
        "./nano", "./exemples/not.nts", "i0=0", "i1=0", "i2=0", "i3=0", "i4=0",
        "i5=0",
    };
    std::map<std::string, nts::Tristate> inputs;
    setInputs(&inputs, 4, command);
    Circuit *c = new Circuit(inputs, 1);
    std::string path = std::string(command[1]);
    Parser *p = new Parser(path, c);
    p->fillCircuit();
    c->runSimulation();
    c->displayOutputs();
    cr_assert_stdout_eq_str("o0=1\no1=1\no2=0\no3=0\no4=0\no5=0\n");
}

Test(C4011, test_component_4011_S0, .init = redirect_all_stdout) {
    char const *command[] = {"./nano", "./exemples/nand.nts", "i0=1", "i1=1"};
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

Test(C4011, test_component_4011_S1, .init = redirect_all_stdout) {
    char const *command[] = {
        "./nano", "./exemples/nand.nts", "i0=1", "i1=1", "i2=1", "i3=1", "i4=1",
        "i5=1",
    };
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