# C++ Qt 工程师学习计划跟踪表

## 每日例行（贯穿全程）

- 算法 1 题 (30 min)
- 英语阅读技术文档 (20 min)

---

## 第一阶段：C++ 类型系统与语言深度

### 第 1 周：const 正确性
完成日期：____年__月__日

- 区分 const int*、int* const、const int* const 的指向和值规则
- 写出 const 成员函数示例，用 mutable 突破 const 限制
- 理解逻辑 const 与物理 const，各写一个示例
- 区分顶层 const 与底层 const
- 用 constexpr 写一个编译期计算函数
- 在你现有项目中选一个类，给所有不修改成员的函数加 const
- 手写一个 mutable 使用场景：缓存计算结果
- 算法 1 题 + 英语 20min

---

### 第 2 周：类型转换与 explicit
完成日期：____年__月__日

- 用 static_cast 写父类指针转子类指针，并验证安全性
- 用 dynamic_cast 做安全的多态转换，处理转换失败的情况
- 理解 const_cast 的危险场景，写出一个反例
- 了解 reinterpret_cast 的用途，何时不得不使用
- 用 explicit 禁止隐式转换，对比加与不加的行为差异
- 把项目中 5 处 C 风格转换改成 C++ 风格转换
- 算法 1 题 + 英语 20min

---

### 第 3 周：运算符重载
完成日期：____年__月__日

- 列出不能重载的 4 个运算符并说明原因
- 实现一个类的算术运算符（+ - * /），注意返回值类型
- 实现比较运算符（只需要 == 和 <，其余用这两个组合）
- 实现拷贝赋值和移动赋值，注意自赋值检查
- 实现 operator[] 的 const 和非 const 两个版本
- 实现 explicit operator bool() 用于条件判断
- 理解为什么 && || , 不应该重载
- 用 copy-and-swap idiom 统一赋值运算符
- 算法 1 题 + 英语 20min

---

### 第 4 周：智能指针
完成日期：____年__月__日

- 用 unique_ptr 改写一个使用裸指针的类，不再写 delete
- 用 shared_ptr + weak_ptr 解决一个循环引用问题
- 自定义 deleter：用 unique_ptr 管理 FILE*
- 手写一个微型 enable_shared_from_this，理解 CRTP 原理
- 了解 shared_ptr 的 aliasing constructor 的用途
- 区分 QPointer 与 std::weak_ptr 的差异和使用场景
- 阅读《Effective Modern C++》条款 18-22
- 算法 1 题 + 英语 20min

---

### 第 5 周：移动语义
完成日期：____年__月__日

- 手写 MyVector 类，对比拷贝构造和移动构造的性能
- 在 MyVector 的移动构造函数上加 noexcept，对比不加时 vector resize 的行为差异
- 写一个 emplace_back vs push_back 的性能对比 demo
- 用 std::forward 实现一个完美转发的工厂函数
- 理解 RVO/NRVO：写测试验证编译器自动优化
- 总结三五法则和零法则的适用场景
- 用 godbolt.org 观察移动语义对应的汇编
- 算法 1 题 + 英语 20min

---

### 第 6 周：Lambda 与 std::function
完成日期：____年__月__日

- 默写 lambda 完整语法：[capture](params) mutable -> ret { body }
- 写一个 init capture 捕获 unique_ptr 的 lambda
- 写一个泛型 lambda：[](auto x) { return x; }
- 用 std::function 存储不同 lambda，理解类型擦除机制
- 手写 std::bind 示例，注意占位符 _1 _2 规则
- 检查你项目中所有 connect 中捕获 this 的 lambda，评估安全性
- 阅读《Effective Modern C++》条款 31-34
- 算法 1 题 + 英语 20min

---

### 第 7 周：STL 算法
完成日期：____年__月__日

- 用 find/find_if/count/count_if/all_of/any_of/none_of 各写一个示例
- 掌握 erase-remove idiom：remove_if + erase 的正确用法
- 用 transform 将一个序列转换为另一个序列
- 用 sort/stable_sort/partial_sort/nth_element 做不同粒度的排序
- 用 partition 将满足条件的元素移到前面
- 用 accumulate 做求和、求乘积、字符串拼接
- 用 set_union/set_difference 做集合运算
- 在现有项目中找 5 个手写 for 循环，用 STL 算法重写
- 学习 std::clamp、std::minmax、std::sample 的用法
- 算法 1 题 + 英语 20min

---

### 第 8 周：编译链接模型
完成日期：____年__月__日

- 理解翻译单元概念：.cpp 经过预处理、编译、链接的全过程
- 理解 ODR 规则：故意写一个违规程序，观察链接错误
- 对比 #ifndef 和 #pragma once 的区别和各自优劣
- 理解为什么模板定义必须放在头文件中
- 理解 inline 的三个现代含义
- 用 extern template 显式实例化，测量编译时间差异
- 了解 name mangling、符号解析、静态链接 vs 动态链接
- 算法 1 题 + 英语 20min

---

### 第 9 周：虚函数底层机制
完成日期：____年__月__日

