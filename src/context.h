//
// Created by lulu on 2020/2/15.
//

#ifndef MARSROVER_CONTEXT_H
#define MARSROVER_CONTEXT_H

#include <string>
#include <vector>
#include <memory>

class Command;

class Context {
public:
    Context(std::string cmd_str);
    ~Context();

    std::vector<std::shared_ptr<Command>> get_command_list();
private:
    std::vector<std::shared_ptr<Command>> _cmd;
};

inline std::vector<std::shared_ptr<Command>> Context::get_command_list() {
    return _cmd;
}



#endif //MARSROVER_CONTEXT_H
