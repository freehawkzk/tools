# 工具类

&emsp;&emsp;本代码库收集了一些开发过程中所使用的各种工具类库。

[TOC]

## 1 EMPLog

&emsp;&emsp;这是一个基于clog库的日志输出显示工具。主要是兼容windows、linux和安卓平台，方便在开发过程中输出并显示日志。

### 1.1 接口列表

#### 1.1.1 EMPLogInfo

&emsp;&emsp;输出消息，将消息内容按照指定的格式格式化输出

```C++
inline static void EMPLogInfo(const char* format, ...)
```

#### 1.1.2 EMPLogDebug

&emsp;&emsp;输出调试信息，将调试信息内容按照指定的格式格式化输出

```C++
inline static void EMPLogDebug(const char* format, ...)
```

#### 1.1.3 EMPLogError

&emsp;&emsp;输出错误信息，将错误信息内容按照指定的格式格式化输出

```C++
inline static void EMPLogError(const char* format, ...)
```

#### 1.1.4 EMPLogFatal

&emsp;&emsp;输出致命错误，将致命错误内容按照指定的格式格式化输出，并调用exit()结束程序。

```C++
inline static void EMPLogFatal(const char* format, ...)
```

### 1.2 启用

&emsp;&emsp;通过在编译是定义宏开关`EMPWITHLOG`启用以上接口，否额接口被定义为空。
`LOCAL_CFLAGS += -DEMPWITHLOG=1`

### 1.3 信息输出时库名称定义

&emsp;&emsp;在编译时定义宏`MoudleName`，指定信息输出时的模块名称。
`LOCAL_CFLAGS += -DMoudleName="\"EMPFaceAntiProof\""`

## 2 EMPTimer

&emsp;&emsp;EMPTimer是一个高精度计时器类，用于统计程序段的运行时间。计时精度精确到毫秒。

&emsp;&emsp;该计时器类支持windows\linux\android平台。在windows平台上，内部采用`QueryPerformanceCounter`实现，在linux\android平台上，内部采用`gettimeofday`实现。

### 2.1 接口

#### 2.1.1 创建

&emsp;&emsp;计时器示例通过构造函数`CEMPTimer(const char* pname, bool show)`创建计时器，其中pname指向计时器的名称，以`\0`结尾，show表示该计时器是否能够显示输出信息，true表示可以输出，false表示不输出。

#### 2.1.2 开始计时

&emsp;&emsp;计时器对象创建成功后，内部计时器就开始计时。

#### 2.1.3 查看时间间隔

&emsp;&emsp;调用show查看当前计时器当前的计时。

#### 2.1.4 重置计时器

&emsp;&emsp;调用reset函数，当前计时器重新开始计时。

#### 2.1.5 停止计时器

&emsp;&emsp;调用stop函数，停止当前计时器的计时，并重置当前计时器。

### 2.2 输出控制

&emsp;&emsp;通过在编译时定义`EMPWITHLOG`宏，`EMPTimer`类可以将输出信息通过`EMPLog`输出。

&emsp;&emsp;定义`EMPWITHLOG`宏将引入对`EMPLog`库的依赖。
