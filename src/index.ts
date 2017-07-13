export interface IClipboard {
  copy: () => string;
  paste: () => void;
  getFromClipboard: () => string;
  setToClipboard: (string) => void;
  getSelectedTextAsync: () => Promise<string>;
}

// tslint:disable-next-line:no-var-requires
const cb: IClipboard = require('bindings')('selectedText');

cb.getSelectedTextAsync = () => {
  return new Promise<string>(resolve => {
    const prevValue = cb.getFromClipboard();
    cb.copy();
    setImmediate(() => {
      const fromCb = cb.getFromClipboard();
      cb.setToClipboard(prevValue);
      resolve(fromCb);
    });
  });
};
export const clipboard = cb;