- 画出单继承下 vtable 和 vptr 的内存布局图
- 用 sizeof 观察：空类、有虚函数的类、有多个虚函数的类的大小
- 理解虚函数调用的两次间接跳转的开销
- 理解去虚拟化（devirtualization）的编译器优化条件
- 理解虚析构函数为什么必须的 3 个原因
- 画出多继承下的虚表结构（多个 vptr）
- 画图理解虚继承如何解决菱形继承问题
- 用 godbolt.org 观察虚表布局和虚函数调用的汇编
- 算法 1 题 + 英语 20min

---

### 第 10 周：C++ 异常安全
完成日期：____年__月__日

- 能说出异常安全的三个保证级别并各写一个示例
- 理解 noexcept 的声明语法和 noexcept() 检测操作符
- 理解为什么移动构造函数应该标记 noexcept
- 理解构造函数抛异常时，已构造的成员和基类会被正确析构
- 理解析构函数为何不应抛异常（C++11 起默认 noexcept(true)）
- 用 RAII 包装锁、文件、Socket，验证异常路径下资源正确释放
- 了解 std::uncaught_exceptions() 的用途
- 算法 1 题 + 英语 20min

---

## 第二阶段：C++ 模板系统学习

### 第 11 周：函数模板基础
完成日期：____年__月__日

- 写出函数模板的完整语法：template typename T
- 理解隐式实例化 vs 显式实例化的区别
- 理解模板参数的类型推导规则（值/引用/万能引用）
- 为不同类型写一个全特化版本
- 理解函数模板重载决议：非模板优先于模板
- 阅读《C++ Templates: The Complete Guide》前 2 章
- 算法 1 题 + 英语 20min

---

### 第 12 周：类模板
完成日期：____年__月__日

- 写出类模板定义，成员函数在类外定义
- 理解类模板成员函数的延迟实例化
- 写一个别名模板：template typename T using MyVec = std::vector T
- 写出模板模板参数的语法
- 实现 MyStack T 类模板（push/pop/top，底层用 std::vector）
- 算法 1 题 + 英语 20min

---

### 第 13 周：Variadic Templates 与折叠表达式
完成日期：____年__月__日

- 写出可变参数模板语法：template typename... Args
- 实现递归展开模式：printHead + printTail 递归
- 理解 C++17 四种折叠表达式的方向和写法
- 用 sizeof...(Args) 获取参数包大小
- 阅读 std::make_unique 和 std::tuple 的实现源码
- 实现一个 printAll(args...) 函数
- 算法 1 题 + 英语 20min

---

### 第 14 周：Type Traits 与 SFINAE
完成日期：____年__月__日

- 熟记 10 个常用 type_traits：is_same、is_base_of、is_convertible、is_integral、is_floating_point、is_class、is_pointer、remove_reference、decay、enable_if
- 理解 SFINAE 原理：替换失败不是错误
- 用 enable_if 的三种写法控制重载决议
- 用 std::void_t 检测一个类型是否具有某个成员
- 用 std::conditional 做编译期类型选择
- 算法 1 题 + 英语 20min

---

### 第 15 周：CRTP 与静态多态
完成日期：____年__月__日

- 写出 CRTP 基本结构：class Derived : public Base Derived
- 理解 CRTP 为何能实现编译期多态
- 阅读 std::enable_shared_from_this 源码，理解 CRTP 的应用
- 实现一个 CRTP 基类，自动为派生类生成 operator<
- 实现一个 CRTP 对象计数器基类
- 实现一个 CRTP Mixin 组合示例
- 理解 CRTP 的局限：不能放在 vector Base* 中
- 手写微型 enable_shared_from_this
- 算法 1 题 + 英语 20min

---

## 第三阶段：API 设计 + C++ 新特性 + 工具库

### 第 16 周：API 设计原则
完成日期：____年__月__日

- 背诵参数传递规则总结表
- 理解 sink 参数：按值传递 + std::move
- 理解输出参数 vs 返回值的选择
- 理解 std::optional T 的返回值用法
- 对比异常 vs std::error_code vs std::optional vs bool 四种错误处理
- 给一个类写 Doxygen 风格的文档注释
- Review 项目中一个公开头文件，按原则提出改进点
- 算法 1 题 + 英语 20min

---

### 第 17 周：C++11/14/17 特性精讲
完成日期：____年__月__日

- 用 enum class 替代项目中的传统 enum
- 理解 auto vs decltype(auto) 的区别并写代码验证
- 理解 decltype 的两种规则（加括号 vs 不加括号）
- 用结构化绑定 auto [x, y, z] = tuple 简化代码
- 用 if constexpr 实现编译期分支
- 用 if/switch 初始化语句重构项目中一处代码
- 用 static_assert 做编译期断言
- 理解 range-based for 的临时对象生命周期陷阱
- 算法 1 题 + 英语 20min

---

### 第 18 周：std::filesystem、std::chrono、std::regex
完成日期：____年__月__日

