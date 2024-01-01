const land2EncounterType = 3;
const title = "Set Metatile Land Encounter";
const title2 = "Set Metatile";
const title3 = "Set Land Encounter";
const label = 'Determines from which table the wild Pokemon will come from.';
const landEncounterIndexes = [3, 4, 5, 6, 7, 8, 9];

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
    let response = utility.getInputNumber(title2, "Metatile ID", metatileId, 0, maxMetatileId);
    if (!response.ok)
        return;

    // Set your special encounter type
    metatileId = response.input;
    let response2 = utility.getInputItem(title3, label, landEncounterIndexes, 0, false);
    if (!response2.ok)
        return;

    const landEncounterIndex = parseInt(response2.input);
    map.setMetatileEncounterType(metatileId, landEncounterIndex);
}