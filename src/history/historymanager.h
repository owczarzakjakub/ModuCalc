#pragma once
#ifndef HISTORYMANAGER_H
#define HISTORYMANAGER_H
#include <vector>
#include <string>
#include "../types/number.h"

class HistoryManager
{
public:
    HistoryManager();
    void addEntry(const std::string& expression, const Number& result);
    std::pair<std::string,Number> getLastEntry() const;
    std::vector<std::pair<std::string, Number>> getAll() const;

private:
    std::vector<std::pair<std::string, Number>> history;
};

#endif // HISTORYMANAGER_H
