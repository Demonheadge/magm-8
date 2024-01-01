const land2EncounterType = 3;
const title = "Set Land 2 Encounter";

var metatileId = 0;
var maxMetatileId;

// `onProjectOpened` is one of those special callbacks, Porymap calls this when the project is opened.
export function onProjectOpened(projectPath) {
    // This adds a new action to the `Tools` menu
    utility.registerAction("prompt", title);
    maxMetatileId = constants.max_primary_metatiles + constants.max_secondary_metatiles - 1;
}

export function prompt() {
    // Show a prompt to ask which metatile to set your special encounter type on
    let response = utility.getInputNumber(title, "Metatile ID", metatileId, 0, maxMetatileId);
    if (!response.ok)
        return;

    // Set your special encounter type
    metatileId = response.input;
    map.setMetatileEncounterType(metatileId, land2EncounterType);
}