- 用 std::filesystem::path 做路径拼接、获取扩展名
- 用 directory_iterator 递归遍历目录
- 用 std::chrono 测量函数执行时间
- 理解 steady_clock vs system_clock vs high_resolution_clock 的区别
- 用 std::regex 做邮箱格式验证
- 写一个遍历目录统计所有 .cpp 文件总行数的程序
- 算法 1 题 + 英语 20min

---

## 第四阶段：多线程与并发

### 第 19 周：线程基础
完成日期：____年__月__日

- 用 std::thread 创建线程并正确 join
- 理解 detach 的危险和适用场景
- 用 thread_local 实现每个线程独立的计数器
- 理解 hardware_concurrency() 的返回值含义
- 对比 Qt QThread 的两种用法并写出示例
- 用 QThread::moveToThread 把耗时代码从主线程移出
- 算法 1 题 + 英语 20min

---

### 第 20 周：互斥量与锁
完成日期：____年__月__日

- 用 std::mutex + std::lock_guard 保护临界区
- 用 std::unique_lock 实现可延迟加锁
- 用 std::scoped_lock 同时锁两个 mutex，避免死锁
- 用 std::shared_mutex 实现多读单写
- 用 std::lock() 全局函数同时锁多个 mutex
- 故意写一个死锁程序，用调试器分析
- 理解死锁的四个必要条件
- 理解活锁和饥饿概念
- 算法 1 题 + 英语 20min

---

### 第 21 周：条件变量
完成日期：____年__月__日

- 写出 condition_variable 的 wait(lock, predicate) 正确写法
- 理解为什么 wait 必须带谓词（虚假唤醒）
- 理解丢失唤醒问题的原因和避免方法
- 实现生产者-消费者环形缓冲区
- 实现线程安全的 BlockingQueue T
- 理解为什么 wait 必须配合 unique_lock 而不是 lock_guard
- 算法 1 题 + 英语 20min

---

### 第 22 周：Future 与异步
完成日期：____年__月__日

- 用 std::async 启动异步任务并获取结果
- 理解 std::launch::async vs std::launch::deferred 的区别
- 理解 std::async 默认启动策略的陷阱
- 用 std::promise 手动设置异步结果
- 用 std::packaged_task 包装可调用对象
- 用 QtConcurrent::run 启动异步任务
- 对比 std::async 和 std::thread 的性能差异
- 算法 1 题 + 英语 20min

---

### 第 23 周：原子操作与无锁编程
完成日期：____年__月__日

- 用 std::atomic int 做线程安全的计数器
- 理解 4 种内存序的含义并各写一个示例
- 用 CAS 实现无锁的 push 操作
- 理解 compare_exchange_weak vs _strong 的选择
- 理解 ABA 问题及其解决方案
- 用 std::atomic_flag 实现自旋锁
- 实现单生产者单消费者的无锁栈
- 算法 1 题 + 英语 20min

---

### 第 24 周：手写线程池（核心项目 1）
完成日期：____年__月__日

- 设计线程池架构：任务队列、工作线程、优雅关闭
- 实现 submit(callable, args...) 返回 std::future
- 用 std::packaged_task 做类型擦除
- 实现 shutdown() 等待所有任务完成再退出
- 实现 shutdown_now() 丢弃未执行任务
- 处理异常：任务中抛异常传播到 future
- 注意 false sharing 问题，做缓存行对齐
- 上传到 GitHub，写 README
- 算法 1 题 + 英语 20min

---

### 第 25 周：Qt 多线程深入
完成日期：____年__月__日

- 深入理解 QThread::moveToThread 的工作原理
- 理解跨线程信号槽的 AutoConnection 默认行为
- 理解 Qt::QueuedConnection 的参数拷贝机制
- 理解 Qt::BlockingQueuedConnection 的死锁风险
- 用 QMetaObject::invokeMethod 跨线程安全调用
- 理解 QObject 线程亲和性的规则
- 用 QThreadPool + QRunnable 执行轻量级任务
- 用 QtConcurrent::mapped 并行处理 QList
- 理解 GUI 线程规则并写出正确示例
- 算法 1 题 + 英语 20min

---

### 第 26 周：并发排查与性能分析
完成日期：____年__月__日

- 给线程池项目加上 ThreadSanitizer 检测，修复数据竞争
- 用 perf 或 Visual Studio 探查器找到锁争用热点
- 理解锁的粒度选择的权衡
- 了解数据分片、per-thread 数据、double buffering 减锁技术
- 写一个并发程序的 benchmark 对比不同锁策略的性能
- 复盘：回顾 19-25 周所学，解答里程碑自测题
- 算法 1 题 + 英语 20min

---

## 第五阶段：操作系统基础

### 第 27 周：进程与线程底层
完成日期：____年__月__日

- 用代码创建 10000 个线程和 10000 个进程，对比时间开销
- 理解虚拟地址空间布局并画出内存图
- 理解页表和 TLB 的作用
- 理解用户态到内核态的切换开销
- 理解上下文切换的具体代价（寄存器/TLB/缓存）
- 用共享内存实现两个进程间的数据传输
- 了解 IPC 所有方式并画出对比表
- 阅读 CSAPP 第 8 章
- 算法 1 题 + 英语 20min

