#pragma once

#include "Application.h"

//-----------------------------------------------------------------------------
// QnxApplication
//-----------------------------------------------------------------------------
class QnxApplication : public Application
{
public:
    QnxApplication();

    virtual bool ProcessMessages() override;
};