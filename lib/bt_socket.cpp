/**
    Copyright: zirexix 2016

    This program is distributed
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

    This program, or portions of it cannot be used in commercial
    products without the written consent of the author: marrius9876@gmail.com

*/

#include "uguid.h"

#include "hci_socket.h"
#include "bu_hci.h"
#include "libbungetpriv.h"
#ifndef TRACE_H_
#include "trace.h"
#endif

/****************************************************************************************
*/
typedef enum
{
    BT_IO_L2CAP,
    BT_IO_RFCOMM,
    BT_IO_SCO,
    BT_IO_INVALID,
} BtIOType;

/****************************************************************************************
*/
bt_socket::~bt_socket()
{
    close();
}

/****************************************************************************************
*/
void bt_socket::close()
{
    if(_sock>0)
    {
        ::close(_sock);
        _sock = 0;
    }
}

/****************************************************************************************
*/
int bt_socket::read(uint8_t* buffer, int sizeb)
{
    return ::read(this->_sock, buffer, sizeb);
}

/****************************************************************************************
*/
int bt_socket:: writeocts(const uint8_t* buffer, int sizeb)
{

    bybuff  data(buffer,sizeb);
    int r = ::write(this->_sock, buffer, sizeb);
    if(is_tracing(kTraceGory)) TRACE("\n<--[" <<int(data.length())<<"/"<<r<<"]" << data.to_string());
    ::fsync(this->_sock);
	return r;
}