---

### 第 28 周：内存管理底层
完成日期：____年__月__日

- 理解虚拟地址空间的各段布局并画图
- 理解 malloc/free 的底层实现：ptmalloc、brk vs mmap
- 理解内部碎片和外部碎片的区别
- 理解栈帧结构：ebp/esp 的运作方式
- 了解 TCMalloc 和 jemalloc 的设计思想
- 实现一个固定大小的内存池分配器
- 用 mmap 实现大文件映射读取
- 阅读 CSAPP 第 9 章
- 算法 1 题 + 英语 20min

---

### 第 29 周：锁的底层实现
完成日期：____年__月__日

- 理解 futex（Linux）和 Critical Section（Windows）的工作原理
- 对比自旋锁和互斥锁的开销，写 benchmark
- 理解信号量的内核级实现
- 理解读写锁的饥饿问题
- 了解 MESI 缓存一致性协议
- 用 futex（或 Windows 等效）实现一个简易互斥锁
- 算法 1 题 + 英语 20min

---

### 第 30 周：I/O 模型
完成日期：____年__月__日

- 理解阻塞 I/O 和非阻塞 I/O 的区别
- 画出五种 I/O 模型的对比图
- 实现一个基于 select 的简易 echo 服务器
- 实现一个基于 poll 的版本并对比
- 实现一个基于 epoll 的版本，对比性能
- 理解 epoll ET 和 LT 的区别并编写两套代码对比
- 了解零拷贝：sendfile、splice、mmap
- 阅读 CSAPP 第 10-11 章
- 算法 1 题 + 英语 20min

---

## 第六阶段：内存管理与调试

### 第 31 周：C++ 内存模型与 RAII
完成日期：____年__月__日

- 画出 C++ 对象从构造到析构的完整生命周期图
- 写一个 RAII 文件句柄包装器
- 写一个 RAII 数据库连接包装器
- 用 placement new 实现一个简易对象池
- 理解内存对齐：用 alignof 和 alignas
- 理解 SSO（小字符串优化）的实现原理
- 理解虚函数表在内存中的布局
- 算法 1 题 + 英语 20min

---

### 第 32 周：内存泄漏检测
完成日期：____年__月__日

- 编译一个带 ASan 的程序，故意写出以下 bug 并检测：
  - 数组越界读写
  - use-after-free
  - 堆缓冲区溢出
  - double-free
  - 内存泄漏
- 理解 ASan 的检测原理（影子内存）
- 了解 Windows CRT 内存泄漏检测方法
- 用 ASan 跑你现有项目的 Debug 版本，检查隐藏问题
- 理解 shared_ptr 循环引用的检测方法
- 算法 1 题 + 英语 20min

---

### 第 33 周：高级调试技巧
完成日期：____年__月__日

- 在 WinDbg 中加载符号、分析 dump 文件
- 用条件断点只在满足条件时中断
- 用 watchpoint 监控变量何时被修改
- 写一个崩溃程序，生成 dump 并用 WinDbg 分析
- 调试多线程程序：查看所有线程、检测死锁
- 用 Visual Studio 性能探查器找到 CPU 热点
- 学习 strace/ltrace（或 Windows 等效）追踪系统调用
- 算法 1 题 + 英语 20min

---

### 第 34 周：Qt 内存管理专讲
完成日期：____年__月__日

- 理解 QObject 父子树：setParent、析构顺序、findChild/findChildren
- 写测试验证 QObject 父子析构的完整顺序
- 理解 deleteLater() 的实现原理和 delete 的区别
- 理解 WA_DeleteOnClose 的行为
- 对比 QSharedPointer 和 std::shared_ptr
- 理解隐式共享 COW 的实现：QSharedData + QSharedDataPointer
- 写测试观察隐式 detach 的触发条件
- 理解 QScopedPointer 和 QPointer 的用途
- 排查项目所有 lambda 捕获裸 this 的风险
- 算法 1 题 + 英语 20min

---

## 第七阶段：Qt 深入

### 第 35 周：Qt MOC 原理与信号槽底层
完成日期：____年__月__日

- 理解 MOC 工作流程：头文件 -> moc_*.cpp 的生成过程
- 理解 Q_OBJECT 宏展开后生成的代码
- 阅读并理解 moc_*.cpp 文件的内容
- 理解信号槽底层实现：信号 = 普通函数 + QMetaObject::activate()
- 理解五种连接方式的区别并写出示例
- 理解 QueuedConnection 的事件队列 + 参数拷贝机制
- 用 QMetaObject::invokeMethod 做跨线程调用
- 算法 1 题 + 英语 20min

---

### 第 36 周：Qt 事件系统
完成日期：____年__月__日

