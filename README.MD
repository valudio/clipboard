# selected-text

Node addon that will allow you to copy the user's selected text in any active window. Note that this addon will only work in Windows.

[![Build status](https://ci.appveyor.com/api/projects/status/lqalp2kjj3e482hq?svg=true)](https://ci.appveyor.com/project/robertohuertasm/clipboard)


## Usage

Install the module:

`npm i -S @valudio/selected-text`

then require it:

`var slt = require('@valudio/selected-text').selectedText;` for `js`

or

`import { selectedText as slt } from '@valudio/selected-text'` for `ts`

and use it:

`const text = slt.getSelectedText();`

## Building the addon

`node-gyp configure build` if you happen to have `node-gyp` installed globally. 

If that's not the case, you can use `npm run build` or even better, if you are using `visual studio code`, just press `Ctrl+Shift+B`.