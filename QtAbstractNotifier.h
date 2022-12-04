#ifndef QTABSTRACTNOTIFIER_H
#define QTABSTRACTNOTIFIER_H

#include <QObject>

/**
 * @class QtAbstractNotifier The interface for generic notification
 * @brief The class which contains properties for notifications such as
 *        hide, show notifications
 *
 * Each method returns a boolean indicating whether the notifications are
 * supported or not
 */

class QtAbstractNotifier : public QObject
{
    Q_OBJECT

public:
    virtual bool show(const QVariant &notificationParameters) = 0;
};

#endif // QTABSTRACTNOTIFIER_H
