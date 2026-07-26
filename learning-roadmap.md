# C++ Qt 工程师提升路线图

## 个人画像
- 1 年 C++ Qt Widgets 桌面应用开发经验
- 航天测试软件开发（维护为主）
- 目标：上海中高级 C++/Qt 岗位，涨薪
- 平台：Windows 为主
- 日均学习时间：2 小时
- 总周期：约 67 周（12~14 个月）

---

## 阶段一：C++ 类型系统与语言深度 —— 第 1~10 周

### 第 1 周：const 正确性
- const 修饰变量：const int*、int* const、const int* const
- const 成员函数与 mutable
- 逻辑 const 与物理 const
- 顶层 const 与底层 const
- constexpr 变量与函数基础

### 第 2 周：类型转换与 explicit
- static_cast：编译期转换、父类子类互转
- dynamic_cast：运行期多态转换、需要虚函数
- const_cast：移除 const/volatile
- reinterpret_cast：重新解释比特位
- explicit 关键字：禁止隐式转换
- C 风格转换的缺陷

### 第 3 周：运算符重载
- 哪些运算符可以/不可以重载
- 算术运算符：成员函数 vs 友元函数
- 比较运算符、赋值运算符、copy-and-swap idiom
- 下标运算符 operator[] 的 const 重载
- 类型转换运算符 explicit operator bool()
- 不应该重载的：&& || ，（短路逻辑丢失）

### 第 4 周：智能指针
- unique_ptr：独占所有权、make_unique、自定义 deleter
- shared_ptr：引用计数、make_shared 内存优化
- weak_ptr：打破循环引用、lock()、expired()
- enable_shared_from_this（CRTP 实现原理）
- unique_ptr 与 PIMPL 的结合
- shared_ptr 的 aliasing constructor
- Qt 混用：QPointer（weak ptr）、QSharedPointer

### 第 5 周：移动语义
- 左值 vs 右值的本质
- std::move 只是类型转换
- 移动构造/赋值的手写规则
- noexcept 对 vector resize 的性能影响
- std::forward 与完美转发
- RVO/NRVO 返回值优化
- 三五法则（Rule of Five）与零法则（Rule of Zero）
- copy-and-swap idiom

### 第 6 周：Lambda 与 std::function
- Lambda 完整语法：[capture](params) mutable -> ret { body }
- 捕获列表：= & this *this init capture
- 泛型 lambda：[](auto x) {}
- Lambda 底层：编译器生成匿名仿函数类
- std::function：类型擦除、性能开销
- std::bind 的占位符 _1 _2 与陷阱
- Qt 信号槽中的 lambda：生命周期安全、contextObject 参数

### 第 7 周：STL 算法
- 非修改类：find、find_if、count、count_if、all_of、any_of、none_of
- 修改类：copy、copy_if、transform、replace、remove+erase idiom
- 排序与分区：sort、stable_sort、partial_sort、nth_element、partition
- 数值类：accumulate、inner_product、partial_sum
- 集合类：set_union、set_difference
- 堆类：make_heap、push_heap、pop_heap、std::priority_queue
- for_each vs range-based for vs 算法
- std::clamp、std::minmax、std::sample

### 第 8 周：编译链接模型
- 翻译单元：.cpp 到目标文件的全过程
- ODR 规则：一个定义规则
- 头文件守卫：#ifndef vs #pragma once
- 为什么模板必须在头文件中
- inline 关键字的三个含义
- extern template：显式实例化
- 链接阶段：name mangling、符号解析、静态/动态链接

### 第 9 周：虚函数底层机制
- vtable 与 vptr 的内存布局
- 虚函数调用开销：两次间接跳转
- 去虚拟化（devirtualization）
- 纯虚函数与抽象类
- 虚析构函数为什么必须
- 多继承下的虚表结构：多个 vptr、thunk
- 虚继承：菱形继承问题
- 用 godbolt.org 观察虚表汇编

### 第 10 周：C++ 异常安全
- 三个保证级别：no-throw、strong、basic
- noexcept 规范：声明 + noexcept() 操作符
- 构造函数中抛异常的后果
- 析构函数不应抛异常（noexcept(true) 默认）
- RAII 与异常安全
- std::uncaught_exceptions()

