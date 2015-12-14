#include "ChatWidgetCtrl.h"
#include "ChatWidget.h"
#include "globalvar.h"
#include <QResizeEvent>
#include <QMargins>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QDebug>

#include <QPushButton>
#include <QCheckBox>
#include <QTextEdit>
#include <QVBoxLayout>

ChatWidgetCtrl::ChatWidgetCtrl(QWidget *parent) :
    QWidget(parent)
{
    this->m_pScrollArea = new QScrollArea(this);
    this->m_pScrollArea->setGeometry(this->rect());
    this->m_pScrollArea->setWidgetResizable(true);

    QVBoxLayout* tmpLayout = new QVBoxLayout(this->m_pScrollArea);
    tmpLayout->setMargin(LAYOUT_MARGIN_ZERO);
    this->m_pScrollArea->setLayout(tmpLayout);

    this->m_pChatWidget = new ChatWidget(this);
    this->m_pScrollArea->setWidget(this->m_pChatWidget);

    this->m_pMainLayout = new QVBoxLayout(this);
    this->m_pMainLayout->setMargin(LAYOUT_MARGIN_ZERO);
    this->m_pMainLayout->addWidget(this->m_pScrollArea);
    this->setLayout(this->m_pMainLayout);

    this->setWindowState(Qt::WindowMaximized);

    qDebug() << "ChatWidgetCtrl::ChatWidgetCtrl size()" << this->size();
    qDebug() << "ChatWidgetCtrl::ChatWidgetCtrl m_pChatWidget " << this->m_pChatWidget << "size()" << this->m_pChatWidget->size();

    initInputWidget();
}

void ChatWidgetCtrl::addNewChatWidget(QString data)
{
}

void ChatWidgetCtrl::initInputWidget()
{
    this->m_pInputWidget = new QWidget();
    this->m_pInputWidgetBtn = new QPushButton("确定", this->m_pInputWidget);
    this->m_pInputWidgetCheckBox = new QCheckBox("坐席", this->m_pInputWidget);
    this->m_pInputWidgetTextEdit = new QTextEdit("Hello QTextEdit Hello QTextEdit 接天莲叶无穷碧，映日荷花别样红", this->m_pChatWidget);
    this->m_pInputWidgetStyleTestTextEdit = new QTextEdit(this->m_pInputWidget);
    this->m_pInputWidgetLayout = new QVBoxLayout(this->m_pInputWidget);

    this->m_pInputWidgetStyleTestTextEdit->setStyleSheet("border:2px groove green;border-radius:10px;padding:2px 4px;");
    this->m_pInputWidgetStyleTestTextEdit->setReadOnly(true);


    connect(this->m_pInputWidgetBtn, SIGNAL(clicked(bool)),
            this, SLOT(inputWidgtBtnClicked(bool)));

    this->m_pInputWidgetLayout->addWidget(this->m_pInputWidgetBtn);
    this->m_pInputWidgetLayout->addWidget(this->m_pInputWidgetCheckBox);
    this->m_pInputWidgetLayout->addWidget(this->m_pInputWidgetTextEdit);
    this->m_pInputWidgetLayout->addWidget(this->m_pInputWidgetStyleTestTextEdit);
    this->m_pInputWidget->setLayout(this->m_pInputWidgetLayout);
    this->m_pInputWidget->setWindowTitle("InputWidget");
    this->m_pInputWidget->show();
}

void ChatWidgetCtrl::inputWidgtBtnClicked(bool clicked)
{
    this->m_pInputWidgetStyleTestTextEdit->hide();

    this->m_pChatWidget->addNewChatWidgetItem(this->m_pInputWidgetTextEdit->toPlainText(), this->m_pInputWidgetCheckBox->isChecked());
    this->m_pInputWidgetStyleTestTextEdit->setText(this->m_pInputWidgetTextEdit->toPlainText());
//    this->m_pInputWidgetStyleTestTextEdit->setFixedSize(this->m_pInputWidgetStyleTestTextEdit->sizeHint());

    qDebug() << "ChatWidgetCtrl::ChatWidgetCtrl m_pInputWidgetStytleTestTextEdit Document size" << this->m_pInputWidgetStyleTestTextEdit->document()->size();
    this->m_pInputWidgetStyleTestTextEdit->setFixedHeight(this->m_pInputWidgetStyleTestTextEdit->document()->size().height() + this->m_pInputWidgetStyleTestTextEdit->contentsMargins().top() * 2);
    this->m_pInputWidgetStyleTestTextEdit->show();
    qDebug() << "ChatWidgetCtrl::ChatWidgetCtrl size()" << this->size();
    qDebug() << "ChatWidgetCtrl::ChatWidgetCtrl m_pChatWidget " << this->m_pChatWidget << "size()" << this->m_pChatWidget->size();
}

void ChatWidgetCtrl::resizeEvent(QResizeEvent *resizeEvent)
{
    QWidget* tmpWidget = this->m_pScrollArea->widget();
    if (NULL != tmpWidget)
    {
        qDebug() << "ChatWidgetCtrl::resizeEvent m_pScrollArea's widget " << tmpWidget << " size: " << tmpWidget->size();
        tmpWidget->resize(this->m_pScrollArea->width() - 17, this->m_pScrollArea->height() - 17);
    }
    qDebug() << "ChatWidgetCtrl::resizeEvent size()" << this->size();
    qDebug() << "ChatWidgetCtrl::resizeEvent m_pScrollArea " << this->m_pScrollArea << "size()" << this->m_pScrollArea->size();
    qDebug() << "ChatWidgetCtrl::resizeEvent m_pChatWidget " << this->m_pChatWidget << "size()" << this->m_pChatWidget->size();
}

ChatWidgetCtrl::~ChatWidgetCtrl()
{
    delete this->m_pScrollArea;
}

