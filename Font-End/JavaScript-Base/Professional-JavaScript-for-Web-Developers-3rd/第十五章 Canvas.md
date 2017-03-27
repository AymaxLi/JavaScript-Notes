# 第十五章 Canvas

标签（空格分隔）： 高设笔记

---

在页面设定一个区域，通过 js 动态地在这个区域中绘制图形

## 基本用法
- 为 canvas 标签设置宽高，标签内内容为备用信息
- 使用前检测 ```getContext()``` 方法是否存在
```
<canvas id="drawing" width="500" height="500">haha</canvas>
<script>
	var drawing = document.getElementById('drawing');
	if (drawing.getContext) {
		var context = drawing.getContext('2d');
		// do something
	}
</script>
```

## 2D 上下文
2D 上下文的坐标开始于 ```<canvas>``` 元素的左上角，原点坐标为 （0，0），默认情况下，```width``` 和 ```height``` 表示水平和垂直两个方向上可用的像素数目

## fillStyle 和 strokeStyle
这两个属性的值可以是字符串，渐变对象或模式对象，默认值为 ```#00000``` （表示颜色的时候可以使用其他 CSS 格式）
```
var drawing = document.getElementById('drawing');
if (drawing.getContext) {
	var context = drawing.getContext('2d');
	context.strokeStyle = 'red';
	context.fillStyle = '#0000ff';
}
```

## 绘制矩形
矩形是唯一可以直接在 2D 上下文张绘制的形状，有关方法： ```fillRect()``` 填充矩形
```strokeRect()``` 边框矩形
```clearRect()``` 空白矩形（挖空）
这三个方法接受四个参数：
- 矩形的 x 坐标
- 矩形的 y 坐标
- 矩形的宽度
- 矩形的高度
```
// 粉色矩形
context.fillStyle = 'pink';
context.fillRect(0, 20, 100, 100);
// 红色矩形
context.fillStyle = '#ff0000';
context.fillRect(0, 0, 50, 50);
// 挖空矩形
context.clearRect(0, 20, 10, 10);
```
（注：如果重叠，后声明的会在上面）

```lineWidth``` 控制线条宽度，该属性可以是任意整数
```lineCap``` 控制线条末端的形状：
1. ```butt``` 平头
2. ```round``` 圆头
3. ```square``` 方头
```lineJoin``` 控制线条相交方式：
1. ```round``` 圆交
2. ```bevel``` 斜交
3. ```miter``` 斜接

## 绘制路径
1. 要先开启路径 ```beginPath()```
2. 然后再用 ```arc()``` ```moveTo```等移动画笔画画
3. 移动完画笔记得用 ```stroke()``` 或者 ```fill()```（描边或填充），不然没效果
4. 最后关闭路径 ```closePath()```

例子： 时钟
```
var context = drawing.getContext('2d');
context.lineWidth = 2;
// 开始路径
context.beginPath();
// 画一个圆
context.arc(250, 250, 150, 0, Math.PI * 2, false);
// 移动画笔
context.moveTo(390, 250);
// 画内圆
context.arc(250, 250, 140, 0, Math.PI * 2, false);
// 画指针
context.moveTo(250, 250);
context.lineTo(250, 140);
context.moveTo(250, 250);
context.lineTo(170, 250);
// 画
context.stroke();
// 关闭路径
context.closePath();
```

## 绘制文本
```fillText()``` 和 ```strokeText()```，接受四个参数：
要绘制文本字符串、x 坐标、y 坐标、可选的最大像素宽度
