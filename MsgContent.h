#ifndef MSGCONTENT_H
#define MSGCONTENT_H

#include <QWidget>

class QBoxLayout;
class MsgContent : public QWidget
{
    Q_OBJECT
public:
    explicit MsgContent(QWidget *parent = 0);
    MsgContent(QString content, QWidget *parent = 0);

signals:

public slots:

protected:
    QString m_content;
    QBoxLayout *m_pMainVLayout;
};

#endif // MSGCONTENT_H
