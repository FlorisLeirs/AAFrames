#pragma once

#include "Application.h"

//-----------------------------------------------------------------------------
// QnxApplication
//-----------------------------------------------------------------------------
class LinuxApplication : public Application
{
public:
    LinuxApplication();

    virtual bool ProcessMessages() override;
};