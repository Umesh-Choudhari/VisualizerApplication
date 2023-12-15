#include "stdafx.h"
#include "SymmetricDDAandSutherLandCohen.h"
#include <QtWidgets/QApplication>
using namespace symmetricDDAandSutherlandCohen;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SymmetricDDAandSutherLandCohen w;
    w.show();
    return a.exec();
}
