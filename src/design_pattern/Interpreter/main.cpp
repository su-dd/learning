#include "ImgExpression.h"
#include "PhoneExpression.h"
#include "PlusOperation.h"
#include "ValueExpression.h"
#include "WeblinkExpression.h"
#include "Context.h"
#include <string>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    Context oContext;
    oContext.assign("Img", "img王小二照片");
    oContext.assign("p", "13579");

    PlusOperation oPlus1(new ImgExpression(new ValueExpression("Img")), new PhoneExpression(new ValueExpression("p")));

    cout << oPlus1.interprete(oContext);

    return 0;
}
