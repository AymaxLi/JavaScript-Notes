# ES6 笔记

标签（空格分隔）： ES6

---

[toc]

---

## let
- `let` 声明的变量只在代码块里面有效，如 `for 循环`
- 不会变量提升，只能在声明后使用（暂时性死区，`typeof` 操作也会报 `referenceError`）
- `let` 不允许在相同作用域内，重复声明同一个变量

## 块级作用域
- 块级作用域内声明的函数类似于 ```let```，对作用域之外没有影响

## const
- 声明一个只读常量，一旦声明，值无法改变
- 只声明不赋值，就会报错
- 和 `let` 一样，不会提升，存在暂时性死区和不可重复声明
- 对于复合型数据，`const` 只是保证变量名指向的地址不变，并不保证该地址的数据不变
``` javascript
const a = [];
a.push('Hello'); // 可执行
a.length = 0;    // 可执行
a = ['Dave'];    // 报错
```

## 全局对象的属性
- `var` 命令和 `function` 命令声明的全局变量，依旧是全局对象的属性
- `let `，`const`，`class` 命令声明的全局变量，不属于全局对象的属性
``` javascript
var s = 1
let y = 2
console.log(window.s); // 1
console.log(window.y); // undefined
```


## 结构赋值
- 只要某种数据结构具有 `Iterator` 接口，都可以采用数组形式的解构赋值
