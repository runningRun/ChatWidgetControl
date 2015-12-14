#ifndef CHATWIDGETCTRL_H
#define CHATWIDGETCTRL_H

#include <QWidget>
class QScrollArea;
class ChatWidget;
class QVBoxLayout;

class QPushButton;
class QCheckBox;
class QTextEdit;
class QBoxLayout;

class ChatWidgetCtrl : public QWidget
{
    Q_OBJECT
public:
    explicit ChatWidgetCtrl(QWidget *parent = 0);
    ~ChatWidgetCtrl();

    void addNewChatWidget(QString data);

protected:
    void resizeEvent(QResizeEvent* );
private:
    void initInputWidget();
signals:

public slots:

private slots:
    void inputWidgtBtnClicked(bool);

private:
    QScrollArea *m_pScrollArea;
    ChatWidget *m_pChatWidget;
    QBoxLayout *m_pMainLayout;

    /*
     * zwl 2015.12.12
     * 注，以下所创建的组件，只是为了测试输入
     */
    QWidget *m_pInputWidget;
    QPushButton *m_pInputWidgetBtn;
    QCheckBox *m_pInputWidgetCheckBox;
    QTextEdit *m_pInputWidgetTextEdit;
    QTextEdit *m_pInputWidgetStyleTestTextEdit;
    QVBoxLayout *m_pInputWidgetLayout;
};

#endif // CHATWIDGETCTRL_H
