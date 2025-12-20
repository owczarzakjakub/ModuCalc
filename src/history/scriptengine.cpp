#include "scriptengine.h"
#include "../core/parser.h"
#include "../core/lexer.h"

ScriptEngine::ScriptEngine(HistoryManager& hm):historyManager(hm) {}
    Number ScriptEngine::runScript(const std::string& expression){
        Lexer lexer;
        Parser parser;

        auto tokens=lexer.tokenize(expression);
        auto parsed=parser.parse(tokens);

        Number dummyResult(0);
        historyManager.addEntry(expression,dummyResult);
        return dummyResult;
    }

