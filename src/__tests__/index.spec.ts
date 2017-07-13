import { clipboard } from '../index';

describe('Ensures that setToClipboard and getFromClipboard methods', () => {
  it('work', () => {
    const test = 'hello world';
    clipboard.setToClipboard(test);
    const from = clipboard.getFromClipboard();
    expect(from).toEqual(test);
  })
});

