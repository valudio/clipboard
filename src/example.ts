import { selectedText } from './index';

setInterval(function () {
    console.log("Here is the complete output of the program: ");
    try {
        // console.log(selectedText.getSelectedText());
        selectedText.setToClipboard('Hola que tal estás');
        console.log(selectedText.getFromClipboard());
    } catch (error) {
        console.log(error);
    }
}, 2000);
