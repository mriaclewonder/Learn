## week5

### static_assert()

> static_assert(条件, "错误描述")编译期 查看 条件==true，不为true直接报错

### std::is_nothrow_move_constructible_v<T>

> 类型 T 能不能被移动构造，并且这个移动构造是不是 noexcept 的

### std::is_same_v<T, U>

> 用来在编译期判断 类型 T 和类型 U 是不是完全相同的类型。

### std::move_if_noexcept

> 移动可能抛异常、但拷贝可用”时，强制选择拷贝而不是移动，从而保证异常安全

### std::declval<T>

> 只用于编译期、不求值上下文的工具，用来“假装”得到一个 T 类型的值/引用，从而在 decltype、sizeof、noexcept、类型特征里推导表达式类型
