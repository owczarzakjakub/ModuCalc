#include "historymanager.h"

#include <stdexcept>

HistoryManager::HistoryManager() {}
void HistoryManager::addEntry(const std::string& expression,const Number& result){
    history.push_back({expression,result});
}
std::pair<std::string,Number> HistoryManager::getLastEntry() const{
    if(history.empty()){
        throw std::runtime_error("Brak wpisów w historii");
    }
    return history.back();
}

std::vector<std::pair<std::string,Number>> HistoryManager::getAll() const{
    return history;
}
