# system-programming

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