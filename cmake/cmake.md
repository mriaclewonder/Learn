# CMake

## 关键字

### NAME_WE  文件名去除扩展名

它会提取路径中最后一个路径分隔符之后的部分，并去掉最后一个 . 及其后的内容

## 函数

### get_filename_component 获取完整文件名的特定部分

```cmake
get_filename_component(<var> <FileName> <mode> [CACHE])
```

<var>：存放结果的变量名（这里是 TARGET_NAME）

<FileName>：输入的文件路径（这里是变量 ${SOURCE} 的值）

<mode>：指定提取的部分，这里是 NAME_WE