---

## 阶段二：C++ 模板系统学习 —— 第 11~15 周

### 第 11 周：函数模板基础
- template typename T 语法
- 隐式实例化与显式实例化
- 模板参数类型推导规则
- 函数模板全特化
- 函数模板重载决议

### 第 12 周：类模板
- 类模板定义与成员函数外部定义
- 成员函数延迟实例化
- 别名模板 template using
- 模板模板参数
- 实现 MyStack T 类模板

### 第 13 周：Variadic Templates 与折叠表达式
- 可变参数模板语法：typename... Args
- 递归展开模式：头元素 + 递归剩余
- C++17 折叠表达式四种方向
- sizeof...(Args)
- std::tuple 的简单实现
- 实现 printAll(args...) 函数

### 第 14 周：Type Traits 与 SFINAE
- type_traits 常用：is_same、is_base_of、is_convertible、is_integral
- remove_reference、decay、enable_if
- SFINAE 概念：替换失败不是错误
- enable_if 的三种用法
- std::void_t 的妙用
- std::conditional

### 第 15 周：CRTP 与静态多态
- CRTP：class Derived : public Base Derived
- 编译期多态原理
- enable_shared_from_this 的实现原理
- 编译期虚函数替代（无 vtable 开销）
- Mixin 模式
- 手写微型 enable_shared_from_this

---

## 阶段三：API 设计 + C++ 新特性 + 工具库 —— 第 16~18 周

### 第 16 周：API 设计原则
- 参数传递规则：const T&、按值+sink、T&、const T*、std::optional T
- 返回值策略：RVO、不 std::move 返回值、std::optional 表示可能失败
- 错误处理选择：异常 vs std::error_code vs std::optional vs bool
- 接口最小化原则
- Doxygen 基础：@brief @param @return @throw

### 第 17 周：C++11/14/17 特性精讲
- enum class vs 传统 enum
- auto 与 decltype(auto) 区别
- decltype 的两种规则
- 结构化绑定 auto [x, y] = pair
- if constexpr：编译期分支
- if/switch 初始化语句
- Range-based for 陷阱详解
- static_assert

### 第 18 周：std::filesystem、std::chrono、std::regex
- std::filesystem::path：路径操作
- directory_iterator 遍历目录
- std::chrono::duration：时间单位
- std::chrono::time_point 与 clock
- steady_clock vs system_clock vs high_resolution_clock
- std::regex_match / regex_search / regex_replace

---

## 阶段四：多线程与并发 —— 第 19~26 周

### 第 19 周：线程基础
- std::thread 创建与生命周期
- join() vs detach()、joinable()
- thread_local 线程局部存储
- std::this_thread::sleep_for、yield
- hardware_concurrency()
- Qt：QThread 两种用法（继承 vs moveToThread）

### 第 20 周：互斥量与锁
- std::mutex、std::recursive_mutex
- std::timed_mutex：try_lock_for
- std::lock_guard：最简单的 RAII 锁
- std::unique_lock：可延迟加锁、与条件变量配合
- std::scoped_lock（C++17）：同时锁多个 mutex
- std::shared_mutex（C++17）：读写锁
- std::lock() 全局函数
- 死锁四个必要条件

### 第 21 周：条件变量
- std::condition_variable：wait()、notify_one()、notify_all()
- 虚假唤醒：为什么 wait 必须带谓词
- wait(lock, predicate) 的正确写法
- 丢失唤醒问题
- 实现生产者-消费者环形缓冲区
- 实现 BlockingQueue T

### 第 22 周：Future 与异步
- std::async：launch::async vs launch::deferred、默认策略陷阱
- std::future：get()、wait_for()
- std::shared_future：多个等待者
- std::promise：手动设置值/异常
- std::packaged_task
- Qt：QtConcurrent::run、QFuture、QFutureWatcher

### 第 23 周：原子操作与无锁编程
- std::atomic T：load()、store()、exchange()
- 内存序：relaxed、acquire/release、seq_cst
- CAS compare_exchange_weak vs _strong
- ABA 问题
- std::atomic_flag 自旋锁
- fetch_add/fetch_sub 锁无关计数器
- 无锁栈（单生产者单消费者）

