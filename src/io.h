/******************************************************************************
**
** Copyright (C) 2014 BIMEtek Co. Ltd.
**
** This file is part of QUSB.
**
** QUSB is free software: you can redistribute it and/or modify it under the
** terms of the GNU Lesser General Public License as published by the Free
** Software Foundation, either version 3 of the License, or (at your option)
** any later version.
**
** QUSB is distributed in the hope that it will be useful, but WITHOUT ANY
** WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
** FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
** details.
**
** You should have received a copy of the GNU General Public License along with
** this file. If not, see <http://www.gnu.org/licenses/>.
**
******************************************************************************/

#ifndef QUSB_IO_H
#define QUSB_IO_H

#include <QIODevice>
#include "global.h"

namespace QUSB
{

class DeviceHandle;
class IOPrivate;

class QUSB_SHARED_EXPORT IO : public QIODevice
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(IO)

protected:
    IOPrivate *d_ptr;
    IO(IOPrivate *d, QObject *parent = nullptr);

public:
    explicit IO(DeviceHandle *handle, QObject *parent = nullptr);
    virtual ~IO() override;

    DeviceHandle * getDeviceHandle();
    virtual bool open(QIODevice::OpenMode openMode) override;
    virtual void close() override;
    bool isSequential() const override;
    qint64 bytesToWrite() const override;
    qint64 bytesAvailable() const override;

    // QIODevice interface
protected:
    qint64 readData(char *data, qint64 maxlen) override;
    qint64 writeData(const char *data, qint64 len) override;

};

}   // namespace QUSB

#endif // QUSB_IO_H
