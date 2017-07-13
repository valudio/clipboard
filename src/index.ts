export interface IClipboard {
  copy: () => string;
  paste: () => void;
  getFromClipboard: () => string;
  setToClipboard: (string) => void;
  getSelectedTextAsync: () => Promise<string>;
}

// tslint:disable-next-line:no-var-requires
const cb: IClipboard = require('bindings')('clipboard');

cb.getSelectedTextAsync = () => {
  return new Promise<string>(resolve => {
    const prevValue = cb.getFromClipboard();
    cb.copy();
    setTimeout(() => {
      const fromCb = cb.getFromClipboard();
      cb.setToClipboard(prevValue);
      resolve(fromCb);
    }, 150);
  });
};
export const clipboard = cb;
