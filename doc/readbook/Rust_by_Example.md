翻译自：[Introduction - Rust By Example (rust-lang.org)](https://doc.rust-lang.org/rust-by-example/index.html)

[Rust](https://www.rust-lang.org/) is a modern systems programming language focusing on safety, speed, and concurrency. It accomplishes these goals by being memory safe without using garbage collection.

Rust 是 一个专注于安全、速度、并发的现代编程语言。它是通过不依赖垃圾回收的内存安全完成了这些目标。

Rust by Example (RBE) is a collection of runnable examples that illustrate various Rust concepts and standard libraries. To get even more out of these examples, don't forget to [install Rust locally](https://www.rust-lang.org/tools/install) and check out the [official docs](https://doc.rust-lang.org/std/). Additionally for the curious, you can also [check out the source code for this site](https://github.com/rust-lang/rust-by-example).

Rust by Example 是一组用于阐明各种Rust概念和标准库的可运行实例。如果希望获得更多的知识，不要忘记本地安装Rust 并且 阅读官网文件。另外还想知道更多，可以下载本站的源代码。

Now let's begin!

现在我们开始

- [Hello World](https://doc.rust-lang.org/rust-by-example/hello.html) - Start with a traditional Hello World program.
- [Hello World](https://doc.rust-lang.org/rust-by-example/hello.html) - 通过一个经典的Hello World程序开始
    
- [Primitives](https://doc.rust-lang.org/rust-by-example/primitives.html) - Learn about signed integers, unsigned integers and other primitives.
- [内置类型](https://doc.rust-lang.org/rust-by-example/primitives.html) -学习 有符合的整型、无符号的整型 和其他内置类型
    
- [Custom Types](https://doc.rust-lang.org/rust-by-example/custom_types.html) - `struct` and `enum`.
- [自定义类型](https://doc.rust-lang.org/rust-by-example/custom_types.html) - `struct` 和 `enum`.
    
- [Variable Bindings](https://doc.rust-lang.org/rust-by-example/variable_bindings.html) - mutable bindings, scope, shadowing.
- [Variable Bindings](https://doc.rust-lang.org/rust-by-example/variable_bindings.html) - mutable bindings, scope, shadowing.

- [Types](https://doc.rust-lang.org/rust-by-example/types.html) - Learn about changing and defining types.
    
- [Conversion](https://doc.rust-lang.org/rust-by-example/conversion.html) - Convert between different types, such as strings, integers, and floats.
    
- [Expressions](https://doc.rust-lang.org/rust-by-example/expression.html) - Learn about Expressions & how to use them.
    
- [Flow of Control](https://doc.rust-lang.org/rust-by-example/flow_control.html) - `if`/`else`, `for`, and others.
    
- [Functions](https://doc.rust-lang.org/rust-by-example/fn.html) - Learn about Methods, Closures and Higher Order Functions.
    
- [Modules](https://doc.rust-lang.org/rust-by-example/mod.html) - Organize code using modules
    
- [Crates](https://doc.rust-lang.org/rust-by-example/crates.html) - A crate is a compilation unit in Rust. Learn to create a library.
    
- [Cargo](https://doc.rust-lang.org/rust-by-example/cargo.html) - Go through some basic features of the official Rust package management tool.
    
- [Attributes](https://doc.rust-lang.org/rust-by-example/attribute.html) - An attribute is metadata applied to some module, crate or item.
    
- [Generics](https://doc.rust-lang.org/rust-by-example/generics.html) - Learn about writing a function or data type which can work for multiple types of arguments.
    
- [Scoping rules](https://doc.rust-lang.org/rust-by-example/scope.html) - Scopes play an important part in ownership, borrowing, and lifetimes.
    
- [Traits](https://doc.rust-lang.org/rust-by-example/trait.html) - A trait is a collection of methods defined for an unknown type: `Self`
    
- [Macros](https://doc.rust-lang.org/rust-by-example/macros.html) - Macros are a way of writing code that writes other code, which is known as metaprogramming.
    
- [Error handling](https://doc.rust-lang.org/rust-by-example/error.html) - Learn Rust way of handling failures.
    
- [Std library types](https://doc.rust-lang.org/rust-by-example/std.html) - Learn about some custom types provided by `std` library.
    
- [Std misc](https://doc.rust-lang.org/rust-by-example/std_misc.html) - More custom types for file handling, threads.
    
- [Testing](https://doc.rust-lang.org/rust-by-example/testing.html) - All sorts of testing in Rust.
    
- [Unsafe Operations](https://doc.rust-lang.org/rust-by-example/unsafe.html) - Learn about entering a block of unsafe operations.
    
- [Compatibility](https://doc.rust-lang.org/rust-by-example/compatibility.html) - Handling Rust's evolution and potential compatibility issues.
    
- [Meta](https://doc.rust-lang.org/rust-by-example/meta.html) - Documentation, Benchmarking.

## 1. Hello World 

This is the source code of the traditional Hello World program.

这是经典程序Hello World 的源码

```rust
// This is a comment, and is ignored by the compiler.
// You can test this code by clicking the "Run" button over there ->
// or if you prefer to use your keyboard, you can use the "Ctrl + Enter"
// shortcut.

// This code is editable, feel free to hack it!
// You can always return to the original code by clicking the "Reset" button ->

// This is the main function.
fn main() {
    // Statements here are executed when the compiled binary is called.

    // Print text to the console.
    println!("Hello World!");
}
```

`println!` is a [_macro_](https://doc.rust-lang.org/rust-by-example/macros.html) that prints text to the console.
`println!` 是一个用于向控制台输出文本的宏

A binary can be generated using the Rust compiler: `rustc`.

可以使用Rust编译器：`rustc`生成一个二进制文件
```cmd
$ rustc hello.rs
```

`rustc` will produce a `hello` binary that can be executed.

`rustc` 将会创建一个可以执行的二进制文件 `hello` .
```cmd
$ ./hello
Hello World!
```

**Activity** 兴趣作业

Click 'Run' above to see the expected output. Next, add a new line with a second `println!` macro so that the output shows:

点击上面的`运行`可以获得预料到的输出。 然后，通过添加一行新的`println!`显示一下的输出：
```cmd
Hello World!
I'm a Rustacean!
```

### 1.1 Comments 注解

Any program requires comments, and Rust supports a few different varieties:
仍和语言都需要注释，Rust支持一些不同的变化：

- _Regular comments_ which are ignored by the compiler:
- 被编译器忽略的常见注释
    - `// Line comments which go to the end of the line.`
    - `/* Block comments which go to the closing delimiter. */`
- _Doc comments_ which are parsed into HTML library [documentation](https://doc.rust-lang.org/rust-by-example/meta/doc.html):
- 解析到HTML库文档的文档解释
    - `/// Generate library docs for the following item.`
    - `//! Generate library docs for the enclosing item.`

```rust
fn main() {
    // This is an example of a line comment.
    // There are two slashes at the beginning of the line.
    // And nothing written after these will be read by the compiler.

    // println!("Hello, world!");

    // Run it. See? Now try deleting the two slashes, and run it again.

    /*
     * This is another type of comment, a block comment. In general,
     * line comments are the recommended comment style. But block comments
     * are extremely useful for temporarily disabling chunks of code.
     * /* Block comments can be /* nested, */ */ so it takes only a few
     * keystrokes to comment out everything in this main() function.
     * /*/*/* Try it yourself! */*/*/
     */

    /*
    Note: The previous column of `*` was entirely for style. There's
    no actual need for it.
    */

    // You can manipulate expressions more easily with block comments
    // than with line comments. Try deleting the comment delimiters
    // to change the result:
    let x = 5 + /* 90 + */ 5;
    println!("Is `x` 10 or 100? x = {}", x);
}
```

### 1.2 Formatted print 格式化输出

Printing is handled by a series of [`macros`](https://doc.rust-lang.org/rust-by-example/macros.html) defined in [`std::fmt`](https://doc.rust-lang.org/std/fmt/) some of which include:
输出是有一系列定义在 [`std::fmt`](https://doc.rust-lang.org/std/fmt/) 的  [`macros`](https://doc.rust-lang.org/rust-by-example/macros.html)实现的，其中包括：
- `format!`: write formatted text to [`String`](https://doc.rust-lang.org/rust-by-example/std/str.html) 写入标准化文本到`String`
- `print!`: same as `format!` but the text is printed to the console (io::stdout). 文本打印到控制台，其他同`format!`
- `println!`: same as `print!` but a newline is appended. 另起一行，其他同`print!`
- `eprint!`: same as `print!` but the text is printed to the standard error (io::stderr). 文本输出到错误信息，其他同`print!`
- `eprintln!`: same as `eprint!` but a newline is appended. 另起一行，其他同`eprint!`

All parse text in the same fashion. As a plus, Rust checks formatting correctness at compile time.

所有的文本语法分析使用的是相同的方式。并且Rust会在编译期间检查格式的正确性。

```rust
fn main() {
    // In general, the `{}` will be automatically replaced with any
    // arguments. These will be stringified.
    println!("{} days", 31);

    // Positional arguments can be used. Specifying an integer inside `{}`
    // determines which additional argument will be replaced. Arguments start
    // at 0 immediately after the format string.
    println!("{0}, this is {1}. {1}, this is {0}", "Alice", "Bob");

    // As can named arguments.
    println!("{subject} {verb} {object}",
             object="the lazy dog",
             subject="the quick brown fox",
             verb="jumps over");

    // Different formatting can be invoked by specifying the format character
    // after a `:`.
    println!("Base 10:               {}",   69420); // 69420
    println!("Base 2 (binary):       {:b}", 69420); // 10000111100101100
    println!("Base 8 (octal):        {:o}", 69420); // 207454
    println!("Base 16 (hexadecimal): {:x}", 69420); // 10f2c

    // You can right-justify text with a specified width. This will
    // output "    1". (Four white spaces and a "1", for a total width of 5.)
    println!("{number:>5}", number=1);

    // You can pad numbers with extra zeroes,
    println!("{number:0>5}", number=1); // 00001
    // and left-adjust by flipping the sign. This will output "10000".
    println!("{number:0<5}", number=1); // 10000

    // You can use named arguments in the format specifier by appending a `$`.
    println!("{number:0>width$}", number=1, width=5);

    // Rust even checks to make sure the correct number of arguments are used.
    println!("My name is {0}, {1} {0}", "Bond");
    // FIXME ^ Add the missing argument: "James"

    // Only types that implement fmt::Display can be formatted with `{}`. User-
    // defined types do not implement fmt::Display by default.

    #[allow(dead_code)] // disable `dead_code` which warn against unused module
    struct Structure(i32);

    // This will not compile because `Structure` does not implement
    // fmt::Display.
    // println!("This struct `{}` won't print...", Structure(3));
    // TODO ^ Try uncommenting this line

    // For Rust 1.58 and above, you can directly capture the argument from a
    // surrounding variable. Just like the above, this will output
    // "    1", 4 white spaces and a "1".
    let number: f64 = 1.0;
    let width: usize = 5;
    println!("{number:>width$}");
}
```

