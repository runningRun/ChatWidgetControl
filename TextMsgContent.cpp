#include "TextMsgContent.h"
#include "globalvar.h"
#include <QPaintEvent>
#include <QLabel>
#include <QTextEdit>
#include <QGridLayout>
#include <QApplication>
#include <QDebug>

//构造析构函数区
#if DE_CONSTRUCT_FUNCTIOINS

TextMsgContent::TextMsgContent(QString &content, QWidget *parent)
{
    this->setParent(parent);

    if (NULL != this->parentWidget())
    {
        this->setMaximumWidth( this->parentWidget()->width() - HEAD_PIXMAP_WIDTH - CHILD_LAYOUT_MARGIN);
    }

    this->m_styleSheetStr = "border:2px groove green;border-radius:10px;padding:2px 4px;";
    this->m_pContentTextEdit = new QTextEdit(content, this);
    this->m_pMainLayout = new QGridLayout(this);
    this->setLayout(this->m_pMainLayout);
    this->m_content = content;

    initContentControl();
}

#endif  //DE_CONSTRUCTION_FUNCTIONS

//public访问权限函数
#if PUBLIC_FUNCTIONS

void TextMsgContent::setMaximumWidth(int maxw)
{
}

#endif  //PUBLIC_FUNCTIONS

//protected访问权限函数
#if PROTECTED_FUNCTIONS

void TextMsgContent::initContentControl()
{
    this->m_pContentTextEdit->hide();
    this->m_pMainLayout->setMargin(LAYOUT_MARGIN_ZERO);



    this->m_pContentTextEdit->setStyleSheet(this->m_styleSheetStr);
    this->m_pContentTextEdit->setReadOnly(true);
    this->m_pContentTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->m_pContentTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    int contetWidth = this->m_pContentTextEdit->fontMetrics().width(this->m_content);
    int contentHMargins =  this->m_pContentTextEdit->contentsMargins().left() - this->m_pContentTextEdit->contentsMargins().right();
    qDebug() << "TextMsgContent::initContentControl contentWidth: " << contetWidth << "contentHMargins: " << contentHMargins << "size: " << this->size();
    if (contetWidth > (this->maximumWidth() -contentHMargins))
    {/*
        this->m_pContentTextEdit->setMinimumWidth(this->maximumWidth() - contentHMargins);
        this->m_pContentTextEdit->setMaximumWidth(this->maximumWidth() - contentHMargins);*/
        this->m_pContentTextEdit->setFixedWidth(this->maximumWidth() - contentHMargins);
    }
    else
    {
        int tmpWidth = contetWidth + contentHMargins + 8;
        this->m_pContentTextEdit->setMaximumWidth(tmpWidth);
        this->m_pContentTextEdit->setMinimumWidth(tmpWidth);
    }

    this->m_pContentTextEdit->show();
    qDebug() << "m_pContentTextEdit document size" << this->m_pContentTextEdit->document()->size().toSize();
    this->m_pMainLayout->addWidget(this->m_pContentTextEdit);
    this->setMaximumSize(this->m_pMainLayout->sizeHint());
    this->setMinimumSize(this->m_pMainLayout->sizeHint());
}

#endif  //PROTECTED_FUNCTIONS

//重写事件函数区
#if EVENT_FUNCTIONS

void TextMsgContent::paintEvent(QPaintEvent *paintEvent)
{
}

#endif  //EVENT_FUNCTIONS
