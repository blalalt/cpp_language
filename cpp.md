1. RALL(资源获取即初始化):
   * 概念：使用局部对象来管理资源的技术称为资源获取即初始化；这里的资源主要是指操作系统中有限的东西如内存、网络套接字等等，局部对象是指存储在栈的对象，它的生命周期是由操作系统来管理的，无需人工介入；
   * 原理：资源的使用一般经历三个步骤a.获取资源 b.使用资源 c.销毁资源，但是资源的销毁往往是程序员经常忘记的一个环节，所以程序界就想如何在程序员中让资源自动销毁呢？c++之父给出了解决问题的方案：RAII，它充分的**利用了C++语言局部对象自动销毁的特性来控制资源的生命周期**。
   * 步骤：a.设计一个类封装资源 b.在构造函数中初始化 c.在析构函数中执行销毁操作 d.使用时声明一个该对象的类
   * 参考资料：[C++11实现模板化(通用化)RAII机制](https://blog.csdn.net/10km/article/details/49847271)，
   
2. CONST

   ```c++
   // 一种承诺，承诺不会去改变这个值
   const int var = 20;
   int& var2 = (int&) var;
   var2 = 100;
   cout << var1 << var2 << endl; // 20, 12
   // 说明 引用 和 原变量 并不是在同一个地址空间
   ```

3. C++的内存区域分类

   ![1570282321540](C:\Users\BLALALT\AppData\Roaming\Typora\typora-user-images\1570282321540.png)