### 第 24 周：手写线程池（核心项目 1）
- 任务队列、工作线程管理
- submit(callable, args...) 返回 std::future result
- std::packaged_task 类型擦除
- 优雅关闭：shutdown() 等待任务完成、shutdown_now() 丢弃
- 异常处理：任务中抛异常传到调用者
- False sharing 与缓存行对齐

### 第 25 周：Qt 多线程深入
- QThread::moveToThread 正确用法
- 跨线程信号槽：AutoConnection 默认、QueuedConnection、BlockingQueuedConnection
- QMetaObject::invokeMethod
- QObject 线程亲和性
- QThreadPool + QRunnable
- QtConcurrent：run、map、filter
- QMutex、QMutexLocker、QReadWriteLock、QWaitCondition
- GUI 线程规则：UI 操作必须在主线程

### 第 26 周：并发排查与性能分析
- ThreadSanitizer（TSan）
- perf / VTune：锁争用热点分析
- 锁的粒度：粗粒度 vs 细粒度
- 减少锁争用：读写锁、数据分片、per-thread 数据、double buffering

---

## 阶段五：操作系统基础 —— 第 27~30 周

### 第 27 周：进程与线程底层
- 进程 vs 线程本质区别
- 虚拟内存：页表、TLB、缺页中断
- 用户态 vs 内核态：系统调用开销
- 上下文切换的具体开销
- IPC 通信方式：管道、共享内存、消息队列、Socket

### 第 28 周：内存管理底层
- 虚拟地址空间布局：代码段、数据段、BSS、堆、栈、mmap
- malloc/free 底层：ptmalloc、brk vs mmap
- 内存碎片：内部 vs 外部
- 栈帧结构：ebp/esp
- TCMalloc/jemalloc 简介

### 第 29 周：锁的底层实现
- futex（Linux）、Critical Section（Windows）
- 自旋锁 vs 互斥锁对比
- 信号量内核级实现
- 读写锁饥饿问题
- 缓存一致性协议 MESI

### 第 30 周：I/O 模型
- 阻塞 I/O vs 非阻塞 I/O
- 五种 I/O 模型
- select、poll、epoll 原理与优缺点
- epoll ET vs LT
- 零拷贝：sendfile、splice、mmap

---

## 阶段六：内存管理与调试 —— 第 31~34 周

### 第 31 周：C++ 内存模型与 RAII
- C++ 对象生命周期完整调用链
- RAII 原则：谁分配谁释放
- placement new
- 内存对齐：alignof、alignas
- SSO 小字符串优化
- 空基类优化 EBO
- 虚函数表内存布局

### 第 32 周：内存泄漏检测
- AddressSanitizer（ASan）：堆溢出、栈溢出、use-after-free、double-free
- Valgrind/Memcheck（Linux）
- Windows CRT 内存泄漏检测：_CrtSetDbgFlag
- shared_ptr 循环引用检测

### 第 33 周：高级调试技巧
- GDB：条件断点、watchpoint、catch throw、core dump
- WinDbg：符号加载、dump 分析、!analyze -v
- 多线程调试：查看所有线程、切换上下文、检测死锁
- 性能断点：perf record / perf report / 火焰图
- strace/ltrace（Linux）

### 第 34 周：Qt 内存管理专讲
- QObject 父子树机制：setParent、析构顺序、findChild/findChildren
- deleteLater() 原理与 delete 的区别
- QWidget 特殊销毁：WA_DeleteOnClose
- QSharedPointer vs std::shared_ptr
- 隐式共享（COW）：QString、QByteArray、QImage
- 隐式 detach 触发条件
- QScopedPointer、QPointer
- 信号槽 lambda 捕获 this 的安全检查

---

## 阶段七：Qt 深入 —— 第 35~40 周

