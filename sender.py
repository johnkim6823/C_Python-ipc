#!/usr/bin/env python3
# http://weifan-tmm.blogspot.kr/2015/07/a-simple-turorial-for-python-c-inter.html
import sysv_ipc
import struct

BUFF_SIZE = 8
INT_SIZE = 4

from type_definitions import *

if __name__ == '__main__':
        
    msg_size = VGA
    msg_fps = 30
    msg_format = YUV420
    print(VGA)
    print(YUV420)
    try:
        mq = sysv_ipc.MessageQueue(1234, sysv_ipc.IPC_CREAT)
        
        # by HEADER
        header = bytearray(6)
        fmt_str = "<BBi" 
        struct.pack_into(fmt_str, header, 0, 0x01, 0x21, msg_fps) 
        print (header)
        mq.send(header, True, type=TYPE_CAMERA_CFG)


    except sysv_ipc.ExistentialError:
        print("ERROR: message queue creation failed")


