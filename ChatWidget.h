#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>

class ChatWidgetItem;
class QPixmap;
class QVBoxLayout;

class ChatWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ChatWidget(QWidget *parent = 0);
    ChatWidget(QString data, QWidget *parent = 0);
    ~ChatWidget();

    void addNewChatWidgetItem(QString msgContent, bool isFromAgent);

private:
    void initComponent();
signals:

public slots:

private:
    QList<ChatWidgetItem*> *m_pChatWidgetItemList;
    QPixmap *m_pCustomerHeadPixmap;
    QPixmap *m_pAgetnHeadPixmap;
    QVBoxLayout *m_pMainLayout;
};

#endif // CHATWIDGET_H
