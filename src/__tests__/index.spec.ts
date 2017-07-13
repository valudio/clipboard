import { clipboard } from '../index';

describe('Basic tests', () => {
  it('Ensures that setToClipboard and getFromClipboard methods work', () => {
    const test = 'hello world';
    clipboard.setToClipboard(test);
    const from = clipboard.getFromClipboard();
    expect(from).toEqual(test);
  });

  describe('Ensures that getSelectedTextAsync', () => {
    it('works', () => {
      const test = 'hello world';
      clipboard.setToClipboard(test);
      return clipboard.getSelectedTextAsync().then(s => {
        expect(s).toEqual(test);
      });
    });

    it('keeps the value of the previous text stored in the clipboard', () => {
      const test = 'hello world';
      const prev = 'previous value';
      clipboard.setToClipboard(prev);
      const spy = jest.spyOn(clipboard, 'copy');
      spy.mockImplementation(() => clipboard.setToClipboard(test));
      return clipboard.getSelectedTextAsync().then(s => {
        const inclipValue = clipboard.getFromClipboard();
        expect(s).toEqual(test);
        expect(inclipValue).toEqual(prev);
        spy.mockReset();
        spy.mockRestore();
      });
    });

    it('calls copy', () => {
      const spy = jest.spyOn(clipboard, 'copy');
      return clipboard.getSelectedTextAsync().then(() => {
        expect(spy).toHaveBeenCalled();
        spy.mockReset();
        spy.mockRestore();
      });
    });

    it('calls setClipboard', () => {
      const spy = jest.spyOn(clipboard, 'setToClipboard');
      return clipboard.getSelectedTextAsync().then(() => {
        expect(spy).toHaveBeenCalled();
        spy.mockReset();
        spy.mockRestore();
      });
    });
  });
});
