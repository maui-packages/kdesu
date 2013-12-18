/*
 * This file is part of the KDE project, module kdesu
 * Copyright (C) 1999,2000 Geert Jansen <jansen@kde.org>
 *
 * This is free software; you can use this library under the GNU Library
 * General Public License, version 2. See the file "COPYING.LIB" for the
 * exact licensing terms.
 */

#ifndef KDESUKCOOKIE_H
#define KDESUKCOOKIE_H

#include <QtCore/QByteRef>

#include <config-kdesu.h>

namespace KDESu {

namespace KDESuPrivate {

/**
 * Utility class to access the authentication tokens needed to run a KDE
 * program (X11 cookies on X11, for instance).
 * @internal
 */

class KCookie
{
public:
    KCookie();
    ~KCookie();

    /**
     * Returns the X11 display.
     */
    QByteArray display() const;

#if HAVE_X11
    /**
     * Returns the X11 magic cookie, if available.
     */
    QByteArray displayAuth() const;
#endif

private:
    void getXCookie();

    class KCookiePrivate;
    KCookiePrivate * const d;
};

}}

#endif // KDESUKCOOKIE_H
