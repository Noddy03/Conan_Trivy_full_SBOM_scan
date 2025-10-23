import json
import sys

def merge_sboms(sbom_paths, output_path):
    merged = None

    for path in sbom_paths:
        with open(path, "r") as f:
            sbom = json.load(f)
            if merged is None:
                merged = sbom
            else:
                merged["components"].extend(sbom.get("components", []))
                # Add merging for dependencies or metadata here if needed

    # Remove duplicate components based on (name, version)
    unique = {}
    for comp in merged.get("components", []):
        key = (comp.get("name"), comp.get("version"))
        unique[key] = comp
    merged["components"] = list(unique.values())

    with open(output_path, "w") as f:
        json.dump(merged, f, indent=2)

if __name__ == "__main__":
    if len(sys.argv) < 4:
        print("Usage: python merge_sbom.py output.json input1.json input2.json ...")
        sys.exit(1)

    out = sys.argv[1]
    inputs = sys.argv[2:]
    merge_sboms(inputs, out)
