export interface IClipboard {
  copy: () => string;
  paste: () => void;
  getFromClipboard: () => string;
  setToClipboard: (string) => void;
  getSelectedText: () => string;
}
export const clipboard: IClipboard = require('bindings')('selectedText');