### 第 35 周：Qt MOC 原理与信号槽底层
- MOC 工作流程：解析头文件、生成 moc_*.cpp
- Q_OBJECT 宏展开：staticMetaObject、metaObject()、qt_metacall()
- 信号槽底层：信号 = 普通函数 + QMetaObject::activate()
- 五种连接方式：直接、队列、阻塞队列、自动、唯一
- QueuedConnection 内部实现：事件队列 + 参数拷贝
- QMetaObject::Connection 与 disconnect()

### 第 36 周：Qt 事件系统
- QEventLoop 原理：processEvents()、exec()
- 事件 vs 信号的区别
- QObject::event() 分发函数
- QObject::eventFilter() 事件过滤器
- QObject::customEvent() 自定义事件
- sendEvent() vs postEvent()：同步 vs 异步
- paintEvent、resizeEvent、mousePressEvent、keyPressEvent 调用链
- 嵌套事件循环的使用场景与风险

### 第 37 周：Qt Model/View 框架
- 框架结构：Model、View、Delegate
- QAbstractItemModel 纯虚接口：index()、parent()、rowCount()、columnCount()、data()
- QAbstractListModel：只需 rowCount + data
- QAbstractTableModel：表格模型
- QModelIndex 的 internalPointer()
- QStyledItemDelegate：自定义 paint()、createEditor()
- QSortFilterProxyModel：排序 + 过滤
- beginInsertRows/endInsertRows 通知 View 数据变更
- Model/View 中的线程安全注意事项

### 第 38 周：Qt 容器 vs STL 容器
- QList vs std::vector 对比
- QMap vs std::map vs QHash vs std::unordered_map 性能对比
- Qt 隐式共享 COW 实现原理：QSharedData + QSharedDataPointer
- 隐式 detach 触发条件与代价
- 隐式 detach 引发的常见 bug
- const 成员函数不触发 detach
- Q_DECLARE_TYPEINFO 宏

### 第 39 周：QVariant 与 Qt 类型系统
- QVariant：内部用 union + type tag
- QVariant::canConvert T 与 value T
- Q_DECLARE_METATYPE 宏
- qRegisterMetaType T：跨线程信号槽的前提
- QMetaType：运行时类型构造/析构
- Q_PROPERTY 宏与属性系统
- QObject::setProperty() / property() 动态属性

### 第 40 周：Qt 实用功能精讲
- QTimer：singleShot、start/stop、定时器类型
- QProcess：启动外部程序、start() vs execute()、读写标准 IO
- 文件操作：QFile/QDir/QFileInfo
- QTextStream 文本流、QDataStream 二进制流
- QBuffer：QByteArray 模拟 QIODevice
- .qrc 资源文件系统
- QTemporaryFile / QTemporaryDir
- QSettings：跨平台配置存取

---

## 阶段八：设计模式与架构设计 —— 第 41~43 周

### 第 41 周：创建型模式
- 工厂方法模式
- 抽象工厂模式
- 单例模式：Meyers' Singleton（C++11 线程安全）
- 建造者模式：链式调用
- 原型模式

### 第 42 周：行为型模式
- 策略模式：替代 if-else/switch
- 观察者模式：Qt 信号槽的底层思想
- 命令模式：QUndoCommand/QUndoStack
- 状态模式：QStateMachine 框架

### 第 43 周：结构型模式与架构原则
- PIMPL（编译防火墙）
- 适配器模式
- 装饰器模式
- 代理模式
- SOLID 原则：单一职责、开闭原则、里氏替换、接口隔离、依赖倒置
- CRTP 应用模式回顾（编译期多态）

---

## 阶段九：硬件通信 —— 第 44~45 周

### 第 44 周：QSerialPort 串口通信
- QSerialPortInfo::availablePorts() 查找串口
- 串口配置：波特率、数据位、校验位、停止位、流控
- 异步读写：readyRead() 信号、超时处理
- 串口粘包/拆包：长度前缀、帧头帧尾
- 多串口并发管理策略
- volatile 关键字：硬件寄存器映射
- volatile != atomic：不保证多线程安全

### 第 45 周：工业通信协议概要
- Modbus RTU / Modbus TCP 组件架构：主站/从站、功能码、寄存器地址
- CAN 总线基础：帧格式、CAN ID、差分信号
- 用 Wireshark 抓包分析 Modbus TCP 报文

---

