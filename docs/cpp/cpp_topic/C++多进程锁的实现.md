# C++多进程锁的实现

最近工作中需要 **多进程 & 多线程** 的读写文件，项目是基于Qt的；

 用于 读远远多余 写，QLockFile 并不合用；效率下降太多

半天，也没有在Qt中并没有找到其他比较合适轮子，一拍大腿就自己干了



QLockFile 锁有两个问题影响效率：

1、基于文件系统，加锁要操作文件系统

2、没有读写锁模式，对 读远大于写的场景并不合适；

所以目标就是实现一个 基于内存的读写锁


## 分析

读写锁有3种模式：**读优先**，**写优先**，**读写平权**

本次任务的问题是QLockFile效率不行，所以一起以效率优先的方式去实现的：**读优先 且  线程不落等待区** 

读写锁要求：读读互斥，读写互斥，写写不互斥

## 读写锁

读写锁是基于一把可重入锁，一把不可重入锁组成























































