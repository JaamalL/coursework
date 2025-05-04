#pragma once

class ICommand
{
public:
    virtual ~ICommand() = default;
public:
    virtual void execute() = 0;

};