## 阶段十：网络编程 —— 第 46~49 周

### 第 46 周：网络基础与 TCP/UDP
- OSI 七层模型 vs TCP/IP 四层模型
- IP 协议基础：IP 地址、子网掩码、路由
- TCP 详解：三次握手、四次挥手、状态机
- TCP 机制：滑动窗口、拥塞控制、Nagle 算法、延迟确认
- TIME_WAIT 状态的意义
- UDP：无连接、不可靠、适用场景

### 第 47 周：Socket 编程
- Socket API：socket()、bind()、listen()、accept()、connect()、send()/recv()
- 阻塞 vs 非阻塞 Socket
- Socket 选项：SO_REUSEADDR、SO_KEEPALIVE、TCP_NODELAY
- TCP 分包/粘包：长度前缀、分隔符、定长包
- 网络字节序：htonl/htons/ntohl/ntohs
- Qt Socket：QTcpSocket、QTcpServer、QUdpSocket

### 第 48 周：HTTP 协议与应用层
- HTTP/1.1 请求/响应格式
- GET/POST/PUT/DELETE 方法
- 状态码分类
- HTTPS/TLS 握手流程（了解）
- QNetworkAccessManager、QNetworkRequest、QNetworkReply
- WebSocket 与 QWebSocket

### 第 49 周：I/O 多路复用与高性能网络
- select 的局限：fd_set 大小、O(n) 遍历
- poll：无 fd 数量限制
- epoll（Linux）：epoll_create/epoll_ctl/epoll_wait、O(1) 就绪通知
- ET vs LT：边缘触发 vs 水平触发
- Reactor 模式：单线程 + epoll、事件分发
- 开源库简介：libevent、libuv、Boost.Asio

---

## 阶段十一：数据库基础 —— 第 50~51 周

### 第 50 周：SQL 基础
- 核心语句：SELECT、INSERT、UPDATE、DELETE
- 表设计：主键、外键、索引、约束
- 连接查询：INNER/LEFT/RIGHT/FULL JOIN
- 聚合函数：COUNT/SUM/AVG/MAX/MIN
- 子查询与派生表
- 事务 ACID：BEGIN/COMMIT/ROLLBACK
- 隔离级别：读未提交/读已提交/可重复读/串行化
- 索引原理：B+Tree、聚簇索引 vs 非聚簇索引、最左前缀原则

### 第 51 周：Qt 数据库编程
- Qt SQL 模块：QSqlDatabase、QSqlQuery、QSqlTableModel
- connect + QSQLITE
- QSqlQuery::exec()、prepare() + bindValue() 防注入
- QSqlDatabase::transaction()/commit()/rollback()
- QSqlTableModel + QTableView 绑定
- setFilter/setSort、select()/submitAll()
- 数据库连接池设计

---

## 阶段十二：Qt 图形与渲染 —— 第 52~53 周

### 第 52 周：自定义绘制与 QGraphicsView
- QPainter 绘制模型：paint device
- 基本绘制：直线、矩形、椭圆、多边形、文字、QPainterPath
- QPen 与 QBrush：渐变（线性/辐射/锥形）
- 坐标变换：平移/旋转/缩放/剪切、save()/restore()
- 抗锯齿与透明度
- 双缓冲绘制防闪烁
- QGraphicsView 框架：QGraphicsScene、QGraphicsView、QGraphicsItem
- 图元交互：选中、拖拽、碰撞检测
- 坐标系统：逻辑坐标 vs 物理坐标、DPI 缩放

### 第 53 周：OpenGL 基础与 Qt 集成
- 渲染管线：顶点着色器、图元装配、光栅化、片段着色器
- VAO/VBO/EBO
- 变换矩阵：模型/视图/投影、glm 库
- QOpenGLWidget、QOpenGLFunctions
- QPainter 与 OpenGL 混合绘制
- 基础纹理映射
- learnopengl.com 教程

---

## 阶段十三：软件测试 —— 第 54~55 周

