#include "ChatWidget.h"
#include <QPixmap>
#include <QVBoxLayout>
#include <QDebug>
#include "globalvar.h"
#include "ChatWidgetItem.h"
ChatWidget::ChatWidget(QWidget *parent) :
    QWidget(parent)
{
    initComponent();
}

ChatWidget::ChatWidget(QString data, QWidget *parent)
{
    initComponent();
}

void ChatWidget::addNewChatWidgetItem(QString msgContent, bool isFromAgent)
{
    /*
     * QPixmap *headPixmap, const QString &nickName,
     * MSGTYPE msgtype, QString msgContent,
     * bool isFromAgent, QWidget *parent = 0
    */
    ChatWidgetItem*  newItem = new ChatWidgetItem(this->m_pAgetnHeadPixmap, QString("NickName"), TEXT, msgContent, isFromAgent, this);
    qDebug() << "ChatWidget::addNewChatWidgetItem newItem " << newItem << " size:" << newItem->size();
    this->m_pMainLayout->addWidget(newItem);
    this->m_pMainLayout->setAlignment(newItem, Qt::AlignTop);
}

void ChatWidget::initComponent()
{
    this->m_pAgetnHeadPixmap = new QPixmap("./res/agent.png");
    this->m_pCustomerHeadPixmap = new QPixmap("./res/customer.png");
    this->m_pChatWidgetItemList = new QList<ChatWidgetItem*>();
    this->m_pMainLayout = new QVBoxLayout(this);
    this->setLayout(this->m_pMainLayout);
}

ChatWidget::~ChatWidget()
{
    ChatWidgetItem *item;
    while (!m_pChatWidgetItemList->isEmpty()) {
        item = this->m_pChatWidgetItemList->last();
        this->m_pChatWidgetItemList->removeLast();
        delete item;
        item = NULL;
    }
    delete this->m_pChatWidgetItemList;
    this->m_pChatWidgetItemList = NULL;
    delete this->m_pCustomerHeadPixmap;
    this->m_pCustomerHeadPixmap = NULL;
    delete this->m_pAgetnHeadPixmap;
    this->m_pAgetnHeadPixmap = NULL;
    delete this->m_pMainLayout;
    this->m_pMainLayout = NULL;
}