- 理解 QEventLoop 的 exec() 和 processEvents() 原理
- 清楚区分事件和信号的核心差异（事件可拦截、信号不行）
- 理解 QObject::event() 作为事件分发入口的作用
- 实现一个 eventFilter 监控某个 Widget 的按键事件
- 实现一个自定义事件并发送
- 理解 sendEvent() 和 postEvent() 的区别并写出对比示例
- 理解 paintEvent、resizeEvent、mousePressEvent、keyPressEvent 的调用链
- 理解嵌套事件循环的使用场景和风险
- 算法 1 题 + 英语 20min

---

### 第 37 周：Qt Model/View 框架
完成日期：____年__月__日

- 画出 Model/View/Delegate 三者的关系图
- 实现一个 QAbstractListModel 自定义列表模型
- 实现一个 QAbstractTableModel 自定义表格模型
- 理解 QModelIndex 的 internalPointer() 在树形数据中的用法
- 实现 QStyledItemDelegate 自定义绘制和编辑
- 用 QSortFilterProxyModel 实现排序和过滤
- 理解 beginInsertRows/endInsertRows 的必要性
- 理解 Model/View 中的线程安全注意事项
- 把你项目中一个 QTableWidget 改成 QTableView + 自定义 Model
- 算法 1 题 + 英语 20min

---

### 第 38 周：Qt 容器 vs STL 容器
完成日期：____年__月__日

- 对比 QList vs std::vector 的性能特征
- 对比 QMap vs std::map vs QHash vs std::unordered_map
- 理解 Qt 隐式共享 COW 原理：QSharedData + QSharedDataPointer
- 写出隐式 detach 的触发条件和性能代价
- 理解为什么 const 成员函数不会触发 detach
- 写出隐式 detach 引发 bug 的实际场景
- 了解 Q_DECLARE_TYPEINFO 宏的用法
- 写 benchmark 实测 QVector 隐式 detach 的时间开销
- 算法 1 题 + 英语 20min

---

### 第 39 周：QVariant 与 Qt 类型系统
完成日期：____年__月__日

- 用 QVariant 存储和读取不同类型的数据
- 用 Q_DECLARE_METATYPE 注册自定义类型给 QVariant
- 用 qRegisterMetaType 注册类型以支持跨线程信号槽
- 理解 QMetaType 类的作用
- 用 Q_PROPERTY 宏定义 Qt 属性
- 用 QObject::setProperty() / property() 做动态属性
- 实现一个自定义类型，既能存进 QVariant，又能跨线程传递
- 算法 1 题 + 英语 20min

---

### 第 40 周：Qt 实用功能精讲
完成日期：____年__月__日

- 用 QTimer::singleShot 实现延迟执行
- 用 QTimer 实现心跳检测机制
- 用 QProcess 启动外部程序并读写标准 I/O
- 用 QFile/QDir/QFileInfo 做文件操作
- 用 QTextStream 读写文本文件、QDataStream 读写二进制文件
- 用 QBuffer 在内存中模拟文件 I/O
- 使用 .qrc 资源文件嵌入图片和配置
- 用 QSettings 实现配置存储
- 用 QTemporaryFile 创建临时文件
- 算法 1 题 + 英语 20min

---

## 第八阶段：设计模式与架构设计

### 第 41 周：创建型模式
完成日期：____年__月__日

- 用工厂方法模式重构项目中的 switch-case 创建逻辑
- 实现抽象工厂模式：跨平台 UI 组件示例
- 实现 Mayer's Singleton：线程安全、懒汉式
- 实现双重检查锁定单例的正确写法
- 实现建造者模式：Builder 链式调用
- 实现原型模式：深拷贝 vs 浅拷贝
- 算法 1 题 + 英语 20min

---

### 第 42 周：行为型模式
完成日期：____年__月__日

- 用策略模式重构一个 100 行+ 的多分支函数
- 配合 lambda 使用策略模式
- 用 std::function + std::vector 自己实现观察者模式
- 用命令模式 + QUndoStack 实现撤销/重做
- 了解 QStateMachine 状态机框架
- 算法 1 题 + 英语 20min

---

### 第 43 周：结构型模式与架构原则
完成日期：____年__月__日

- 把一个暴露大量私有成员的头文件用 PIMPL 重构
- 理解适配器模式的典型场景
- 理解装饰器模式和代理模式的区别
- 用 SOLID 原则对你项目中一个模块做 Code Review
- 复盘 CRTP 在静态多态中的应用
- 回顾 23 种设计模式分类（创建型 5、结构型 7、行为型 11）
- 算法 1 题 + 英语 20min

---

## 第九阶段：硬件通信

### 第 44 周：QSerialPort 串口通信
完成日期：____年__月__日

- 用 QSerialPortInfo 枚举本机所有可用串口
- 配置波特率、数据位、校验、停止位、流控
- 实现异步读写：readyRead() 信号方式
- 实现同步读写：waitForReadyRead() 阻塞方式
- 处理串口粘包：实现基于帧头帧尾的协议解析
- 设计多串口并发管理方案
- 理解 volatile 关键字在硬件寄存器映射中的用途
- 能说出 volatile != atomic 的三个原因
- 算法 1 题 + 英语 20min

