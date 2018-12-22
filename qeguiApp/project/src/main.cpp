/*  main.cpp
 *
 *  This file is part of the EPICS QT Framework, initially developed at the
 *  Australian Synchrotron.
 *
 *  Copyright (c) 2009-2018 Australian Synchrotron
 *
 *  The EPICS QT Framework is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  The EPICS QT Framework is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with the EPICS QT Framework.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Author:
 *    Andrew Rhyder
 *  Contact details:
 *    andrew.rhyder@synchrotron.org.au
 */

#include <QtGlobal>
#include <QApplication>
#include <QEGui.h>

//------------------------------------------------------------------------------
//
int main(int argc, char *argv[])
{
    // Intercept help/verson arguments before QApplication created.
    //
    if (argc >= 2) {
        const QString firstArg (argv[1]);

        if ((firstArg == "-h") || (firstArg == "--help")) {
            QEGui::printHelp();
            return 0;
        }

        if ((firstArg == "-v") || (firstArg == "--version")) {
            QEGui::printVersion();
            return 0;
        }
    }

#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
    // Avoid Qt WebEngine seems to be initialized from a plugin warning.
    QCoreApplication::setAttribute( Qt::AA_ShareOpenGLContexts );
#endif

    QEGui* app = new QEGui( argc, argv );
    int ret = app->run();
    delete app;
    return ret;
}

// end
