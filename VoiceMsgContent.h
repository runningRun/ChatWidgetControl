#ifndef VOICEMSGCONTENT_H
#define VOICEMSGCONTENT_H

#include "MsgContent.h"

class VoiceMsgContent : public MsgContent
{
public:
    VoiceMsgContent();
    VoiceMsgContent(QString &content, QWidget* parent = 0);
};

#endif // VOICEMSGCONTENT_H
