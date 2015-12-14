#include <QApplication>
#include "ChatWidgetCtrl.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    ChatWidgetCtrl chatWidget;
    chatWidget.show();

    return app.exec();
}
