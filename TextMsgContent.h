#ifndef TEXTMSGCONTENT_H
#define TEXTMSGCONTENT_H

#define EVENT_FUNCTIONS         1
#define DE_CONSTRUCT_FUNCTIOINS 1
#define PUBLIC_FUNCTIONS        1
#define PROTECTED_FUNCTIONS     1
#define PRIVATE_FUNCTIONS       1

#define MARGIN                  5


#include "MsgContent.h"

class QVBoxLayout;
class QLabel;
class QTextEdit;
class QGridLayout;

class TextMsgContent : public MsgContent
{
public:
    TextMsgContent(QString &content, QWidget *parent = 0);

    //重写父类提供的方法
    void setMaximumWidth(int maxw);

protected:
    void paintEvent(QPaintEvent *);

protected:
    void initContentControl();
private:
    QLabel *m_pContentLabel;
    QTextEdit *m_pContentTextEdit;
    QGridLayout *m_pMainLayout;
    QString m_styleSheetStr;
};

#endif // TEXTMSGCONTENT_H