---

### 第 45 周：工业通信协议概要
完成日期：____年__月__日

- 理解 Modbus RTU/TCP 的主站/从站架构
- 了解常用 Modbus 功能码（01-06、15、16）
- 了解 CAN 总线帧格式组成
- 用 Wireshark 抓一段 Modbus TCP 报文并解析各字段
- 了解 RS232/RS485/RS422 物理层区别
- 算法 1 题 + 英语 20min

---

## 第十阶段：网络编程

### 第 46 周：网络基础与 TCP/UDP
完成日期：____年__月__日

- 画出 OSI 七层模型和 TCP/IP 四层模型的对应关系
- 默画 TCP 三次握手和四次挥手的时序图
- 理解 TCP 状态机各状态的转换条件
- 理解滑动窗口和拥塞控制的原理
- 理解 TIME_WAIT 状态的意义和时间
- 理解 Nagle 算法和延迟确认
- 用 Wireshark 抓一次完整的 HTTP 请求，分析各层数据包
- 算法 1 题 + 英语 20min

---

### 第 47 周：Socket 编程
完成日期：____年__月__日

- 用 QTcpSocket + QTcpServer 实现客户端和服务端
- 理解 SO_REUSEADDR 和 TCP_NODELAY 的作用
- 理解 TCP 分包/粘包的三种解决方案
- 用长度前缀协议解决粘包问题
- 理解网络字节序：写 htonl/ntohl 转换的示例
- 用 QUdpSocket 实现 UDP 通信
- 算法 1 题 + 英语 20min

---

### 第 48 周：HTTP 协议与应用层
完成日期：____年__月__日

- 抓包分析 HTTP 请求/响应的完整格式
- 理解 GET/POST/PUT/DELETE 的语义
- 理解常用状态码含义（200/301/302/400/401/403/404/500）
- 了解 HTTPS/TLS 握手的简化流程
- 用 QNetworkAccessManager 发 GET 和 POST 请求
- 用 QWebSocket 实现双向通信
- 算法 1 题 + 英语 20min

---

### 第 49 周：I/O 多路复用与高性能网络
完成日期：____年__月__日

- 理解 select 的三大局限并写出示例
- 理解 poll 对 select 的改进
- 理解 epoll 的数据结构（红黑树 + 就绪链表）
- 用 epoll 实现边缘触发（ET）模式的服务器
- 对比 ET 和 LT 的行为差异
- 了解 Reactor 模式的事件分发设计
- 了解 libevent、libuv、Boost.Asio 的设计思路
- 算法 1 题 + 英语 20min

---

## 第十一阶段：数据库基础

### 第 50 周：SQL 基础
完成日期：____年__月__日

- 写出 SELECT 语句的完整子句执行顺序
- 写出四种 JOIN 的区别并用示例验证
- 用 GROUP BY + HAVING 做分组统计
- 用子查询和派生表实现复杂查询
- 设计航天测试记录表结构并写出完整 DDL
- 用 BEGIN/COMMIT/ROLLBACK 做事务操作
- 理解四个隔离级别并说出各自的防止问题
- 理解 B+Tree 索引原理和复合索引的最左前缀原则
- 用 EXPLAIN 分析查询计划
- 算法 1 题 + 英语 20min

---

### 第 51 周：Qt 数据库编程
完成日期：____年__月__日

- 用 QSqlDatabase::addDatabase("QSQLITE") 连接数据库
- 用 QSqlQuery::exec() 执行 CRUD 操作
- 用 prepare() + bindValue() 防止 SQL 注入
- 用 transaction()/commit()/rollback() 实现事务
- 用 QSqlTableModel + QTableView 绑定显示数据
- 实现 setFilter/setSort 动态查询
- 实现一个简易测试数据管理系统（增删改查界面）
- 了解数据库连接池的线程安全设计
- 算法 1 题 + 英语 20min

---

## 第十二阶段：Qt 图形与渲染

### 第 52 周：自定义绘制与 QGraphicsView
完成日期：____年__月__日

- 理解 QPainter 三板斧：paint device、QPainter、QPainter 设置
- 用 QPainter 绘制直线、矩形、椭圆、文字、路径
- 理解 QPen 和 QBrush 的渐变效果
- 理解坐标变换：translate/rotate/scale/shear
- 用 save()/restore() 保存和恢复绘制状态
- 实现双缓冲绘制消除闪烁
- 实现一个实时波形显示控件
- 用 QGraphicsView 实现可拖拽缩放的画布
- 理解 QGraphicsItem 的选中、拖拽、碰撞检测
- 算法 1 题 + 英语 20min

---

### 第 53 周：OpenGL 基础与 Qt 集成
完成日期：____年__月__日

- 画出 OpenGL 渲染管线各阶段流程图
- 理解 VAO/VBO/EBO 三者的关系
- 编写并编译一个简单的顶点着色器和片段着色器
- 理解模型/视图/投影矩阵的作用
- 用 glm 库做矩阵运算
- 用 QOpenGLWidget 绘制一个旋转的彩色三角形
- 加载纹理图片并在 OpenGL 中显示
- 了解 QPainter 与 OpenGL 混合绘制
- 算法 1 题 + 英语 20min

