#ifndef SCRIPTENGINE_H
#define SCRIPTENGINE_H
#pragma once
#include <string>
#include "historymanager.h"
#include "../types/number.h"
class ScriptEngine
{
public:
    ScriptEngine(HistoryManager& hm);
    Number runScript(const std::string& expression);

private:
    HistoryManager& historyManager;
};

#endif // SCRIPTENGINE_H
