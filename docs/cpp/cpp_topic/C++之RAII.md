**RAII**，全称为 Resource Acquisition Is Initialization，直译为**资源获取即初始化**。

这是C++的一个编程技术或者说是一种编程哲学。

**其核心思想是将对象的生命周期（对象的创建和销毁）与资源的生命周期（资源的获取和释放）绑定在一起。**



在C++中，RAII主要通过对象构造函数和析构函数来实现。当创建一个对象时，我们可以在构造函数中获取资源，比如**动态分配内存**、打开文件、**获取锁**等。

当对象不再需要时，我们可以通过析构函数来释放这些资源。

这种方式的**优点**是，它可以自动管理资源的生命周期，防止资源泄露。

因为C++有确定的析构函数调用时间（当对象离开其作用域时），所以我们可以确保在适当的时间释放资源。

这也可以防止因为异常或早期返回而导致的资源泄露。

**例：**

```cpp
class File {  
public:  
    File(const std::string& filename) {  
        // 打开文件  
        file_ = fopen(filename.c_str(), "r");  
        if (!file_) {  
            throw std::runtime_error("Failed to open file");  
        }  
    }  
      
    ~File() {  
        // 关闭文件  
        fclose(file_);  
    }  
      
private:  
    FILE* file_;  
};
```

## ScopeExit

当退出作用域时，做一些相应的操作；如，资源管理

**实现方案1：**

```cpp
class ScopeExit {
   public:
    ScopeExit() = default;

    ScopeExit(const ScopeExit&) = delete;
    void operator=(const ScopeExit&) = delete;

    ScopeExit(ScopeExit&&) = default;
    ScopeExit& operator=(ScopeExit&&) = default;

    template <typename F, typename... Args>
    ScopeExit(F&& f, Args&&... args) {
        func_ = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
    }

    ~ScopeExit() {
        if (func_) {
            func_();
        }
    };

   private:
    std::function<void()> func_;
};

#define _CONCAT(a, b) a##b
#define _MAKE_SCOPE_(line) ScopeExit _CONCAT(defer, line) = [&]()

#undef SCOPE_GUARD
#define SCOPE_GUARD _MAKE_SCOPE_(__LINE__)
```

**实现方案2：**

```cpp
template <class ReleaseFun>
class ScopeGuard
{
public:
    ScopeGuard(ReleaseFun fun)
        : m_releaseFun(fun)
    {}
    ~ScopeGuard()
    {
        m_releaseFun();
    }

private:
    ReleaseFun m_releaseFun;
};

class ScopeGuardOnExit{};
template <typename ReleaseFun>
ScopeGuard<ReleaseFun> operator+(ScopeGuardOnExit, ReleaseFun &&fn)
{
    return ScopeGuard<ReleaseFun>(fn);
}

#define _JOINT(s1, s2) s1##s2
#define JOINT(s1, s2) _JOINT(s1, s2)
#define VARIABLE(str) JOINT(str, __LINE__)

#define SCOPE_GUARD \
    auto VARIABLE(SCOPE_EXIT_STATE) = ScopeGuardOnExit() + [&]()
```


**使用如下：**

```cpp
void test()
{
	int *pInt = new int(9);
	SCOPE_GUARD
	{
		delete pInt;
	};
	int a = *pInt + 1; 
}
```

