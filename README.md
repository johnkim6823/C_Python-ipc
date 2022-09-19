# C_python_ipc

Author: Kiyoon Kim (yoonkr33@gmail.com, https://kiyoon.kim)  

Description: Message Queue based Interprocess Communication (IPC) between Python and C. There are sender and receiver code for each language.  

The senders will send:  
- string
- two doubles
- one array (or numpy)
- one double and one array (or numpy)

And the receivers receive the byte formatted data and unpack.


## Dependencies

- Python >= 3.6
- sysv_ipc (python package)
- numpy (python package)

For Python 2 support, see the older version: [v0.1](https://github.com/kiyoon/C_python_ipc/tree/v0.1)

## Usage

Build C programs

`make`

Run receiver. For example, C receiver:

`./receiver`

In a different terminal, execute sender. For example, Python sender with String, double (float64), numpy formats.

`./sender.py`

Watch what happens on the receiver!

## Example output
### sender.py
```
$ python3 sender.py
string size: VGA or HD
int fps: 30
string format YUV420
```

### receiver (C)
```
$ ./receiver
Raw data: 56 47 41 00 1E 00 00 00 59 55 56 34 32 30 00 00
SIZE: VGA
FPS: 30
FORMAT : YUV420
```

## References

http://weifan-tmm.blogspot.kr/2015/09/invoke-floating-point-logic-set-option_4.html  

http://forum.falinux.com/zbxe/index.php?document_srl=420147&mid=C_LIB

## ISSUE need to FIX

String length difference from SIZE and FORMAT
