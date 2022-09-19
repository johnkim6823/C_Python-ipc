#!/usr/bin/env python3
# http://weifan-tmm.blogspot.kr/2015/07/a-simple-turorial-for-python-c-inter.html
import sysv_ipc
import numpy as np
import struct

BUFF_SIZE = 8
INT_SIZE = 4

from type_definitions import *

if __name__ == '__main__':
        
    msg_size = "VGA\0"
    msg_fps = 30
    msg_format = "YUV420\0"
    
    try:
        mq = sysv_ipc.MessageQueue(1234, sysv_ipc.IPC_CREAT)
        
        # by HEADER
        header_size = len(msg_size) + INT_SIZE + len(msg_format)
        header = bytearray(header_size)
        fmt_str = f"<{len(msg_size)}si{len(msg_format)}s" 
        struct.pack_into(fmt_str, header, 0, bytes(msg_size, 'utf-8'), msg_fps, bytes(msg_format, 'utf-8')) 
        print (header)
        mq.send(header, True, type=TYPE_CAMERA_CFG)


    except sysv_ipc.ExistentialError:
        print("ERROR: message queue creation failed")


