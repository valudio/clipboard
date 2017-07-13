# clipboard

Node addon that will allow you to use some Windows Clipboard methods.

[![Build status](https://ci.appveyor.com/api/projects/status/lqalp2kjj3e482hq?svg=true)](https://ci.appveyor.com/project/robertohuertasm/clipboard)
[![GitHub version](https://badge.fury.io/gh/valudio%2Fclipboard.svg)](https://badge.fury.io/gh/valudio%2Fclipboard)


## Usage

Install the module:

`npm i -S @valudio/clipboard`

then require it:

`var slt = require('@valudio/clipboard').selectedText;` for `js`

or

`import { selectedText as slt } from '@valudio/clipboard'` for `ts`

and use it:

`const text = slt.getSelectedText();`

## API

**copy()**: It will execute `ctrl+C`

**paste()**: It will execute `ctrl+V`

**getFromClipboard()**: It will retrieve any text stored in the clipboard.

**setToClipboard(string)**: It will store some text in the clipboard.

**getSelectedText():string**: It will get the selected text in the active window.

## Building the addon

`node-gyp configure build` if you happen to have `node-gyp` installed globally. 

If that's not the case, you can use `npm run build` or even better, if you are using `visual studio code`, just press `Ctrl+Shift+B`.