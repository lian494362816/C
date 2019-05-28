2018_03
	AdvanceQueue
		高级队列
	compute_time
		计算程序的执行时间
2018_04
	rand_256
		产生256个随机数

2018_06
	bbs_test.c  
		验证bbs段只记录位置的大小，不增大代码空间

	text_test.c
		代码段会增大代码的空间

	memset.c
		u-boot 中memset的实现	

2018_07
	select.c
		linux select 简单例子

	01_printf.c
		通过指针确定可变参数, 先偏移再取值
		编译时，需要加上-m32

	02_printf.c
		通过指针确定可变参数，取值后再偏移
		编译时，需要加上-m32

	03_printf.c
		通过va_start va_arg va_end 实现可变参的取值
		编译时，需要加上-m32

	04_printf.c
		va_list va_start va_arg va_end 源码
		编译时，需要加上-m32

2018_10
        pointer_sub.c
        测试指针之间的减法
    
2018_11
    01_macro_return.c
        可以返回错误的宏

    02_print.c
        通过VT码打印出不同颜色的log

2018_12
    01_error.c
        测试#error

2019_03
    1_export_symbol.c
        测试 __EXPORT_SYMBOL宏

    02_test.c 
        测试?: 的功能 

2019_04 
    01_test.c 
        测试--> 的功能, 结论为先减1， 在做小于等于的判断

    02_typeof.c
        测试typeof的功能，实现max,min 等宏

    03_container_of.c 
        测试container_of

    04_zero_array.c
        测试零长度数组

    05_open.c
        INLINE_SYSCALL_CALL 宏的展开

    06_fun_pointer_cmp.c
        __attribute__((weak, alias("__def_xxx"))); 的测试

    hello.c
        跟06配合的.c文件

    07_aligned.c 
        attribute aligned 测试

    08_packed.c
        attribute packed 测试

    09_format.c
        attribute format 测试
    
2019_05
    01_case.c
        测试case 1 ... 2

            1) 发现swtich case 中没有判断语法错误
            如下面的程序，可以正常编译并运行，不会报错
                switch(x)
                {
                    case 1:

                        break;
                    ssdf:
                        brea;
                }
            2) 可以使用 "..." 来省略某些过程
            如
                switch(x)
                {
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:

                        break;
                }
            等价于
                switch(x)
                {
                    case 1 ... 5:

                        break;
                }
                
    02_constructor.c
        测试constructor 和 destructor 的功能
        被constructor 修饰的函数会在main 被调用之前自动调用
        被destructor  修饰的函数会在main 被调用之后自动调用

    03_mode.c
        测试__attribute__((mode)) 的功能

    04_noreturn.c  
        测试noreturn    

    05_constant_p.c   
        测试 __builtin_costant_p 的功能

    06_label.c
       测试 __label__ 的作用, 当在宏中定义局部标号
       可能会出现重复定义，此时可以使用 __label__ 来消除重定义
   
    07_define.c
        测试在宏中使用可变参数

    08_func_err.c
        测试PRINT_FUNC_ERR 宏

    09_chinese_word.c
        通过HZK16 来打印16x16的字符
        里面涉及到了UTF-8转GBK、在HZK16查找对应的字模数据
        
