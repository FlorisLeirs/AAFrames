#pragma once

#include "args.hxx"

#include "CommonReplay.h"

#include <functional>
#include <memory>
#include <vector>

using FnParseResults = std::function<void(void)>;
using FnAddArgument = std::function<FnParseResults(args::ArgumentParser&)>;

inline std::vector<FnAddArgument>& GetExternalArguments()
{
    static std::vector<FnAddArgument> s_vecFnAddArgument;
    return s_vecFnAddArgument;
}

struct AutoRegisterArgument
{
    AutoRegisterArgument(const FnAddArgument& argument)
    {
        auto& vec = GetExternalArguments();
        vec.push_back(argument);
    }
};

#define REGISTER_ARGUMENTS(fnptr) static AutoRegisterArgument const NV_ANONYMOUS_VARIABLE(autoRegisterArgument, __LINE__)(fnptr)