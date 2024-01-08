#pragma once

#include "Application.h"

//-----------------------------------------------------------------------------
// Win32Application
//-----------------------------------------------------------------------------
class Win32Application : public Application
{
public:
    Win32Application();

    virtual int ExecuteInternal(int argc, char** argv) override;
    virtual void OutputMessage(const std::string& message) const override;
    virtual bool ProcessMessages() override;
};