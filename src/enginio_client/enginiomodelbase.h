/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtEnginio module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef ENGINIOMODELBASE_H
#define ENGINIOMODELBASE_H

#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qscopedpointer.h>

#include <Enginio/enginioclientbase.h>

QT_BEGIN_NAMESPACE

class EnginioModelBasePrivate;
class ENGINIOCLIENT_EXPORT EnginioModelBase : public QAbstractListModel
{
    Q_OBJECT
    Q_ENUMS(EnginioClientBase::Operation) // TODO remove me QTBUG-33577
    Q_PROPERTY(EnginioClientBase::Operation operation READ operation WRITE setOperation NOTIFY operationChanged)

public:
    explicit EnginioModelBase(EnginioModelBasePrivate &dd, QObject *parent);
    ~EnginioModelBase();

    enum Roles {
        InvalidRole = -1,
        SyncedRole = Qt::UserRole + 1,
        CreatedAtRole,
        UpdatedAtRole,
        IdRole,
        ObjectTypeRole,
        LastRole = Qt::UserRole + 10 // the first fully dynamic role
    };

    EnginioClientBase::Operation operation() const Q_REQUIRED_RESULT;
    void setOperation(EnginioClientBase::Operation operation);

    virtual Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) Q_DECL_OVERRIDE;

    virtual void fetchMore(const QModelIndex &parent) Q_DECL_OVERRIDE;
    virtual bool canFetchMore(const QModelIndex &parent) const Q_DECL_OVERRIDE;

    virtual QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;

    void disableNotifications();
Q_SIGNALS:
    void operationChanged(EnginioClientBase::Operation operation);

private:
    Q_DISABLE_COPY(EnginioModelBase)
    Q_DECLARE_PRIVATE(EnginioModelBase)
    friend class EnginioModelPrivate;
};


QT_END_NAMESPACE


#endif // ENGINIOMODELBASE_H
