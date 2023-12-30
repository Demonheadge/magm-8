import re
import json

# Read the contents of the header file
with open("level_up_learnsets.h", "r") as file:
    content = file.read()

# Define a regular expression pattern to extract Pokemon names and their level-up moves
pattern = re.compile(r's(\w+)LevelUpLearnset\[\] = {(.*?)};', re.DOTALL)

# Find all matches in the content
matches = pattern.findall(content)

# Dictionary to store the Pokemon and their level-up moves
pokemon_data = {}

# Define a function to process level-up moves
def process_moves(moves_string):
    moves_pattern = re.compile(r'LEVEL_UP_MOVE\s*\(\s*(\d+)\s*,\s*MOVE_(\w+)\s*\)')
    moves_matches = moves_pattern.findall(moves_string)
    return [[int(level), move] for level, move in moves_matches]

# Iterate through matches
for match in matches:
    # Extract Pokemon name
    pokemon_name = match[0].strip()

    # Extract and process level-up moves
    level_up_moves = process_moves(match[1])

    # Add Pokemon and its level-up moves to the dictionary
    pokemon_data[pokemon_name] = level_up_moves

# Convert dictionary to JSON format
json_data = json.dumps(pokemon_data, indent=4)

# Write JSON data to a file
with open("output.json", "w") as json_file:
    json_file.write(json_data)

# Print a message indicating the successful creation of the JSON file
print("JSON data has been written to output.json.")
