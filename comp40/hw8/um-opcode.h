#line 697 "www/solutions/um/miniasm-core.nw"
#ifndef UM_OPCODE_INCLUDED
#define UM_OPCODE_INCLUDED

#line 706 "www/solutions/um/miniasm-core.nw"
typedef enum Um_Opcode {
  CMOV = 0, SLOAD, SSTORE, ADD, MUL, DIV,
  NAND, HALT, ACTIVATE, INACTIVATE, OUT, IN, LOADP, LV
} Um_Opcode;

#line 702 "www/solutions/um/miniasm-core.nw"
#endif
