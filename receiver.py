#!/usr/bin/env python3
# http://weifan-tmm.blogspot.kr/2015/07/a-simple-turorial-for-python-c-inter.html
import sysv_ipc
import struct

from type_definitions import *
SIZEOF_FLOAT = 8

try:
    mq = sysv_ipc.MessageQueue(1234, sysv_ipc.IPC_CREAT)

    while True:
        message, mtype = mq.receive()
        print("*** New message received ***")
        print(f"Raw message: {message}")
        
        if mtype == TYPE_CAMERA_CFG:
            camera_cfg_recv = struct.unpack("BBi", message)
            print(f"Interpret as BBi: {camera_cfg_recv}")

except sysv_ipc.ExistentialError:
    print("ERROR: message queue creation failed")
