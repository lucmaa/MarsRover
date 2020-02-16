//
// Created by lulu on 2020/2/15.
//

#include "context.h"
#include "command.h"

Context::Context(std::string cmd_str)
{
    int len = cmd_str.length();
    for (int i = 0; i < len; ++i) {
        switch (cmd_str[i]) {
            case 'L': _cmd.push_back(std::make_shared<LeftCommand>()); break;
            case 'R': _cmd.push_back(std::make_shared<RightCommand>()); break;
            case 'M': _cmd.push_back(std::make_shared<MoveCommand>()); break;
            default: break;
        }
    }

    // The receiver should echo something in the end.
    _cmd.push_back(std::make_shared<RogerCommand>());
}

Context::~Context() {

}
