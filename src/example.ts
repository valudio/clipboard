import { clipboard } from './index';

setInterval(function () {
    console.log("Output: ");
    try {
        console.log(clipboard.getSelectedText());
        // clipboard.setToClipboard('Hola que tal estás');
        // console.log(clipboard.getFromClipboard());
    } catch (error) {
        console.log(error);
    }
}, 2000);
