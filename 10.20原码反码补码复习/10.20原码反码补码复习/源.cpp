﻿#define  _CRT_SECURE_NO_WARNINGS 1
//对于正整数，原码反码补码都是一样的
//对于负整数
//原码：直接将数值按照正负数的形式翻译成二进制就可以
//反码：源码的符号位不变，其他位依次按位取反
//补码：反码+1；
//原码x+补码y=2^31,x取反+1=y，y取反+1=x;

//对于整形，数据存放内存中其实存放的是补码
//正数＋正数，无所谓，
//负数＋负数，
//1 1111011 x  -5  2^7-x  2^7-x-y   2^7-1 1  1111010 0000110
//1 1111111 y  -1  2^7-y   2^7-1
//正数+负数
//1 0000101
//0 1111011


//1.左移操作符(操作数只能是整数)
//左边抛弃右边补0

//2.右移操作符（操作数只能是整数）
//<1>逻辑右移：左边用0填充，右边丢弃
//<2>算术右移：左边用原该值的符号位填充，右边丢弃

//低位对齐，高位补零。

//3.按位与 &
// 同一二进制位上的数字都是1的话，&的结果为1，否则为0.
// 0 & 0 = 0；
//0 & 1 = 0；
//1 & 1 = 1；
// 对于原二进制数来说，&0是屏蔽，&1是不变。
// &可以利用0来屏蔽，也可以用1来读取。
​ //例如： 一个二进制数 1101 1001，我只想要它的后四位，怎么办呢？
​ //只需要进行如下操作：1101 1001 & 0000 1111即可。
​ //其实该方法是屏蔽和读取的结合， & 0保证消除无用位， & 1保证有用数据的完整性

//4.按位或 |
// 只要参与运算的双方其中有一个是1，结果就是1.同0才为0.
// 例如：1010 0000 | 0000 1111.
//结果为 1010 1111.
//总结：对于原二进制数来说， | 0是不变， | 1是置1.

//5.按位异或 ^
//只要参与运算的双方互异，结果就为1，否则为0.
// 一个数^1的话就会0变成1，1变成0，而^0则不对原数进行改变。
//所以根据此特性可以对特定位进行0 1 反转

//6.逗号表达式:（p1,p2,p3）依次执行p1，2，3，但最终结果是最后一个表达式的结果