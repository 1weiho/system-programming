# system-programming

## SIC/XE Instruction Set Table
```
Mnemonic      Format  Opcode  Effect                               Notes
------------  ------  ------  -----------------------------------  ------
ADD m          3/4      18    A <-- (A) + (m..m+2)
ADDF m         3/4      58    F <-- (F) + (m..m+5)                  X F
ADDR r1,r2      2       90    r2 <-- (r2) + (r1)                    X
AND m          3/4      40    A <-- (A) & (m..m+2)
CLEAR r1        2       B4    r1 <-- 0                              X
COMP m         3/4      28    A : (m..m+2)
COMPF m        3/4      88    F : (m..m+5)                          X F C
COMPR r1,r2     2       A0    (r1) : (r2)                           X F C
DIV m          3/4      24    A : (A) / (m..m+2)
DIVF m         3/4      64    F : (F) / (m..m+5)                    X F
DIVR r1,r2      2       9C    (r2) <-- (r2) / (r1)                  X
FIX             1       C4    A <-- (F) [convert to integer]        X F
FLOAT           1       C0    F <-- (A) [convert to floating]       X F
HIO             1       F4    Halt I/O channel number (A)         P X
J m            3/4      3C    PC <-- m
JEQ m          3/4      30    PC <-- m if CC set to =
JGT m          3/4      34    PC <-- m if CC set to >
JLT m          3/4      38    PC <-- m if CC set to <
JSUB m         3/4      48    L <-- (PC); PC <-- m
LDA m          3/4      00    A <-- (m..m+2)
LDB m          3/4      68    B <-- (m..m+2)                        X
LDCH m         3/4      50    A [rightmost byte] <-- (m)
LDF m          3/4      70    F <-- (m..m+5)                        X F
LDL m          3/4      08    L <-- (m..m+2)
LDS m          3/4      6C    S <-- (m..m+2)                        X
LDT m          3/4      74    T <-- (m..m+2)                        X
LDX m          3/4      04    X <-- (m..m+2)
LPS m          3/4      D0    Load processor status from          P X
                                information beginning at
                                address m (see Section
                                6.2.1)
MUL m          3/4      20    A <-- (A) * (m..m+2)
MULF m         3/4      60    F <-- (F) * (m..m+5)                  X F
MULR r1,r2      2       98    r2 <-- (r2) * (r1)                    X
NORM            1       C8    F <-- (F) [normalized]                X F
OR m           3/4      44    A <-- (A) | (m..m+2)
RD m           3/4      D8    A [rightmost byte] <-- data         P
                                from device specified by (m)
RMO r1,r2       2       AC    r2 <-- (r1)                           X
RSUB           3/4      4C    PC <-- (L)
SHIFTL r1,n     2       A4    r1 <-- (r1); left circular            X
                                shift n bits. {In assembled
                                instruction, r2=n-1}
SHIFTR r1,n     2       A8    r1 <-- (r1); right shift n            X
                                bits with vacated bit
                                positions set equal to
                                leftmost bit of (r1).
                                {In assembled instruction,
                                r2=n-1}
SIO             1       F0    Start I/O channel number (A);       P X
                                address of channel program
                                is given by (S)
SSK m          3/4      EC    Protection key for address m        P X
                                <-- (A) (see Section 6.2.4)
STA m          3/4      0C    m..m+2 <-- (A)
STB m          3/4      78    m..m+2 <-- (B)                        X
STCH m         3/4      54    m <-- (A) [rightmost byte]
STF m          3/4      80    m..m+5 <-- (F)                        X
STI m          3/4      D4    Interval timer value <--            P X
                                (m..m+2) (see Section
                                6.2.1)
STL m          3/4      14    m..m+2 <-- (L)
STS m          3/4      7C    m..m+2 <-- (S)                        X
STSW m         3/4      E8    m..m+2 <-- (SW)                     P
STT m          3/4      84    m..m+2 <-- (T)                        X
STX m          3/4      10    m..m+2 <-- (X)
SUB m          3/4      1C    A <-- (A) - (m..m+2)
SUBF m         3/4      5C    F <-- (F) - (m..m+5)                  X F
SUBR r1,r2      2       94    r2 <-- (r2) - (r1)                    X
SVC n           2       B0    Generate SVC interrupt. {In           X
                                assembled instruction, r1=n}
TD m           3/4      E0    Test device specified by (m)        P     C
TIO             1       F8    Test I/O channel number (A)         P X   C
TIX m          3/4      2C    X <-- (X) + 1; (X) : (m..m+2)             C
TIXR r1         2       B8    X <-- (X) + 1; (X) : (r1)             X   C
WD m           3/4      DC    Device specified by (m) <-- (A)     P
                                [rightmost byte]
```

