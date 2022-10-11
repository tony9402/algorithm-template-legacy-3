from glob import glob
import json


def replace_escape_sequence(text):
    escape = [
        ("\"", "\\\""),
        ("\'", "\\\'"),
    ]
    for a, b in escape:
        text = text.replace(a, b)
    return text


# title -> Must Unique
def assemble(title: str, prefix: list, code: list, description: str):
    if type(prefix) == str: prefix = [prefix]
    if type(code) == str: code = [code]

    assert type(title) == str
    assert type(prefix) == list
    assert type(code) == list
    assert type(description) == str
    
    code = [
        f"{replace_escape_sequence(x.rstrip())}"
        for x in code
    ]
    value = {
        "prefix": prefix,
        "body": code,
        "description": description
    }
    return (title, value)


def information_parse(lines: list):
    info = dict()
    for line in lines:
        line = line.strip()[2:]
        key, value = line.split(':')
        info[key] = value.strip()
    return info


def make_snippet(file):
    with open(file, 'r') as f:
        data = f.readlines()
        info = information_parse(lines = data[:3])
        code = data[3:]
        f.close()
    return assemble(**info, code=code)


def run():
    cpp_files = glob("src/**/*.cpp", recursive=True)
    snippet = dict()
    for file in cpp_files:
        key, value = make_snippet(file)
        snippet[key] = value
    with open('cpp.json', 'w') as f:
        json.dump(snippet, f, ensure_ascii=False, indent=4)
        f.close()


if __name__ == "__main__":
    run()
