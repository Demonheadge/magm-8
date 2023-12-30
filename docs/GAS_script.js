const sheet = SpreadsheetApp.getActiveSpreadsheet(); // Retrieve active sheet. Change if you want to access another sheet or another spreadsheet
function JSON_to_Spreadsheet(pokedexID, learnsetsID, formatsDataID) {
  const pokedexJSON = DriveApp.getFileById(pokedexID).getBlob().getDataAsString(); // Get JSON text from Drive file
  const pokedex = JSON.parse(pokedexJSON); // JSON text to JS object
  const learnsetsJSON = DriveApp.getFileById(learnsetsID).getBlob().getDataAsString(); // Get JSON text from Drive file
  const learnsets = JSON.parse(learnsetsJSON); // JSON text to JS object
  const formatsDataJSON = DriveApp.getFileById(formatsDataID).getBlob().getDataAsString(); // Get JSON text from Drive file
  const formatsData = JSON.parse(formatsDataJSON); // JSON text to JS object
  var mons = [];
  for (const mon in pokedex) {
      mons.push(mon);
  }
  mons.forEach(function(mon) {
    console.log(mon);
    var yourNewSheet = sheet.getSheetByName(pokedex[mon].name);
    if (yourNewSheet != null) {
        sheet.deleteSheet(yourNewSheet);
    }
    newSheet = sheet.insertSheet(pokedex[mon].name);
    if (learnsets[mon]) newSheet.deleteRows(Object.keys(learnsets[mon]['learnset']).length + 3,1000 - Object.keys(learnsets[mon]['learnset']).length - 3);
    else newSheet.deleteRows(3, 997)
    newSheet.deleteColumns(10,16);
    newSheet.getRange(1,1,1,1).setValue('Type 1');
    newSheet.getRange(2,1,1,1).setValue(pokedex[mon].types[0]);
    newSheet.getRange(1,2,1,1).setValue('Type 2');
    if (pokedex[mon].types[1]) newSheet.getRange(2,2,1,1).setValue(pokedex[mon].types[1]);
    newSheet.getRange(1,3,1,1).setValue('Ability 1');
    newSheet.getRange(2,3,1,1).setValue(pokedex[mon].abilities[0]);
    newSheet.getRange(1,4,1,1).setValue('Ability 2');
    if (pokedex[mon].abilities[1]) newSheet.getRange(2,4,1,1).setValue(pokedex[mon].abilities[1]);
    newSheet.getRange(1,5,1,1).setValue('HP');
    newSheet.getRange(2,5,1,1).setValue(pokedex[mon].baseStats['hp']);
    newSheet.getRange(1,6,1,1).setValue('Atk');
    newSheet.getRange(2,6,1,1).setValue(pokedex[mon].baseStats['atk']);
    newSheet.getRange(1,7,1,1).setValue('Def');
    newSheet.getRange(2,7,1,1).setValue(pokedex[mon].baseStats['def']);
    newSheet.getRange(1,8,1,1).setValue('SpA');
    newSheet.getRange(2,8,1,1).setValue(pokedex[mon].baseStats['spa']);
    newSheet.getRange(1,9,1,1).setValue('SpD');
    newSheet.getRange(2,9,1,1).setValue(pokedex[mon].baseStats['spd']);
    newSheet.getRange(1,10,1,1).setValue('Spe');
    newSheet.getRange(2,10,1,1).setValue(pokedex[mon].baseStats['spe']);
    newSheet.getRange(3,1,1,1).setValue('Viable Moves');
    const sortedLearnsets = Object.keys(learnsets[mon]['learnset']).sort();
    for (const move of sortedLearnsets)
    {
      const moveIndex = sortedLearnsets.indexOf(move);
      console.log(move, moveIndex);
      newSheet.getRange(4 + moveIndex,1,1,1).setValue(move);
    }
  })
}
const pokedexID = "14McItshgZ-Js344uzqyKMA2T9kHHwlPA"; // Change to your FILE_ID
const learnsetsID = "1RNStVnCe9UZ8J98qkYahjKbsgzLLtOuv"; // Change to your FILE_ID
const formatsDataID = "1nLgZDvm04rR-gBnZvHL6VJ_mYz9Uziwv"; // Change to your FILE_ID
// JSON_to_Spreadsheet(pokedexID, learnsetsID, formatsDataID);
function sortSheets () {
  var sheetNameArray = [];
  var sheets = sheet.getSheets(); 

  if (sheets.length <= 0){
    return;
  }

  for (var i = 1; i < sheets.length; i++) {
    sheetNameArray.push(sheets[i].getName());
  }

  sheetNameArray.sort(); 

  for( var j = 0; j < sheetNameArray.length; j++ ) {
    sheet.setActiveSheet(sheet.getSheetByName(sheetNameArray[j]));
    sheet.moveActiveSheet(j + 2);
  }
}