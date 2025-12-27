#include "scriptengine.h"
#include "../core/lexer.h"
#include "../core/parser.h"
#include "../core/evaluator.h"
ScriptEngine::ScriptEngine(HistoryManager& hm):historyManager(hm) {}
    Number ScriptEngine::runScript(const std::string& expression){
        Lexer lexer;
        Parser parser;
        Evaluator evaluator;

        auto tokens=lexer.tokenize(expression);
        auto postfix=parser.parse(tokens);
        Number result=evaluator.evaluate(postfix);
        historyManager.addEntry(expression,result);
        return result;
    }

