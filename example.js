'use strict';
var addon = require('./');

// standard node module
setInterval(function () {
    console.log("Here is the complete output of the program: ");
    try {
        console.log(addon.getSelectedText());
    } catch (error) {
        console.log(error);
    }
}, 2000);