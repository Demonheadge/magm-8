import re
import json

def parse_tmhm_learnsets(header_content):
    learnsets = {}
    pattern = r'^\s*\[([^]]+)\]\s+=\s+TMHM_LEARNSET\((.*?)\),'
    tmhm_pattern = r'TMHM\(([^)]+)\)'

    matches = re.finditer(pattern, header_content, re.MULTILINE | re.DOTALL)
    
    for match in matches:
        species = match.group(1)
        tmhm_data = match.group(2)

        tmhm_matches = re.findall(tmhm_pattern, tmhm_data)
        tmhm_list = [tm.split('_', 1) for tm in tmhm_matches]
        
        learnsets[species] = tmhm_list
    
    return learnsets

def write_to_json(data, output_file):
    with open(output_file, 'w') as json_file:
        json.dump(data, json_file, indent=4)

def main():
    with open('tmhm_learnsets.h', 'r') as file:
        header_content = file.read()

    learnsets = parse_tmhm_learnsets(header_content)

    # Write results to a JSON file
    output_file = 'tmhm_learnsets.json'
    write_to_json(learnsets, output_file)
    print(f"Results written to {output_file}.")

if __name__ == "__main__":
    main()