---

## 第十三阶段：软件测试

### 第 54 周：单元测试基础
完成日期：____年__月__日

- 用 GoogleTest 写 TEST() 宏测试用例
- 用 EXPECT_EQ/ASSERT_EQ 的区别写测试
- 用 TEST_F() + SetUp()/TearDown() 做夹具测试
- 用 EXPECT_DEATH 验证崩溃逻辑
- 理解 Mock 和 Stub 的区别
- 用 GoogleMock 写 Mock 类
- 用 QTest 写 Qt 组件的单元测试
- 用 QTest::keyClick/mouseClick 模拟用户操作
- 算法 1 题 + 英语 20min

---

### 第 55 周：测试实践与 TDD
完成日期：____年__月__日

- 理解 TDD 的三步骤循环
- 为你之前写的线程池项目写完整 gtest 测试套件
- 在 CMake 中集成 gtest：FetchContent + enable_testing + add_test
- 用 gcov/lcov 生成覆盖率报告
- 为一个纯逻辑类走完 TDD 完整流程
- 总结：什么样的代码容易测试、什么样的难
- 算法 1 题 + 英语 20min

---

## 第十四阶段：日志系统

### 第 56 周：日志系统设计
完成日期：____年__月__日

- 设计日志级别体系：TRACE/DEBUG/INFO/WARN/ERROR/FATAL
- 设计日志内容格式：时间戳 + 线程ID + 级别 + 文件:行号 + 消息
- 画出同步日志 vs 异步日志的架构对比图
- 用生产者-消费者模式实现异步日志框架
- 实现滚动日志：按大小切割 + 保留最近 N 个文件
- 实现线程安全的 LOG_INFO() 宏
- 用 qInstallMessageHandler 接管 Qt 日志
- 阅读 spdlog 源码，学习其设计思路
- 算法 1 题 + 英语 20min

---

### 第 57 周：日志库完善（轮子项目 2）
完成日期：____年__月__日

- 实现自定义日志格式化 pattern
- 实现多 sink：同时输出到控制台和文件
- 给日志库写 benchmark
- 对比你的日志库和 spdlog 的性能
- 上传到 GitHub，写 README
- 算法 1 题 + 英语 20min

---

## 第十五阶段：序列化与配置管理

### 第 58 周：JSON 与 XML
完成日期：____年__月__日

- 用 QJsonDocument::fromJson() 解析 JSON 字符串
- 用 QJsonObject/QJsonArray 遍历和操作 JSON 数据
- 用 toJson() 将对象序列化为 JSON
- 用 QDomDocument 解析 XML
- 了解 nlohmann/json 库的用法
- 把你项目的配置文件格式从 ini 改为 JSON
- 算法 1 题 + 英语 20min

---

### 第 59 周：二进制序列化与配置管理
完成日期：____年__月__日

- 用 QDataStream 实现类的二进制序列化和反序列化
- 注意 QDataStream 版本号管理
- 用 QByteArray 手动解析二进制协议帧
- 用 QBuffer 在内存中测试序列化代码
- 用 qToLittleEndian/qFromBigEndian 处理字节序
- 设计一个完整的二进制通信协议并实现编解码
- 用 QSettings 管理分组配置
- 了解 Protobuf 的 .proto 定义和编译流程
- 算法 1 题 + 英语 20min

---

## 第十六阶段：性能优化

### 第 60 周：性能测试与基准
完成日期：____年__月__日

- 用 Google Benchmark 写性能基准测试
- 对比 std::vector vs QVector 的插入/删除性能
- 对比 QStringBuilder 和传统 + 操作符的性能
- 对比手写 for vs STL 算法的性能
- 对比值传递 vs 引用传递 vs 移动传递的性能
- 算法 1 题 + 英语 20min

---

### 第 61 周：性能分析工具
完成日期：____年__月__日

- 用 Visual Studio 性能探查器分析 CPU 采样
- 理解自顶向下法定位热点
- 理解二分法定位热点
- 找一个你项目中的慢操作，找到热点函数并记录
- 了解 perf（Linux）和火焰图的基本使用
- 算法 1 题 + 英语 20min

---

### 第 62 周：常见性能优化策略
完成日期：____年__月__日

- 理解数据局部性：用一个连续数组 vs 链表的 benchmark 验证
- 理解 false sharing：写多线程 benchmark 验证缓存行对齐效果
- 用对象池减少动态分配
- 用 string_view 减少字符串拷贝
- 用 -O2/-O3 选项对比性能
- 了解 PGO（Profile-Guided Optimization）的基本思路
- 对项目中一个模块做完整的性能优化，记录优化前后数据
- 算法 1 题 + 英语 20min

---

## 第十七阶段：编译构建与工程化

### 第 63 周：CMake 精通
完成日期：____年__月__日

