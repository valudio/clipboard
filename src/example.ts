// tslint:disable:no-console
import { clipboard } from './index';

setInterval(() => {
    try {
        const before = clipboard.getFromClipboard();
        console.log('Before copy:', before);
        clipboard.copy();
        setTimeout(() => {
            console.log('After copy:', clipboard.getFromClipboard());
            clipboard.setToClipboard(before);
            console.log('After setting:', clipboard.getFromClipboard());
        }, 150);
        // clipboard.getSelectedTextAsync().then(s => {
        //     console.log('After copy:', s);
        // });
    } catch (error) {
        console.log(error);
    }
}, 5000);
