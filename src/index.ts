export interface ISelectedText {
  copy: () => string;
  paste: () => void;
  getFromClipboard: () => string;
  setToClipboard: (string) => void;
  getSelectedText: () => string;
}
export const selectedText: ISelectedText = require('bindings')('selectedText');
