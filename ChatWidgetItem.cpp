#include "ChatWidgetItem.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTextEdit>
#include <QDebug>
#include "TextMsgContent.h"
#include "VoiceMsgContent.h"
#include "VideoMsgContent.h"
#include "ImageMsgContent.h"

const QString ChatWidgetItem::styleSheetStr = "";

//构造、析构函数
#if DE_CONSTRUCT_FUNCTIONS

ChatWidgetItem::ChatWidgetItem(QWidget *parent) : QWidget(parent)
{

}

ChatWidgetItem::ChatWidgetItem(QPixmap *headPixmap, const QString &nickName, MSGTYPE msgtype, QString msgContent, bool isFromAgent, QWidget *parent) :
    QWidget(parent),
    m_rightFlag(isFromAgent)
{
    /*
    this->m_pHeadPixLabel = new QLabel(this);
    this->m_pHeadPixLabel->setPixmap((*headPixmap));
    this->m_pHeadPixLabel->setFixedSize(64, 64);

    this->m_pNickNameLabel = new QLabel(nickName, this);
    this->m_pNickNameLabel->adjustSize();
    QPalette pale;
    pale.setColor(QPalette::Window, QColor (126, 45, 92));
    this->m_pNickNameLabel->setPalette(pale);
    this->m_pNickNameLabel->setAutoFillBackground(true);
    this->m_pNickNameLabel->setFixedSize(this->m_pNickNameLabel->sizeHint());

    this->m_pMainLayout = new QHBoxLayout(this);
    this->m_pNickName_ContentLayout = new QVBoxLayout(this);
    this->m_pHeadPixLayout = new QHBoxLayout(this);

    this->setStyleSheet(ChatWidgetItem::styleSheetStr);

    if (NULL != this->parentWidget())
    {
        this->setFixedWidth(this->parentWidget()->width() - (2 * MARGIN) - (2 * LINE_WIDTH) - 4);
    }
    switch (msgtype) {
    case TEXT:
        this->m_pMsgContent = new TextMsgContent(msgContent, this);
        break;
    case VOICE:
        this->m_pMsgContent = new VoiceMsgContent(msgContent, this);
        break;
    case VIDEO:
        this->m_pMsgContent = new VideoMsgContent(msgContent, this);
        break;
    case PICTURE:
        this->m_pMsgContent = new ImageMsgContent(msgContent, this);
        break;
    default:
        break;
    }

    this->m_pNickName_ContentLayout->addWidget(this->m_pNickNameLabel);
    this->m_pNickName_ContentLayout->addWidget(this->m_pMsgContent);

    if (isFromAgent)
    {
        //消息来自坐席
        this->m_pNickNameLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        this->m_pMainLayout->addLayout(this->m_pNickName_ContentLayout);
        this->m_pMainLayout->addWidget(this->m_pHeadPixLabel);
    }
    else
    {
        this->m_pNickNameLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        this->m_pMainLayout->addWidget(this->m_pHeadPixLabel);
        this->m_pMainLayout->addLayout(this->m_pNickName_ContentLayout);
    }

    this->setLayout(this->m_pMainLayout);
    */

    qDebug() << "ChatWidgetItem::ChatWidgetItem, Parent " << this->parentWidget() << " size:" << this->parentWidget()->size();

    if (NULL != this->parentWidget())
    {
        this->setFixedWidth(this->parentWidget()->width() - (2 * CHILD_LAYOUT_MARGIN) - (2 * LINE_WIDTH) - 8);
    }

    this->m_pHeadPixLabel = new QLabel(this);
    this->m_pHeadPixLabel->setPixmap((*headPixmap));
    this->m_pHeadPixLabel->setFixedSize(HEAD_PIXMAP_WIDTH, HEAD_PIXMAP_HEIGHT);

    this->m_pNickNameLabel = new QLabel(nickName, this);
    this->m_pNickNameLabel->adjustSize();

    this->m_pMainLayout = new QHBoxLayout(this);
    this->m_pMainLayout->setMargin(CHILD_LAYOUT_MARGIN);
    this->m_pMainLayout->setSpacing(2);

    this->m_pHeadPixLayout = new QHBoxLayout(this);
    this->m_pHeadPixLayout->setMargin(0);
    this->m_pHeadPixLayout->setSpacing(0);

    this->m_pRightLayout = new QGridLayout(this);
    this->m_pRightLayout->setMargin(0);
    this->m_pRightLayout->setSpacing(0);

    this->setAutoFillBackground(true);
    this->setStyleSheet(ChatWidgetItem::styleSheetStr);

    switch (msgtype) {
    case TEXT:
        this->m_pMsgContent = new TextMsgContent(msgContent, this);
        break;
    case VOICE:
        this->m_pMsgContent = new VoiceMsgContent(msgContent, this);
        break;
    case VIDEO:
        this->m_pMsgContent = new VideoMsgContent(msgContent, this);
        break;
    case PICTURE:
        this->m_pMsgContent = new ImageMsgContent(msgContent, this);
        break;
    default:
        break;
    }

    this->m_pHeadPixLayout->addWidget(this->m_pHeadPixLabel);
    if (isFromAgent)
    {
        //消息来自坐席
        this->m_pNickNameLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        this->m_pRightLayout->addWidget(this->m_pNickNameLabel, 1, 1, 1, 1, Qt::AlignRight);
        this->m_pRightLayout->addWidget(this->m_pMsgContent, 2, 1, 1, 1, Qt::AlignRight);
        this->m_pMainLayout->addLayout(this->m_pRightLayout);
        this->m_pMainLayout->addLayout(this->m_pHeadPixLayout);
    }
    else
    {
        this->m_pNickNameLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        this->m_pRightLayout->addWidget(this->m_pNickNameLabel, 1, 1, 1, 1, Qt::AlignLeft);
        this->m_pRightLayout->addWidget(this->m_pMsgContent, 2, 1, 1, 1, Qt::AlignLeft);
        this->m_pMainLayout->addLayout(this->m_pHeadPixLayout);
        this->m_pMainLayout->addLayout(this->m_pRightLayout);
    }

    this->m_pMainLayout->setAlignment(this->m_pHeadPixLayout, Qt::AlignTop);
    this->setLayout(this->m_pMainLayout);
    this->setFixedSize(this->m_pMainLayout->sizeHint());
}

ChatWidgetItem::~ChatWidgetItem()
{

}

#endif //DE_CONSTRUCT_FUNCTIONS

