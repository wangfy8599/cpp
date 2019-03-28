# 用VS2010编译log4cxx

## 1.下载文件
- http://www.apache.org/dyn/closer.cgi/logging/log4cxx/0.10.0/apache-log4cxx-0.10.0.zip
- https://archive.apache.org/dist/apr/apr-1.2.11-win32-src.zip
- https://archive.apache.org/dist/apr/apr-util-1.2.10-win32-src.zip

## 2.准备目录
```
set PATH=%PATH%;C:\Program Files\7-Zip
7z.exe x apache-log4cxx-0.10.0.zip
7z.exe x apr-1.2.11-win32-src.zip
7z.exe x apr-util-1.2.10-win32-src.zip

rename apr-1.2.11 apr
rename apr-util-1.2.10 apr-util
```

## 3. 编辑源文件
用cmder打开目录后运行
```
configure
configure-aprutil
```
用VC6或更高版本的Visual Studio工具打开 projects/log4cxx.dsw，在打开的时候按照提示选择转换，然后
文件：src\main\include\log4cxx/spi/loggingevent.h
```
#define LOG4CXX_LIST_DEF(N, T) \
template class LOG4CXX_EXPORT std::allocator<T>; \
template class LOG4CXX_EXPORT std::vector<T>; \
typedef std::vector<T> N
```
替换为
```
#define LOG4CXX_LIST_DEF(N, T) \
typedef std::vector<T> N
```
文件：apr\network_io\unix\multicast.c（两处）
```
#if MCAST_JOIN_SOURCE_GROUP
```
替换为
```
#if defined (group_source_req)
```
文件：src\main\cpp\stringhelper.cpp加入
```
#include <iterator>
```
然后将将 apr, aprutil, xml 添加至 log4cxx 的项目引用中.
## 编译
完
