#pragma once

#ifndef MANAGER_H
#define MANAGER_H

#include "maingame.h"

class manager
{
public:
    static manager& getInstance()
    {
        static manager mgr_;
        return mgr_;
    }

    void maingame_start();

    maingame dialog;

private:
    manager() {}
    manager(const manager& ref) = delete;
    manager& operator=(const manager& ref) = delete;
    ~manager() {}
};

#endif // MANAGER_H
