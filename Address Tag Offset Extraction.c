#include <stdio.h>
#include <stdlib.h>

// getOffset function dependent on an unsigned int address
unsigned int getOffset(unsigned int address) {
	// int mask will isolate the least significant byte (LSB) of the address
	unsigned int mask = 0x0000000F;
	// The int offset ANDs the address and mask to isolate LSB
	unsigned int offset = address & mask;
	return offset;
}

// getTag function dependent on an unsigned int address
unsigned int getTag(unsigned int address) {
	// int tag shifts the address to the right by 4 bits to isolate the 7 most significant bytes (the tag)
	unsigned int tag = address >> 4;
	return tag;
}

int main(int argc,
         char *argv[]) {
    // If user inputs a value
	if (argc == 2) {
	    // String to unsigned int as a hexadecimal
		unsigned int a = strtoul(argv[1], NULL, 16);
		// getOffset of unsigned int a
		unsigned int o = getOffset(a);
		// getTag of unsigned int a
		unsigned int t = getTag(a);
		printf("%x: offset: %x - tag: %x\n", a, o, t);
	} else {
		// Expected -- Offset: 8 - Tag: 1234567
		printf("[0x12345678] Offset: %x - Tag: %x\n", getOffset(0x12345678), getTag(0x12345678));

		//Expected -- Offset: 1 - Tag: 8765432
		printf("[0x87654321] Offset: %x - Tag: %x\n", getOffset(0x87654321), getTag(0x87654321));
	}
}