#include "expression_utils.h"
#include <QRegularExpression>

namespace expression_utils {

QString sanitizeExpression(QString expr)
{
    expr = expr.trimmed();
    expr.replace("＋", "+");
    expr.replace("−", "-");
    expr.replace("–", "-");
    expr.replace("×", "*");
    expr.replace("÷", "/");
    expr.replace(QRegularExpression("\\s"), "");
    return expr;
}

}
