# SASS 基础

标签（空格分隔）： sass

---

## 变量
- 变量用 `$` 开头
```
$red: #ff0000;

div {
  color: $red;
}
```

- 字符串拼接用 `#{...}`
```
$side: left;

div {
  margin-#{$side}: 20px;
}
```

## 计算
注意单位
```
$a: 100px;
$b: 200;

div {
  margin-top: $a / 2;
  margin-left: #{$b/2}px;
}
```

## 嵌套
- 选择器嵌套
```
div {
  h1 {
    color: #ff0000;
  }
}
```

- 属性嵌套，注意属性后面有冒号
```
div {
  border: {
    // width: 20/2 px;
    width: thin;
    style: solid;
    color: #ff0000;
  }
}
```
- 可以用 `&` 引用父元素
```
div {
  &:hover {
    font-size: 40px;
  }
}
```

## 注释
```
/* 会保留到编译后的文件中 */
// 只保留在SASS源文件中，编译后被省略
```

## 继承
```
.a {
  color: #ff0000;
}

.b {
  @extend .a;
  font-size: 50px;
}
```

## mixin 和 include
- 使用 ```@mixin``` 命令，定义一个代码块，使用 ```@include``` 命令来调用
```
// 定义
@mixin scale {
  transition: 1s all ease;
  &:hover {
    transform: scale(1, 1.2);
  }
}

// 使用
div {
  @include scale;
}
```

- 可以传参当函数使用
```
@mixin scale($x: 1, $y: 1) {
  transition: 1s all ease;
  &:hover {
    transform: scale($x, $y);
  }
}

// 非法
.a {
  @include scale(1.2, );
}

// 非法
.b {
  @include scale(, 1.2);
}

// 合法
.c {
  @include scale(1.2);
}

// 非法
.d {
  @include scale();
}
```

## 颜色函数
```
lighten(#cc3, 10%) // #d6d65c
darken(#cc3, 10%) // #a3a329
grayscale(#cc3) // #808080
complement(#cc3) // #33c
```

## 插入文件
```
@import "path/test.scss";
@import "test.css";
```

## if 和 else
```
@mixin changeColor($a) {
  @if $a == 1 {
    color: red;
  }
  @if $a == 2 {
    color: blue;
  }
  @else {
    color: green;
  }
}

.a {
  @include changeColor(1);  // green
}

.b {
  @include changeColor(2);  // blue
}

.c {
  @include changeColor(3);  // green
}
```

## 循环
for 循环
```
    @for $i from 1 to 10 {
    .border-#{$i} {
        border: #{$i}px solid blue;
    }
}
```

while 循环
```
$i: 6;

@while $i > 0 {
    .item-#{$i} { width: 2em * $i; }
    $i: $i - 2;
}
```

each，与 for 类似
```
@each $member in a, b, c, d {
    .#{$member} {
        background-image: url("/image/#{$member}.jpg");
    }
}
```