# **Memory Address Parser: Tag & Offset Extractor**

## **Description**
This program extracts the **tag** and **offset** from a given **memory address** using bitwise operations. It is designed to help understand how memory addresses are broken down in cache memory systems.  

The program takes a **hexadecimal memory address** as input, isolates the **offset** (least significant 4 bits), and extracts the **tag** (remaining bits shifted right).  

## **How It Works**
- **Offset Extraction:** The last 4 bits of the address are extracted using a **bitwise AND** with `0xF`.
- **Tag Extraction:** The address is **shifted right by 4 bits** to remove the offset and isolate the tag.

## **Usage**
### **Running the Program with Command-Line Input**
If using a command-line environment (like GCC or GDB Online Compiler), compile and run the program as follows:

```
gcc main.c -o main
./main 12345678
```
Example Output:
```
12345678: offset: 8 - tag: 1234567
```

### **Running Without Arguments (Default Test Cases)**
If no argument is provided, the program runs with predefined test cases:

```sh
gcc main.c -o main
./main
```
Output:
```
[0x12345678] Offset: 8 - Tag: 1234567
[0x87654321] Offset: 1 - Tag: 8765432
```

## **Functions**
### **`unsigned int getOffset(unsigned int address)`**
Extracts the **offset** (last 4 bits) of the address.
```
unsigned int mask = 0xF;
unsigned int offset = address & mask;
return offset;
```
### **`unsigned int getTag(unsigned int address)`**
Extracts the **tag** (everything except the last 4 bits).
```
unsigned int tag = address >> 4;
return tag;
```

## **Example Calculations**
For `0x12345678`:
- Offset: `0x12345678 & 0xF` → `0x8`
- Tag: `0x12345678 >> 4` → `0x1234567`

For `0x87654321`:
- Offset: `0x87654321 & 0xF` → `0x1`
- Tag: `0x87654321 >> 4` → `0x8765432`

## **Why This Matters**
Understanding how memory addresses are divided into **tag, index, and offset** is crucial in **computer architecture and cache memory design**. This program demonstrates **basic bitwise operations** used in memory management.  

## **Future Improvements**
- Support for different address bit-widths.
- Option to extract **index** for cache line calculations.
- Interactive mode for user input.  
