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
            case 'L': _cmd.push_back(std::make_shared<LCommand>()); break;
            case 'R': _cmd.push_back(std::make_shared<RCommand>()); break;
            case 'M': _cmd.push_back(std::make_shared<MCommand>()); break;
            default: break;
        }
    }
}