## Homework

### [Homework 1. SIC 組合語言 – 字串轉換](https://github.com/davidho0403/system-programming/tree/main/homework/HW1)
在 Device ‘F1’ 中有一字串由大小寫英文字母所組成（字串的結束字元為 ‘$’，其 ASCII 值為 0x24）。請用 SIC 的指令集寫一組合語言程式，完成以下的功能：
請從 Device ‘F1’ 中讀取字串，如果所讀取的字元為小寫，請將其轉換為大寫字元並寫入 Device ‘F2’ 中 （如果所讀取的字元為大寫，則不變，直接寫到 Device ‘F2’ 中）。
完成基本功能者滿分90分，將讀取字元及寫入字元分別以副程式來撰寫者滿分100分。

### [Homework 2. SIC/XE 組合語言 – 9x9 乘法表](https://github.com/davidho0403/system-programming/tree/main/homework/HW2)
請用 SIC/XE 的指令集寫一組合語言程式，在 Device ‘F2’ 中印出如下的 9x9 乘法表，請滿足以下要求：
1. 寫出印一個數字（Register A 的值）的副程式 50 分
2. 以雙迴圈的方式來列印，滿分最高 90 分
3. 你的輸出結果需要對齊，對齊 100 分
```
    1   2   3   4   5   6   7   8   9
1   1   2   3   4   5   6   7   8   9
2   2   4   6   8  10  12  14  16  18
3   3   6   9  12  15  18  21  24  27
4   4   8  12  16  20  24  28  32  36
5   5  10  15  20  25  30  35  40  45
6   6  12  18  24  30  36  42  48  54
7   7  14  21  28  35  42  49  56  63
8   8  16  24  32  40  48  56  64  72
9   9  18  27  36  45  54  63  72  81
```

### [Homework 3. Assembler – Pass 1](https://github.com/davidho0403/system-programming/tree/main/homework/HW3)
請參考課堂中提供的程式 (1-token.c, 2-optable.c 及 3-asm_pass1_u.c) 及 Figure 2.4(a) 的演算法完成 SIC/XE Assembler 的 Pass 1。你的程式要完成：
1. 如 Figure 2.2 秀出每一行組合語言程式的指令，並在前面印出 LOCCTR 的值(該行最後不需印出 Object Code ，印不印出註解均可)
2. 印出 ASM Program 的長度
3. 請在最後印出 SYMTAB 的 Symbol 及其對應值。
Eaxmple：
```
000000  COPY    START   0
000000  FIRST   STL     RETARD
000003          LDB     #LENGTH
000006          BASE    LENGTH
000006  CLOOP   +JSUB   RDREC
00000A          LDA     LENGTH
00000D          COMP    #0
000010          JEQ     ENDFIL
000013          +JSUB   WRREC
000017          J       CLOOP
00001A  ENDFIL  LDA     EOF
00001D          STA     BUFFER
000020          LDA     #3
000023          STA     LENGTH
000026          +JSUB   WRREC
00002A          J       @RETARD
00002D  EOF     BYTE    C'EOF'
000030  RETARD  RESW    1
000033  LENGTH  RESW    1
000036  BUFFER  RESB    4096
.
.
Program length = 1036
FIRST   : 000000
CLOOP   : 000006
ENDFIL  : 00001A
EOF     : 00002D
RETARD  : 000030
LENGTH  : 000033
BUFFER  : 000036
```