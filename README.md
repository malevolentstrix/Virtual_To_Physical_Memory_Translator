# VIRTUAL-TO-PHYSICAL-MEMORY-TRANSLATOR
  
## Designing a Virtual Memory Translator  
### OS PROJECT FOR 3RD SEMESTER  
The goal of this project is to develop the application that converts logical addresses to physical addresses for a virtual address space of 216 = 65,536 bytes. The implementation will read logical addresses from a file, translate each logical address to its matching physical address using a TLB and a page table, then output the value of the byte stored at the translated physical location. This project's purpose is to emulate the stages involved in converting logical addresses to physical addresses.
#### SPECIFICS  
A file containing various 32-bit integer integers that represent logical addresses will be read by the application. However, you only need to worry about 16-bit addresses, thus the rightmost 16 bits of each logical address must be masked. The 16 bits are split into two parts: an 8-bit page number and an 8-bit page offset.

#### ADDRESS TRANSLATION  
Using a TLB and page table, the software will convert logical to physical addresses. The TLB is accessed after extracting the page number from the logical address. The frame number is received from the TLB in the case of a TLB-hit. The page table must be examined in the event of a TLB-miss. Either the frame number is taken from the page table or a page fault occurs in the latter instance.

#### Test File:  
There should be a file named 'addresses.txt' that includes integer values representing logical addresses ranging from 0 to 65,536. (the size of the virtual address space). This file will be opened by the code, which will read each logical address and translate it to its physical address, then output the value of the signed byte at the physical location. 


#### How to Run Your Program:
'gcc translator.c -o translator addresses.txt >' should be used to run the programme.
The file addresses.txt will be read into the application, which includes 1,000 logical addresses ranging from 0 to 65535.
The program's goal is to convert each logical address to a physical address and then determine the contents of the signed byte stored at that physical address. (Hint: the char data type in C takes up a byte of memory, so we recommend using char values.)
The following values are to be produced by the programme:
1. The logical address that is being converted (the integer value being read from addresses.txt).
2. The physical address of the corresponding location (what your programme translates the logical address to).
3. At the translated physical address, the signed byte value is saved.
