# 深入理解：变量、引用、指针

## 变量

变量是程序中一个重要的概念。

在了解概念前先，看一段简单的程序。

```cpp
int a = 0;
int main(int argc, char* argv[])
{
	int b = 1;
	int c = a + b;
}
```

程序的结果也很明了：

```cpp
c 为 1
```

问题：变量a、b、c是以什么样的形式存在于程序中的嗯？



### vs编译器汇编

这里是win32的x86汇编：

```text
--- E:\github\githubDemo\C++相关\104_变量\main.cpp ---------------------------------
int a = 0;
int main()
{
00F61470  push        ebp  
00F61471  mov         ebp,esp  
00F61473  sub         esp,8  
	int b = 1;
00F61476  mov         dword ptr [b],1  
	int c = a + b;
00F6147D  mov         eax,dword ptr [a (0F69138h)]  
00F61482  add         eax,dword ptr [b]  
00F61485  mov         dword ptr [c],eax  
}
00F61488  xor         eax,eax  
00F6148A  mov         esp,ebp  
00F6148C  pop         ebp  
00F6148D  ret  
--- 无源文件 -----------------------------------------------------------------------
```

这里主要关注mov和ptr，mov是汇编中的数据传输指令；ptr为pointer（指针）的缩写。

```text
	int b = 1;
00F61476  mov         dword ptr [b],1   
```



这里的汇编的意思就是，给内存地址等于 “b寄存器的值” 得位置 存上值 1

明显b是我们的变量。Vs编译器上，我们看到似乎存在一个寄存器b。

即程序运行时存在一个名为变量名的地址位置， 可大致直接理解为一个寄存器。



### gcc编译器汇编

ubuntu64位汇编：gcc编译器

```cpp
main():

0x0000555555555129  endbr64  
0x000055555555512d  push   %rbp 
0x000055555555512e  mov    %rsp,%rbp 
0x0000555555555131  movl   $0x1,-0x8(%rbp) 
0x0000555555555138  mov    0x2ed6(%rip),%edx        # 0x555555558014 <a> 
0x000055555555513e  mov    -0x8(%rbp),%eax 
0x0000555555555141  add    %edx,%eax 
0x0000555555555143  mov    %eax,-0x4(%rbp) 
0x0000555555555146  mov    $0x0,%eax 
0x000055555555514b  pop    %rbp 
0x000055555555514c  ret   
```



在这里我们看到： 对于栈变量（b、c），我们是直接使用其在栈中的相对地址位置。 对于全局变量（a），程序是提前分配了一个地址位置，我们也是直接操作的地址。

可见在gcc编译器中，变量只存在于程序的代码编程阶段；在编译器中就会转换为地址，不在存在。这也是我们常用的理解方式。

### [#](https://blog.addai.cn/pages/f95db2/#总结)总结

综上，变量在c++程序中只存在于代码编辑阶段；在程序中表现为地址。

## [#](https://blog.addai.cn/pages/f95db2/#引用)引用

## [#](https://blog.addai.cn/pages/f95db2/#指针)指针