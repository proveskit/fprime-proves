#!/usr/bin/env python3
import re
import argparse
from pathlib import Path

def extract_sections(xml_file_path, output_directory_path):
    """Extract all sections from an XML file and save them to the output directory."""
    with open(xml_file_path, 'r', encoding='utf-8') as file:
        xml_content = file.read()

    section_pattern = r'<!--\s*@FPL\s+START\s+(\w+)\s+-->(.*?)<!--\s*@FPL\s+END\s+-->'
    sections = re.findall(section_pattern, xml_content, re.DOTALL)

    for section_name, section_content in sections:
        section_file_name = f"{section_name.strip()}.xml"
        output_file_path = output_directory_path / section_file_name

        with open(output_file_path, 'w', encoding='utf-8') as section_file:
            section_file.write(f"<fpl>\n  {section_content.strip()}\n</fpl>\n")

def main():
    parser = argparse.ArgumentParser(description="Extract sections from XML files.")
    parser.add_argument("files", nargs="+", type=str, help="List of input XML files.")
    parser.add_argument("-d", "--output-directory", type=str, default=".", help="Path to the output directory for saving sections.")
    args = parser.parse_args()

    output_directory_path = Path(args.output_directory).resolve()

    if not output_directory_path.exists():
        output_directory_path.mkdir(parents=True)

    for xml_file_path in args.files:
        extract_sections(xml_file_path, output_directory_path)

if __name__ == "__main__":
    main()
