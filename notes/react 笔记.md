# react 笔记

标签（空格分隔）： react

---

## ReactDOM.render()
将模板转换为 HTML，并插入指定 DOM 节点

## JSX
遇到 HTML 标签（以 < 开头），就用 HTML 规则解析；遇到代码块（以 { 开头），就用 JavaScript 规则解析
例子：
```
var names = ['Alice', 'Emily', 'Kate'];

ReactDOM.render(
  <div>
  {
    names.map(function (name) {
      return <div>Hello, {name}!</div>
    })
  }
  </div>,
  document.getElementById('example')
);
```
JSX 允许直接在模板插入 JavaScript 变量。如果这个变量是一个数组，则会展开这个数组的所有成员
```
var arr = [
  <h1>Hello world!</h1>,
  <h2>React is awesome</h2>,
];
ReactDOM.render(
  <div>{arr}</div>,
  document.getElementById('example')
);
```

## 组件
React 允许将代码封装成组件（component），然后像插入普通 HTML 标签一样，在网页中插入这个组件。React.createClass 方法就用于生成一个组件类。
>- 所有组件类都必须有自己的 render 方法，用于输出组件
- 组件类的第一个字母必须大写，否则会报错
- 组件类只能包含一个顶层标签，否则也会报错
- 组件的属性可以在组件类的 ```this.props``` 对象上获取，比如 ```name``` 属性就可以通过 ```this.props.name```

例子：
```
var HelloMessage = React.createClass({
  render: function() {
    return <h1>Hello {this.props.name}</h1>;
  }
});

ReactDOM.render(
  <HelloMessage name="John" />,
  document.getElementById('example')
);
```

## this.props.children
```this.props``` 对象的属性与组件的属性一一对应，但是有一个例外，就是 ```this.props.children``` 属性，它表示组件的所有子节点，其取值有以下三种可能：
|子节点个数||
|:-:|:-:|
|当前组件没有子节点| ```undefined``` |
|有一个子节点| ```object``` |
|有多个子节点| ```array``` |

React 提供一个工具方法 ```React.Children``` 来处理 ```this.props.children``` 。我们可以用 ```React.Children.map``` 来遍历子节点，而不用担心 ```this.props.children``` 的数据类型是 ```undefined``` 还是 object


## PropTypes
组件类的 ```PropTypes``` 属性，可以用来验证组件实例的属性是否符合要求
```
var MyTitle = React.createClass({
  propTypes: {
    title: React.PropTypes.string.isRequired, // title 属性必须的，而且它的值必须是字符串
  },

  render: function() {
     return <h1> {this.props.title} </h1>;
   }
});
```

可以用 ```getDefaultProps()``` 来设置组件属性的默认值

## ref
给节点设置 ```ref``` 属性，可以通过 ```this.refs.[refName]``` 获得真实的节点
```
var MyComponent = React.createClass({
  handleClick: function() {
    this.refs.myTextInput.focus();
  },
  render: function() {
    return (
      <div>
        <input type="text" ref="myTextInput" />
        <input type="button" value="Focus the text input" onClick={this.handleClick} />
      </div>
    );
  }
});

ReactDOM.render(
  <MyComponent />,
  document.getElementById('example')
);
```

## this.state
例子：
```
var LikeButton = React.createClass({
  getInitialState: function() {
    return {liked: false};
  },
  handleClick: function(event) {
    this.setState({liked: !this.state.liked});
  },
  render: function() {
    var text = this.state.liked ? 'like' : 'haven\'t liked';
    return (
      <p onClick={this.handleClick}>
        You {text} this. Click to toggle.
      </p>
    );
  }
});

ReactDOM.render(
  <LikeButton />,
  document.getElementById('example')
);
```

```getInitialState()``` 定义初始状态
```this.state``` 读取状态属性
```this.setState()``` 修改状态， 每次修改后，自动调用 ```this.render``` 方法
> 由于 ```this.props``` 和 ```this.state``` 都用于描述组件的特性，可能会产生混淆。一个简单的区分方法是，this.props 表示那些一旦定义，就**不再改变**的特性，而 ```this.state``` 是会**随着用户互动而产生变化**的特性

## 表单
例子：
```
var Input = React.createClass({
  getInitialState: function() {
    return {value: 'Hello!'};
  },
  handleChange: function(event) {
    this.setState({value: event.target.value});
  },
  render: function () {
    var value = this.state.value;
    return (
      <div>
        <input type="text" value={value} onChange={this.handleChange} />
        <p>{value}</p>
      </div>
    );
  }
});

ReactDOM.render(<Input/>, document.body);
```

上面代码中，文本输入框的值，不能用 ```this.props.value``` 读取，而要定义一个 ```onChange``` 事件的回调函数，通过 ```event.target.value``` 读取用户输入的值。```textarea``` 元素、```select``` 元素、```radio``` 元素都属于这种情况

## 组件的生命周期
组件的生命周期分成三个状态
> - Mounting：已插入真实 DOM
- Updating：正在被重新渲染
- Unmounting：已移出真实 DOM

每个状态有两种处理函数， ```will``` 函数在进入状态之前调用，```did``` 函数在进入状态之后调用
>- componentWillMount()
- componentDidMount()
- componentWillUpdate(object nextProps, object nextState)
- componentDidUpdate(object prevProps, object prevState)
- componentWillUnmount()

两种特殊的处理函数
>- componentWillReceiveProps(object nextProps)：已加载组件收到新的参数时调用
- shouldComponentUpdate(object nextProps, object nextState)：组件判断是否重新渲染时调用

## Ajax
组件的数据来源，通常是通过 Ajax 请求从服务器获取，可以使用 ```componentDidMount``` 方法设置 Ajax 请求，等到请求成功，再用 ```this.setState``` 方法重新渲染 UI 