// Bitwise operators (5)

/**
 Bitwise AND (&)
 Bitwise OR  (|)
 Bitwise Complement/Negation Operator (~)
 Bitwise Left shift(<<) and right shift(>>) operators
 Bitwise XOR(^)
 */
#include <stdint.h>

unsigned char A, B, C;  // 8-bit number(1 byte)

int main() {
  // Bitwise AND
  A = 0x66;   // 01100110;
  B = 0xB3;   // 10110011;
  C = A & B;  // 00100010(0x22)

  // Bitwise OR
  A = 0x64;   // 01100100
  B = 0x10;   // 00010000
  C = A | B;  // 01110100 (0x74)

  // Bitwise XOR (If same, its 0 otherwise its a 1)
  A = 0x64;   // 01100100
  B = 0xB3;   // 10110011
  C = A ^ B;  // 11010111

  // Bitwise Complement (Negate bits)
  A = 0x64;  // 01100100 (0x64)
  B = ~A;    // 10011011 (0x9B)

  // Shift operators
  // A >> B (Right shift A by B bit positions)
  // A << B (Left shift A by B bit positions)
  // Vacated bit are filled by zeros
  // Fast way to multiply/devide any number by power of 2.

  A = 0x3B;    // 00111011
  B = A << 2;  // 11101100 (0xEC) (Same as B=A*4)

  A = 0x96;    // 10010110
  B = A >> 4;  // 00001001 (0x9) (Same as B=A/4)

  // Bit masking
  // Avoid direct assignment of values to registers that would otherwise
  // override all bits.
  // Consider an 8-bit register REGT_8b (11100000) (0xE0)
  // if each bit represents an LED, to turn on LED 2 (Bit 2)
  unsigned char REGT_8b = 0xE0;

  REGT_8b |= 1 << 2;  // turns on LED2

  // To turn off LED6
  REGT_8b &= ~(1 << 6);


  // Turn off LED 0 and 5
  // Assuming current register bits: 11100011
  REGT_8b &= ~((1 << 2) | (1 << 5));

  // Turn on LED 3 and 4
  REGT_8b |= ((1 << 3) | (1 << 4));

  // Turn on LED 3 and off LED 7
  REGT_8b = (REGT_8b | (1 << 3)) & (~(1 << 7));

  // ======================= Bit extraction ========================
  // Assume REGHL_16 is a 16 bit register.
  // Assume the current value is:
  // 1000000110101011
  // We can extract the lower 8 bits and upper 8 bits into REGH_8
  uint16_t REGHL_16;
  REGHL_16 = 0b1000000110101011;

  // Extract upper 8 bits by AND operation and left shift by 8
  REGT_8b = (REGHL_16 & 0xFF00) >> 8;  // 10000001

  // Extract lower 8 bits
  REGT_8b = (REGHL_16 & 0xFF00);  // 10101011
}