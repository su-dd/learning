# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("设计模式")


# 简单工厂
add_subdirectory("SimpleFactory")

# 工厂
add_subdirectory("FactoryMethod")

# 抽象工厂
add_subdirectory("AbstractFactory")

# 单例
add_subdirectory("Singleton")

# 模板方法
add_subdirectory("Template")

#享元模式
add_subdirectory("Flyweight")

# 原型模式
add_subdirectory("Prototype")

# 策略模式
add_subdirectory ("Strategy")

# 装饰器模式
add_subdirectory ("Decorator")

# 代理模式
add_subdirectory ("Proxy")

# 桥模式
add_subdirectory ("Bridge")

# 面板模式
add_subdirectory("Facade")

# 适配器
add_subdirectory("Adapter")

# 迭代器
add_subdirectory("Iterator")

# 备忘录
add_subdirectory("Memento")

# 命令模式
add_subdirectory("Command")

# 组合模式
add_subdirectory("Component")

# 职责链模式
add_subdirectory("ChainOfResponsibility")

# 访问者模式
add_subdirectory("Visitor")

# 解释器模式
add_subdirectory(Interpreter)

# 中介者模式
add_subdirectory(Mediator)

# 观察者模式
add_subdirectory(Observer)

# 状态模式
add_subdirectory(State)

# 建造者
add_subdirectory(Builder)