### 第 54 周：单元测试基础
- GoogleTest：TEST() 宏、EXPECT_EQ/ASSERT_EQ
- Test Fixture TEST_F()、SetUp()/TearDown()
- 死亡测试 EXPECT_DEATH
- GoogleMock：Mock 验证行为、Stub 提供数据
- 测试覆盖率：gcov/lcov
- QTest：QTEST_MAIN、QTest::keyClick、QTest::mouseClick

### 第 55 周：测试实践与 TDD
- TDD 三步骤：Red、Green、Refactor
- TDD 价值与局限
- 什么样的代码难以测试
- 线程池项目完整测试套件
- CMake 集成 gtest：FetchContent、enable_testing、add_test

---

## 阶段十四：日志系统 —— 第 56~57 周

### 第 56 周：日志系统设计
- 日志级别：TRACE/DEBUG/INFO/WARN/ERROR/FATAL
- 日志内容：时间戳、线程 ID、级别、文件/行号、消息体
- 同步日志 vs 异步日志
- 异步日志架构：生产者-消费者模式
- 滚动日志：按大小/时间切分
- 线程安全的日志宏
- qInstallMessageHandler 拦截 Qt 日志
- spdlog 简要了解

### 第 57 周：日志库完善
- 日志格式化：自定义 pattern
- 多 sink：控制台 + 文件
- 性能 benchmark
- 完整轮子项目：异步日志库

---

## 阶段十五：序列化与配置管理 —— 第 58~59 周

### 第 58 周：JSON 与 XML
- QJsonDocument：fromJson() / toJson()
- QJsonObject/QJsonArray 操作
- Qt XML：QDomDocument DOM 方式
- nlohmann/json 了解

### 第 59 周：二进制序列化与配置管理
- QDataStream：二进制序列化、版本号管理
- QByteArray 二进制协议解析
- QBuffer：QByteArray 模拟 I/O
- 字节序处理：qToLittleEndian、qFromBigEndian
- QSettings 深入：注册表 vs ini、group 作用域
- Protobuf 简要了解
- 设计二进制通信协议：帧头 + 长度 + 类型 + 负载 + 校验

---

## 阶段十六：性能优化 —— 第 60~62 周

### 第 60 周：性能测试与基准
- Google Benchmark：BENCHMARK()、参数化测试
- 对比测试：std::vector vs QVector、QStringBuilder、STL 算法

### 第 61 周：性能分析工具
- Visual Studio 性能探查器
- Very Sleepy、VTune（Windows）
- perf（Linux）：record/report/火焰图
- 定位热点：自顶向下法、二分法

### 第 62 周：常见性能优化策略
- 缓存友好：数据局部性、字段重排、false sharing 对齐
- 减少内存分配：对象池、预分配 reserve()、string_view
- 减少拷贝：移动语义、RVO、const 引用
- 编译器优化：-O2/-O3、PGO、LTO
- 避免不必要的虚函数调用

---

## 阶段十七：编译构建与工程化 —— 第 63~66 周

### 第 63 周：CMake 精通
- 核心语法：变量、条件、循环、函数
- add_executable、add_library
- target_include_directories、target_link_libraries
- PUBLIC/PRIVATE/INTERFACE 语义（最重要）
- find_package：Config 模式 vs Module 模式
- add_subdirectory、install
- Qt 集成：AUTOMOC、AUTOUIC、AUTORCC
- 跨平台构建

### 第 64 周：CMake 进阶
- CMake Presets（CMakePresets.json）
- FetchContent：自动下载依赖
- CPack：打包生成安装包
- Generator expressions
- CTest + GoogleTest 集成

### 第 65 周：静态分析与代码质量
- clang-tidy 集成 CMake
- clang-format + .clang-format 配置
- 代码覆盖率：gcov/lcov
- CI 基础：GitHub Actions / GitLab CI
- Sanitizers：ASan、TSan、UBSan

### 第 66 周：大型工程模块拆分
- 按功能划分目录、每个模块一个 CMakeLists.txt
- 接口层设计：纯虚接口、DLL 导出符号
- 循环依赖解法：提取公共接口、依赖倒置、回调接口
- 版本号管理：语义化版本 MAJOR.MINOR.PATCH
- 二进制兼容性（ABI）

---

## 阶段十八：Git 进阶 —— 第 67 周

