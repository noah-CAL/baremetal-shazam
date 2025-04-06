import argparse
import numpy as np


def write_data(file, declaration, data, audio=False, header=False, is_np_array=False):
    if header:
        file.write(f"/* Data generated from {__file__} */\n\n")
    if is_np_array:
        data = ',\n\t'.join(map(str, data))
    if audio:
        file.write(f"{declaration} = {{ {data} }};\n")
    else:
        file.write(f"{declaration} = {data};\n")

def main():
    parser = argparse.ArgumentParser(description="1D Puretone Data Generator for WAVE samples.")
    parser.add_argument("--samples", help="Number of samples (default 44100)", type=int, default=44100)
    parser.add_argument("--sample-rate", help="Sample rate (default 44100)", type=int, default=44100)
    parser.add_argument("--frequency", help="Frequency of pure tone to generate (default 440 Hz)", type=int, default=440)
    args = parser.parse_args()

    pure_tone = args.frequency
    sample_freq = args.sample_rate // pure_tone
    arr = np.zeros(args.samples, dtype=np.uint8)
    for i in range(args.samples):
        if i % sample_freq == 0:
            arr[i] = 255

    with open("src/data.h", "w") as f:
        write_data(f, "uint32_t num_samples", args.samples, header=True)
        write_data(f, "uint8_t data[]", arr, audio=True, is_np_array=True)

if __name__ == "__main__":
    main()
