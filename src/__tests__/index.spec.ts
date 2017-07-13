import { selectedText } from '../index';

describe('Ensures that setToClipboard and getFromClipboard methods', () => {
  it('work', () => {
    const test = 'hello world';
    selectedText.setToClipboard(test);
    const from = selectedText.getFromClipboard();
    expect(from).toEqual(test);
  })
});

