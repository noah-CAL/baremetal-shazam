import argparse
import numpy as np


def main():
    parser = argparse.ArgumentParser(description="1D Puretone Data Generator for WAVE samples.")
    parser.add_argument("--samples", help="Number of samples (default 44100)", default=44100)
    parser.add_argument("--sample-rate", help="Sample rate (default 44100)", default=44100)
    parser.add_argument("--frequency", help="Frequency of pure tone to generate (default 440 Hz)", default=440)
    args = parser.parse_args()

    pure_tone = args.frequency
    sample_freq = args.sample_rate // pure_tone
    arr = np.zeros(args.samples, dtype=np.uint8)
    for i in range(args.samples):
        if i % sample_freq == 0:
            arr[i] = 255

    with open("src/data.h", "w") as f: 
        f.write(f"/* Data generated from {__file__} */\n\n")
        f.write(f"uint32_t num_samples = {args.samples};\n")
        data = ',\n\t'.join(map(str, arr))
        f.write(f"uint8_t data[] = {{ {data} }};")

if __name__ == "__main__":
    main()