- Git 内部原理：blob、tree、commit、tag、HEAD
- 分支策略：Git Flow、Trunk-Based Development
- git rebase -i：合并/修改/删除/重排提交
- git cherry-pick
- git bisect：二分法定位 bug 提交
- git reflog：找回误删提交
- git submodule / subtree
- .gitignore 与 Conventional Commits

---

## 阶段十九：算法数据结构（贯穿全程）

- 每天 30 分钟，1 题
- LeetCode Hot 100 + 剑指 Offer
- 分类：数组/链表/哈希表/栈队列/双指针/二叉树/回溯/DP/贪心/位运算/图/排序搜索
- 方法：先想 10 分钟、写代码、AC 后看题解、第二天重写

---

## 阶段二十：英语提升（贯穿全程）

- 每天 20 分钟
- 第 1~12 周：读英文技术文档（cppreference、Qt 文档、《Effective Modern C++》原版）
- 第 13~24 周：加英文技术演讲（CppCon/CppNow）
- 第 25 周后：用英文写 README、尝试英文回答 Stack Overflow

---

## 轮子项目清单

### 最高优先级（必做）
- 通用线程池（C++17、多线程、future、packaged_task）
- 异步日志库（多线程、环形缓冲区、文件 I/O）

### 高优先级
- 并发环形缓冲区（atomic、lock-free、内存序）
- 简易 Modbus 调试工具 Qt（QSerialPort、QByteArray、协议解析）
- 自定义 TableModel + Delegate Qt（Model/View、排序过滤）

### 中优先级
- 简易 TCP 聊天室 Qt（QTcpSocket、多线程、自定义协议）
- 测试数据管理系统 Qt + SQLite（QSqlDatabase、MVC、事务）
- 实时波形显示控件 Qt（QPainter、双缓冲、坐标变换）
- PIMPL + 设计模式示例集（PIMPL、策略、命令、工厂、SOLID）
- 简易 epoll 服务器（epoll、Reactor、非阻塞 I/O）
- OpenGL 3D 数据可视化（QOpenGLWidget、变换矩阵、着色器）

### 低优先级
- JSON 配置文件迁移工具（QJsonDocument、QSettings、序列化）

---

## 学习资源清单

### 必读书籍（按阅读顺序）
- 《Effective Modern C++》（C++11/14 最佳实践）
- 《C++ Concurrency in Action》（C++ 并发圣经）
- 《深入理解计算机系统》CSAPP 第 8~11 章（操作系统）
- 《Linux/UNIX 系统编程手册》（系统调用参考）
- 《TCP/IP 详解 卷 1》（网络协议）
- 《Head First 设计模式》（设计模式入门）
- 《C++17 STL Cookbook》（STL 实战）
- 《labuladong 的算法小抄》（算法刷题）

### 参考书籍（按需查阅）
- 《设计模式：可复用面向对象软件的基础》GoF
- 《UNIX 网络编程 卷 1》
- cppreference.com（C++ 标准库字典）
- learnopengl.com（OpenGL 入门）
- godbolt.org（编译器汇编分析）

---

## 求职策略

### 目标公司分级
- S 级自动驾驶/量化：蔚来、小鹏、地平线、量化私募（30~60k+）
- A 级工业软件/EDA：华大九天、芯华章、合见工软（25~40k）
- A 级半导体测试设备：中微、盛美、华峰测控（22~35k）
- B 级外资工业/医疗：西门子、蔡司、罗氏、美敦力（20~35k）
- C 级传统软件公司：万得、恒生电子、泛微（18~28k）

### 投递节奏
- 现在 ~ 第 26 周：不投简历，全力学习，完成线程池项目
- 第 26 周后：更新简历和 GitHub，投 C 类公司练手
- 第 43 周后：投 B 类/A 类公司
- 第 53 周后：投 S 类公司（如准备好）

### 简历核心关键词
- C++17、多线程并发、线程池、STL 算法、atomic/lock-free
- Qt Widgets、CMake、设计模式、QThread、智能指针
- 条件变量、内存管理、ASan/TSan
- 自定义控件、SQLite、TCP/UDP
- 测试系统开发
