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

#ifndef ENGINIOSTRING_P_H
#define ENGINIOSTRING_P_H

#include "enginioclient_global.h"
#include <QtCore/qstring.h>

#define FOR_EACH_ENGINIO_STRING(F)\
    F(_synced, "_synced")\
    F(_delete, "delete")\
    F(access, "access")\
    F(apiEnginIo, "https://api.engin.io")\
    F(apiRequestId, "apiRequestId")\
    F(authIdentity, "auth/identity")\
    F(complete, "complete")\
    F(count, "count")\
    F(create, "create")\
    F(createdAt, "createdAt")\
    F(data, "data")\
    F(empty, "empty")\
    F(event, "event")\
    F(expiringUrl, "expiringUrl")\
    F(file, "file")\
    F(fileName, "fileName")\
    F(files, "files")\
    F(headers, "headers")\
    F(id, "id")\
    F(include, "include")\
    F(incomplete, "incomplete")\
    F(length, "length")\
    F(limit, "limit")\
    F(member, "member")\
    F(members, "members")\
    F(message, "message")\
    F(messageType, "messageType")\
    F(object, "object")\
    F(objectType, "objectType")\
    F(objectTypes, "objectTypes")\
    F(offset, "offset")\
    F(origin, "origin")\
    F(pageSize, "pageSize")\
    F(password, "password")\
    F(payload, "payload")\
    F(propertyName, "propertyName")\
    F(query, "query")\
    F(results, "results")\
    F(search, "search")\
    F(session, "session")\
    F(sessionToken, "sessionToken")\
    F(sort, "sort")\
    F(stagingEnginIo, "https://staging.engin.io")\
    F(status, "status")\
    F(targetFileProperty, "targetFileProperty")\
    F(update, "update")\
    F(updatedAt, "updatedAt")\
    F(url, "url")\
    F(usergroups, "usergroups")\
    F(username, "username")\
    F(users, "users")\
    F(variant, "variant")\

#define FOR_EACH_ENGINIO_BYTEARRAY(F)\
    F(XRequestId, "X-Request-Id")\
    F(Requested_object_operation_requires_non_empty_objectType_value, "Requested object operation requires non empty \'objectType\' value")\
    F(Requested_object_acl_operation_requires_non_empty_objectType_value, "Requested object acl operation requires non empty \'objectType\' value")\
    F(Requested_object_acl_operation_requires_non_empty_id_value, "Requested object acl operation requires non empty \'id\' value")\
    F(Download_operation_requires_non_empty_fileId_value, "Download operation requires non empty \'fileId\' value")\
    F(Requested_usergroup_member_operation_requires_non_empty_id_value, "Requested usergroup member operation requires non empty \'id\' value")\
    F(Requested_operation_requires_non_empty_id_value, "Requested operation requires non empty \'id\' value")\
    F(Enginio_Backend_Session, "Enginio-Backend-Session")\
    F(Delete, "DELETE")\
    F(Fulltext_Search_objectTypes_parameter_is_missing_or_it_is_not_an_array, "Fulltext Search: 'objectTypes' parameter is missing or it is not an array")\
    F(Fulltext_Search_search_parameter_missing, "Fulltext Search: 'search' parameter(s) missing")\
    F(Application_octet_stream, "application/octet-stream")\
    F(Minus, "-")\
    F(Div, "/")\
    F(EnginioModel_remove_row_is_out_of_range, "EnginioModel::remove: row is out of range")\
    F(EnginioModel_setProperty_row_is_out_of_range, "EnginioModel::setProperty: row is out of range")\
    F(Dependent_create_query_failed_so_object_could_not_be_removed, "Dependent create query failed, so object could not be removed")\
    F(Dependent_create_query_failed_so_object_could_not_be_updated, "Dependent create query failed, so object could not be updated")\
    F(EnginioModel_was_removed_before_this_request_was_prepared, "EnginioModel was removed before this request was prepared")\
    F(EnginioModel_The_query_was_changed_before_the_request_could_be_sent, "EnginioModel: The query was changed before the request could be sent")\
    F(EnginioModel_Trying_to_update_an_object_with_unknown_role, "EnginioModel: Trying to update an object with unknown role")\
    F(Content_Range, "Content-Range")\
    F(Get, "GET")


struct ENGINIOCLIENT_EXPORT EnginioString
{
#define DECLARE_ENGINIO_STRING(Name, String)\
    static const QString Name;

    FOR_EACH_ENGINIO_STRING(DECLARE_ENGINIO_STRING)
#undef DECLARE_ENGINIO_STRING


#define DECLARE_ENGINIO_BYTEARRAY(Name, String)\
    static const QByteArray Name;

    FOR_EACH_ENGINIO_BYTEARRAY(DECLARE_ENGINIO_BYTEARRAY)
#undef DECLARE_ENGINIO_BYTEARRAY
};


#endif // ENGINIOSTRING_P_H