- 掌握 CMake 核心语法：set/list/if/foreach/function
- 用 add_executable 和 add_library 构建项目
- 理解 target_include_directories 的 PUBLIC/PRIVATE/INTERFACE 语义
- 理解 target_link_libraries 的三种可见性
- 用 find_package 查找 Qt
- 用 add_subdirectory 管理子模块
- 集成 AUTOMOC/AUTOUIC/AUTORCC
- 算法 1 题 + 英语 20min

---

### 第 64 周：CMake 进阶
完成日期：____年__月__日

- 配置 CMakePresets.json 标准化构建
- 用 FetchContent 自动下载 GoogleTest
- 用 CTest 跑单元测试
- 用 install 导出库和头文件
- 用 CPack 打包安装包
- 了解 Generator expressions 的用法
- 算法 1 题 + 英语 20min

---

### 第 65 周：静态分析与代码质量
完成日期：____年__月__日

- 配置 clang-tidy 集成到 CMake
- 配置 clang-format 统一代码风格
- 把 clang-format 集成到 git pre-commit hook
- 用 gcov/lcov 生成覆盖率报告
- 写一个 GitHub Actions workflow 做自动构建和测试
- 了解 ASan/TSan/UBSan 的启用方式
- 算法 1 题 + 英语 20min

---

### 第 66 周：大型工程模块拆分
完成日期：____年__月__日

- 设计模块目录结构：每个模块一个 CMakeLists.txt
- 设计纯虚接口层隔离模块
- 理解 DLL 导出符号：__declspec(dllexport/dllimport)
- 解决循环依赖：提取公共接口、依赖倒置
- 理解语义化版本 MAJOR.MINOR.PATCH
- 理解 ABI 兼容性：哪些改动破坏 ABI
- 把一个单体项目拆成 core.dll + plugin.dll 结构
- 算法 1 题 + 英语 20min

---

## 第十八阶段：Git 进阶

### 第 67 周：Git 进阶
完成日期：____年__月__日

- 理解 Git 内部对象模型：blob/tree/commit/tag
- 用 git rebase -i 合并/修改/删除/重排提交
- 用 git cherry-pick 跨分支移植提交
- 用 git bisect 二分法定位 bug 提交（真实项目演练）
- 用 git reflog 找回误删的分支
- 了解 git submodule / subtree 的使用场景
- 按 Conventional Commits 规范重写项目的提交信息
- 算法 1 题 + 英语 20min

---

## 轮子项目完成记录

- 通用线程池 --------------- 完成日期：________ | GitHub: ________
- 异步日志库 --------------- 完成日期：________ | GitHub: ________
- 并发环形缓冲区 ----------- 完成日期：________ | GitHub: ________
- 简易 Modbus 调试工具 ----- 完成日期：________ | GitHub: ________
- 自定义 TableModel+Delegate 完成日期：________ | GitHub: ________
- 简易 TCP 聊天室 ---------- 完成日期：________ | GitHub: ________
- 测试数据管理系统 --------- 完成日期：________ | GitHub: ________
- 实时波形显示控件 --------- 完成日期：________ | GitHub: ________
- PIMPL+设计模式示例集 ----- 完成日期：________ | GitHub: ________
- 简易 epoll 服务器 -------- 完成日期：________ | GitHub: ________
- OpenGL 3D 数据可视化 ----- 完成日期：________ | GitHub: ________
- JSON 配置迁移工具 --------- 完成日期：________ | GitHub: ________

---

## 书籍阅读进度

- 《Effective Modern C++》 已读条款：__ / 42 | 完成日期：________
- 《C++ Concurrency in Action》已读章节：__ / __ | 完成日期：________
- 《深入理解计算机系统》CSAPP 已读章节：__ / __ | 完成日期：________
- 《Linux/UNIX 系统编程手册》已读章节：__ / __ | 完成日期：________
- 《TCP/IP 详解 卷 1》已读章节：__ / __ | 完成日期：________
- 《Head First 设计模式》已读章节：__ / __ | 完成日期：________
- 《C++17 STL Cookbook》已读章节：__ / __ | 完成日期：________
- 《labuladong 的算法小抄》已读章节：__ / __ | 完成日期：________

---

## 面试准备记录

- 目标公司列表整理 -------- 完成日期：________
- 简历更新 --------------- 完成日期：________
- 投递 C 类公司练手 ------- 完成日期：________ | 反馈总结：________
- 投递 B 类公司 ----------- 完成日期：________ | 反馈总结：________
- 投递 A 类公司 ----------- 完成日期：________ | 反馈总结：________
- 投递 S 类公司 ----------- 完成日期：________ | 反馈总结：________

---

## 使用说明

1. 每天先完成"每日例行"：算法 1 题 + 英语 20min
2. 然后完成当周所列任务，完成后勾选 [x]
3. 每完成一项，填写完成日期
4. 每周结束时，回顾本周所有任务是否全部完成
5. 每个阶段结束时，用 learning-roadmap.md 中的里程碑自测题检验掌握程度
6. 轮子项目完成后立即上传 GitHub，填写链接
